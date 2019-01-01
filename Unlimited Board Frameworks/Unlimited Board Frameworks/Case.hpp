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
    
    void setPiece(Piece *p){ m_piece = p; };
    Piece getPiece() { return *m_piece; };
    int getCouleur() { return m_couleur; };
    bool isEmpty() { return m_piece == NULL; };
    
    bool operator==(const Case &c){
    	bool eq = this->m_coordX == c.m_coordX;
    	eq |= this->m_coordY == c.m_coordY;
    	return eq;
    };
    bool operator!=(const Case &c){
    	return !(this == &c);
    }
};

#endif /* Case_hpp */

