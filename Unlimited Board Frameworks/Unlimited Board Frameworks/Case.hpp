//
//  Case.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 24/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Case_hpp
#define Case_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Piece.hpp"

class Case{
private :
    Piece *m_piece; //Une case peut avoir une piece ou non
    int m_coordX;
    int m_coordY;
    int m_couleur;
    
    /*Une case a une couleur. cela sert pour l'affichage et également pour représenter
     certaines propriétés à tester (exemple : une case bleue dans le Stratego n'est pas franchissable)
     Convention:
     1-Blanc
     2-Bleu
     3-Rouge
     4-Jaune
     5-Violet
     6-Orange
     7-Vert
     8-Noir
     */
    
public :
    static Piece puit;
    Case();
    Case(int coordX, int coordY);
    Case(int coordX, int coordY, int couleur);
    
    Piece* getPiece();
    int getCouleur();
    int getX();
    int getY();
    void setPiece(Piece *p);
    void setCouleur(int coul);
    void setCoord(int x, int y);
    bool isEmpty();
    
    bool operator==(const Case &c);
    bool operator!=(const Case &c);
};

#endif /* Case_hpp */

