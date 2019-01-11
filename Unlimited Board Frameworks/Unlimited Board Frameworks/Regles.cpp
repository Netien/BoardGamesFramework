//
//  Regles.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 25/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Regles.hpp"

void Regles::checkOutOfBounds(Plateau& plateau, int x, int y)
{
    if( not (plateau.contains(x, y)))
    {
        throw Move_Exception("Sortie du plateau!", "Erreur de déplacement ");
    }
}

void Regles::checkOrthogonal(int x1, int y1, int x2, int y2)
{
    if(x1 != x2 && y1 != y2)
    {
        throw Move_Exception("Déplacement non orthogonal!", "Erreur de déplacement");
    }
}

void Regles::checkNonOrthogonal(int x1, int y1, int x2, int y2)
{
    if(not(x1 != x2 && y1 != y2))
    {
        throw Move_Exception("Déplacement orthogonal!", "Erreur de déplacement");
    }
}



void Regles::checkDiagonal(int x1, int y1, int x2, int y2)
{
    if(not (abs(x2-x1) == abs(y2-y1)))
    {
        throw Move_Exception("Déplacement non diagonal!", "Erreur de déplacement");
    }
}

void Regles::checkNonDiagonal(int x1, int y1, int x2, int y2)
{
    if((abs(x2-x1) == abs(y2-y1)))
    {
        throw Move_Exception("Déplacement diagonal!", "Erreur de déplacement");
    }
}

bool Regles::isDiagoOrthogonal(int x1, int y1, int x2, int y2)//Déplacement orthogonal ou diagonal
{
    if((x1 != x2 && y1 != y2) && (not (abs(x2-x1) == abs(y2-y1))))
    {
        return false;
    }
    return true;
}

void Regles::checkDiagoOrthogonal(int x1, int y1, int x2, int y2)//Déplacement orthogonal ou diagonal
{
    if((x1 != x2 && y1 != y2) && (not (abs(x2-x1) == abs(y2-y1))))
    {
        throw Move_Exception("Déplacement ni orthogonal ni diagonal!", "Erreur de déplacement");
    }
}


void Regles::checkDidntMove(int x1, int y1, int x2, int y2)
{
    if(x1 == x2 && y1 == y2)
    {
        throw Move_Exception("La piece n'a pas bougé!", "Erreur de déplacement");
    }
}

void Regles::checkStartingBoxEmpty(Plateau& plateau, int x, int y)
{
    Case c = plateau.getCase(x, y);
    if(c.isEmpty())
        throw Move_Exception("La case de départ est vide!", "Erreur de sélection");    
}

void Regles::checkOwner(Plateau& plateau, Joueur& j_tour, int x, int y)
{
    Case c = plateau.getCase(x, y);
    Piece piece = c.getPiece();
    if(j_tour.getId() != piece.getJoueur().getId())
        throw Move_Exception("Cette pièce ne vous appartient pas!", "Erreur de sélection");
    
}

void Regles::checkMove1Box(int x1, int y1, int x2, int y2)
{
    if(abs(x1-x2)>1 || abs(y1-y2)>1)
    {
        throw Move_Exception("Cette pièce ne peut bouger que d'une case!", "Erreur de déplacement");
    }
}



void Regles::checkUpward(int x1, int y1, int x2, int y2)
{
    if(not (y2-y1>0))
    {
        throw Move_Exception("Cette piece doit avancer vers le haut!", "Erreur de déplacement");
    }
}

void Regles::checkDownward(int x1, int y1, int x2, int y2)
{
    if(not(y1-y2>0))
    {
        throw Move_Exception("Cette piece doit avancer vers le bas!", "Erreur de déplacement");
    }
}


void Regles::checkDistanceFromStartLessThanN(int n, int x1, int y1, int x2, int y2)
{
    if(abs(x1-x2)>n || abs(y1-y2)>n)
    {
        throw Move_Exception("Cette pièce n'a pas le droit d'aller aussi loin!", "Erreur de déplacement");
    }
}

void Regles::checkDistanceFromStartExactlyN(int n, int x1, int y1, int x2, int y2)
{
    if((abs(x1-x2) != n || abs(y1-y2) != n))
    {
        throw Move_Exception("Cette pièce n'a pas le droit d'aller aussi loin!", "Erreur de déplacement");
    }
}

void Regles::checkPath(Plateau& plateau, Joueur& j_tour, int x1, int y1, int x2, int y2)
{
    Case c;
    Piece piece;
    int i = x2;
    int j = y2;
    while(i != x1 || j != y1){
        //std::cout << "j'essayait d'acceder a la case " << i << " " << j << std::endl;
        c = plateau.getCase(i, j);
        //Case inutiliable
        if(c.getCouleur() == 1)
        {
            throw Move_Exception("Case inutilisable sur le chemin!", "Erreur de déplacement");
        }
        //Case d'arrivée occupée par piece du joueur actif
        if(i == x2 && j == y2){
            
            if(not c.isEmpty())
            {
                piece = c.getPiece();
                
                if(j_tour.getId() == piece.getJoueur().getId())
                {
                    //cout << "C'est le tour du joueur numero " << j_tour.getId() << " qui attaque la piece apartenant au joueur " << piece.getJoueur().getId() <<   endl;
                    
                    
                    throw Move_Exception("Case déjà occupee par une de vos pieces!", "Erreur de déplacement");
                }
            }
        }
        //Case intermediaire non-vide
        if((not c.isEmpty()) && (not(i == x2 && j == y2)) && (not(i == x1 && j == y1)))
            throw Move_Exception("Case occupée sur le chemin!", "Erreur de déplacement");
            
            
        //incrémentation/décrémentation adaptée
        if(i > x1)
                i--;
        else if(i < x1)
                i++;
        if(j > y1)
            j--;
        else if(j < y1)
            j++;
    }
}

