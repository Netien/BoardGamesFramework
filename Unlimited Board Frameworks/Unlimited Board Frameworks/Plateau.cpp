//
//  Plateau.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 25/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Plateau.hpp"
Plateau::Plateau(const int largeur, const int hauteur) : m_largeur(largeur), m_hauteur(hauteur) {
    int x = 0;
    int y;
    m_damier = std::vector<std::vector<Case>>(largeur);
    while(x < largeur){
    	m_damier[x] = std::vector<Case>(hauteur);
    	y = 0;
    	while(y < hauteur){
    		m_damier[x][y] = Case(x, y);
    		y++;
    	}
    	x++;
    }
    
}

