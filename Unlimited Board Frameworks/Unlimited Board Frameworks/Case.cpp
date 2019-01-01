//
//  Case.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 24/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Case.hpp"

Case::Case() : m_coordX(-1), m_coordY(-1), m_piece(NULL), m_couleur(0)
{
    
}

Case::Case(int coordX, int coordY) : m_coordX(coordX), m_coordY(coordY), m_piece(NULL), m_couleur(0)
{
    
}

Case::Case(int coordX, int coordY, int couleur) : m_coordX(coordX), m_coordY(coordY), m_piece(NULL), m_couleur(couleur)
{
    
}

void Case::setCoord(int x, int y){
    m_coordX = x;
    m_coordY = y;
}
