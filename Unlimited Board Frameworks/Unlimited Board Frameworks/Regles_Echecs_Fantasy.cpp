//
//  Regles_Echecs_Fantasy.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 11/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Regles_Echecs_Fantasy.hpp"


int Regles_Echecs_Fantasy::checkMove(Plateau& plateau, int x1, int y1, int x2, int y2, Joueur& j_tour)
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
    
    if (type == 6)//Si c'est un garde royal
    {
        checkDistanceFromStartLessThanN(2, x1, y1, x2, y2);//pas a une distance de plus de 2 cases

    }
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
    else if (type == 0)//Si c'est un pion
    {
        
        checkPawnMovement(plateau, j_tour, x1, y1, x2, y2);
        
    }
    if(type != 1 && type != 6) //Si c'est autre chose qu'un cavalier OU un garde royal
    {
        //On regarde si le chemin est libre
        checkPath(plateau, j_tour, x1, y1, x2, y2);
    }
    
    
    return 0;
}



bool Regles_Echecs_Fantasy::isAccessible(Piece& p, Plateau& plat, int x, int y)//Permet de vérifier si la case de coordonées x, y est accessible par la piece p sur le plateau plat.
{
    
    int type = p.getType();
    
    try {
        //On regarde si le plateau contient la case d'arrivee
        checkOutOfBounds(plat, x, y);
        
        //Si ce n'est pas un cavalier, il faut déja vérifier que le chemin est libre
        if (type == 6)//Si c'est un garde royal
        {
            checkDistanceFromStartLessThanN(2, p.getX(), p.getY(), x, y);
        }

        if (type == 5)//Si c'est un roi
        {
            checkMove1Box(p.getX(), p.getY(), x, y);//il ne peut bouger que d'une case
        }
        else if (type == 4)//Si c'est une reine
        {
            checkDiagoOrthogonal(p.getX(), p.getY(), x, y);
        }
        else if (type == 3)//Si c'est une tour
        {
            checkOrthogonal(p.getX(), p.getY(), x, y);
        }
        
        else if (type == 2)//Si c'est un fou
        {
            checkDiagonal(p.getX(), p.getY(), x, y);
        }
        else if (type == 1)//Si c'est un cavalier
        {
            checkNonOrthogonal(p.getX(), p.getY(), x, y);//alors si il ne se dáplace pas orthogonalement
            checkNonDiagonal(p.getX(), p.getY(), x, y);//pas diagonalement
            checkDistanceFromStartLessThanN(2, p.getX(), p.getY(), x, y);//et pas a une distance de plus de 2 cases
            //c'est bon !
        }
        else if (type == 0)//Si c'est un pion
        {
            checkPawnMovement(plat, p.getJoueur(), p.getX(), p.getY(), x, y);
        }
        
        if (type != 1 && type != 6) {
            checkPath(plat, p.getJoueur(), p.getX(), p.getY(), x, y);
        }
        
        
        
        
    }
    catch(Move_Exception mE)
    {
        return false;
    }
    
    return true;
}

