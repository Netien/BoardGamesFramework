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
    Piece *m_piece; //Une case peut avoir une piece ou non (pointeur NULL dans ce cas)
    int m_coordX;
    int m_coordY;
    int m_couleur;
    
public :
    Case();
    Case(int coordX, int coordY);
    Case(int coordX, int coordY, int couleur);
    
    Piece getPiece();
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

