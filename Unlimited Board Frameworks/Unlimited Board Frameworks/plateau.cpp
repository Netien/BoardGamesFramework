//
//  plateau.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 25/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#include "plateau.hpp"
Plateau::Plateau(const int largeur, const int hauteur) : m_largeur(largeur), m_hauteur(hauteur) {
    
    m_damier = new Case * [hauteur];
    
    for(int i = 0; i < hauteur; ++i)
    {
        m_damier[i] = new Case[largeur];
    }
    for(int i = 0; i<hauteur; ++i)
    {
        for(int j = 0; j<largeur; j++)
        {
            m_damier[i][j].setCoord(i, j);
        }
    }
}

Plateau::~Plateau()
{
    for(int i = 0; i < m_hauteur; ++i)
    {
        delete m_damier[i];
    }
    
    delete m_damier;
}
