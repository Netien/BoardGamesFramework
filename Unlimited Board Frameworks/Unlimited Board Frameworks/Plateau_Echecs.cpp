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
