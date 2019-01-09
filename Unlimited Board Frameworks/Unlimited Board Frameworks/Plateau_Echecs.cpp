//
//  Plateau_Echecs.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 05/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Plateau_Echecs.hpp"

Plateau_Echecs::Plateau_Echecs(int l, int h) : Plateau(l, h)
{
    
    for(int y = 0; y < m_hauteur; y++)
    {
        for( int x = 0; x < m_largeur; x++)
        {
            if ( (x + y)%2 == 0){
                getCase(x, y).setCouleur(7);
            }
        }
        
    }
    
}

Plateau_Echecs::Plateau_Echecs() : Plateau_Echecs(8, 8)
{
}

std::vector<int> Plateau_Echecs::getCoordKing(Joueur& j)//trouve les coordonnées du roi de j
{
    std::vector<int> vect(2);
    
    for(Piece& p : m_listePieces)
    {
        if(p.getType()==5 and p.getJoueur().getId() == j.getId())
        {
            vect[0] = p.getX();
            vect[1] = p.getY();
        }
    }
    
    
    return vect;
    
}

Piece& Plateau_Echecs::getKing(Joueur& j)//trouve le roi de j
{

    for(Piece& p : m_listePieces)
    {
        if(p.getType()==5 and p.getJoueur().getId() == j.getId())
        {
            return p;
        }
    }
    throw std::runtime_error("Roi non trouvé!");

}

