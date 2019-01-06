//
//  R_Echecs.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 05/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Regles_Echecs.hpp"

Regles_Echecs::Regles_Echecs()
{
    
}

int Regles_Echecs::checkMove(Plateau& plateau, int x1, int y1, int x2, int y2, Joueur j_tour)
{
    
    //Sortie du plateau
    checkOutOfBounds(plateau, x1, y1);
    checkOutOfBounds(plateau, x2, y2);
    
    
    //Mouvement sur la meme case
    checkDidntMove(x1, y1, x2, y2);
    
    //Case de depart vide
    checkStartingBoxEmpty(plateau, x1, y1);
    
    //Piece n'appartient pas au joueur courant
    checkOwner(plateau, j_tour, x1, y1);
    
    int type = plateau.getCase(x1, y1).getPiece().getType();
    
    if (type == 5)//Si c'est un roi
    {
        checkMove1Box(x1, y1, x2, y2);//il ne peut bouger que d'une case
    }
    else if (type == 4)//Si c'est une reine
    {
        checkDiagoOrthogonal(x1, y1, x2, y2);
    }
    else if (type == 3)//Si c'est une tour
    {
        checkOrthogonal(x1, y1, x2, y2);
    }
    
    else if (type == 2)//Si c'est un fou
    {
        checkDiagonal(x1, y1, x2, y2);
    }
    else if (type == 1)//Si c'est un cavalier
    {
        checkNonOrthogonal(x1, y1, x2, y2);//alors si il ne se dáplace pas orthogonalement
        checkNonDiagonal(x1, y1, x2, y2);//pas diagonalement
        checkDistanceFromStartLessThanN(2, x1, y1, x2, y2);//et pas a une distance de plus de 2 cases
        //c'est bon !
    }
    else if (type == 0)//Si c'est un pion (EN COURS)
    {
        
        checkPawnMovement(plateau, j_tour, x1, y1, x2, y2);

    }
    if(type != 1) //Si c'est autre chose qu'un cavalier
    {
        //On regarde si le chemin est libre
        checkPath(plateau, j_tour, x1, y1, x2, y2);
    }
    
    
    return 0;
}

void Regles_Echecs::move(Plateau& plateau, int x1, int y1, int x2, int y2)
{
    
    if(plateau.getCase(x2, y2).isEmpty())
    {
        plateau.move(x1, y1, x2, y2);
    }
    else
    {
        Piece p = plateau.getCase(x2, y2).getPiece();
        
	plateau.discard(p);
	plateau.move(x1, y1, x2, y2);
	//recordMove(plateau, p1, x2, y2);
    }

}

int Regles_Echecs::etatPartie(Plateau &p)
{
    //TODO
    return 0;
}


bool Regles_Echecs::placePiece(Plateau &plateau, Piece &piece, int x, int y)
{
    if(not plateau.contains(x, y)){
        
        return false;
    }
    
    
    if(piece.getJoueur().getId() == 0)
    {
        if(y>=2){
            //cout << "la" << endl;
            return false;
        }
    }
    
    if(piece.getJoueur().getId() == 1)
    {
        if(y<plateau.getHauteur()-2){
            
            return false;
        }
    }
    
    
    if( not (plateau.getCase(x, y).isEmpty()) )
    {
        
        return false;
    }
    
    plateau.dispatch(piece, x, y);
    
    
    return true;
}

void Regles_Echecs::checkPawnMovement(Plateau& plateau, Joueur j_tour, int x1, int y1, int x2, int y2)
{
    Case &c = plateau.getCase(x1, y1);
    
    //
    
    if(j_tour.getId()==0)//Pour le joueur 1
    {
        if (x1==x2 and y2 == y1+1)//Si on essaye d'avancer d'une case tout droit
        {
        
            c = plateau.getCase(x1, y1+1);
            if(not(c.isEmpty()))//Si la case est occupée, peut importe par quelle piece, il ne peut avancer(pion ne peut manger en avançant).
	    {
		throw Move_Exception("Case occupée, vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
	    }
        }
        else if(x2 == x1 and y2 == y1+2)//Si on essaye d'avancer de 2 cases tout droit
        {
            c = plateau.getCase(x1, y1+2);
            if(not(c.isEmpty()))//Si la case est occupée, peut importe par quelle piece, il ne peut avancer(pion ne peut manger en avançant).
            {
                throw Move_Exception("Case occupée, vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
            }
            if(y1 != 1)//Si le pion n'est pas en position de départ, impossible.
            {
                throw Move_Exception("Ce pion ne peut plus avancer de 2 cases !", "Erreur de déplacement");
            }
            
        }

        else if(x2 == x1-1 and y2 == y1+1)//Si on essaye d'accéder à la case adjacente en diagonale gauche
        {
            c = plateau.getCase(x1-1, y1+1);
            if(c.isEmpty() or c.getPiece().getJoueur().getId()==j_tour.getId())//si la case est vide ou avec une piece a nous: impossible.
            {
                throw Move_Exception("Vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
            }
        }
        else if(x2 == x1+1 and y2 == y1+1)//Si on essaye d'accéder à la case adjacente en diagonale droite
        {
            c = plateau.getCase(x1+1, y1+1);
            if(c.isEmpty() or c.getPiece().getJoueur().getId()==j_tour.getId())//si la case est vide ou avec une piece a nous: impossible.
            {
                throw Move_Exception("Vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
            }
        }
        else
        {
            throw Move_Exception("Déplacement impossible pour un pion", "Erreur de déplacement");
        }
        
    }
    
    
    if(j_tour.getId()==1)//Pour le joueur 2
    {
        if (x1==x2 and y2 == y1-1 )//Si on essaye d'avancer d'une case tout droit
        {
            
            c = plateau.getCase(x1, y1-1);
            if(not(c.isEmpty()))//Si la case est occupée, peut importe par quelle piece, il ne peut avancer(pion ne peut manger en avançant).
            {
                throw Move_Exception("Case occupée, vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
            }
        }
        else if(x2 == x1 and y2 == y1-2)//Si on essaye d'avancer de 2 cases tout droit
        {
            c = plateau.getCase(x1, y1-2);
            if(not(c.isEmpty()))//Si la case est occupée, peut importe par quelle piece, il ne peut avancer(pion ne peut manger en avançant).
            {
                throw Move_Exception("Case occupée, vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
            }
            if(y1 != plateau.getHauteur()-2)//Si le pion n'est pas en position de départ, impossible.
            {
                throw Move_Exception("Ce pion ne peut plus avancer de 2 cases !", "Erreur de déplacement");
            }
            
        }
        
        else if(x2 == x1-1 and y2 == y1-1)//Si on essaye d'accéder à la case adjacente en diagonale gauche
        {
            c = plateau.getCase(x1-1, y1-1);
            if(c.isEmpty() or c.getPiece().getJoueur().getId()==j_tour.getId())//si la case est vide ou avec une piece a nous: impossible.
            {
                throw Move_Exception("Vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
            }
        }
        else if(x2 == x1+1 and y2 == y1-1)//Si on essaye d'accéder à la case adjacente en diagonale droite
        {
            c = plateau.getCase(x1+1, y1+1);
            if(c.isEmpty() or c.getPiece().getJoueur().getId()==j_tour.getId())//si la case est vide ou avec une piece a nous: impossible.
            {
                throw Move_Exception("Vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
            }
        }

    }
    
}
