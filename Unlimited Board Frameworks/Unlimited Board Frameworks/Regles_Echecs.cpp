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
    
    int type = plateau.getCase(x1, y1).getPiece()->getType();
    
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
        checkOrthogonal(x1, y1, x2, y2);
        //checkMove1Box(x1, y1, x2, y2);
        
        if(j_tour.getId()==0)
        {
            if(y1 == 1)//on regarde si le pion est a sa position de départ (dans ce cas il peut avancer de 2 cases)
            {
                checkDistanceFromStartLessThanN(2, x1, y1, x2, y2);
            }
            else{
                checkMove1Box(x1, y1, x2, y2);
            }
            checkUpward(x1, y1, x2, y2);
        }
        if(j_tour.getId()==1)
        {
            if(y1 == 6)//on regarde si le pion est a sa position de départ (dans ce cas il peut avancer de 2 cases)
            {
                checkDistanceFromStartLessThanN(2, x1, y1, x2, y2);
            }
            else{
                checkMove1Box(x1, y1, x2, y2);
            }

            checkDownward(x1, y1, x2, y2);
        }
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
    Piece *p1 = plateau.getCase(x1, y1).getPiece();
    int t1;
    int t2;
    
    if(plateau.getCase(x2, y2).isEmpty())
    {
        plateau.move(x1, y1, x2, y2);
    }
    else
    {
        Piece *p2 = plateau.getCase(x2, y2).getPiece();
        
            plateau.discard(p2);
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
        if(y<6){
            
            return false;
        }
    }
    
    
    if( not (plateau.getCase(x, y).isEmpty()) )
    {
        
        return false;
    }
    
    plateau.dispatch(&piece, x, y);
    
    
    return true;
}
