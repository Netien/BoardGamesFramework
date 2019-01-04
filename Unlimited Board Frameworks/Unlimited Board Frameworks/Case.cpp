//
//  Case.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 24/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Case.hpp"

Case::Case() : m_piece(NULL), m_coordX(-1), m_coordY(-1), m_couleur(0)
{}

Case::Case(int coordX, int coordY) : m_piece(NULL), m_coordX(coordX), m_coordY(coordY), m_couleur(0)
{}

Case::Case(int coordX, int coordY, int couleur) : m_piece(NULL), m_coordX(coordX), m_coordY(coordY), m_couleur(couleur)
{}

Piece Case::getPiece() { return *m_piece; }

int Case::getCouleur() { return m_couleur; }

int Case::getX(){ return m_coordX; }

int Case::getY(){ return m_coordY; }

void Case::setPiece(Piece *p){ m_piece = p; }

void Case::setCouleur(int coul) {
    
    m_couleur = coul;

}

void Case::setCoord(int x, int y) { m_coordX = x; m_coordY = y; }

bool Case::isEmpty() { return m_piece == NULL; }

bool Case::operator==(const Case &c){
    bool eq = this->m_coordX == c.m_coordX;
    eq |= this->m_coordY == c.m_coordY;
    return eq;
}

bool Case::operator!=(const Case &c){
    return !(this == &c);
}
