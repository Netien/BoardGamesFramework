//
//  Afficheur_Stratego.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 03/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Afficheur_Stratego.hpp"


void Afficheur_Stratego::affichageTotal(Plateau p)
{
    for(int y = p.getHauteur()-1; y >= 0; y--)
    {
        cout << endl;
        
        for(int x = 0; x< p.getLargeur(); x++)
        {
            Case c = p.getCase(x, y);
            
            if(c.isEmpty())
            {
                if(c.getCouleur()==0)
                {
                    std::cout << " " << "\u25A0" << " ";
                }
                
                if(c.getCouleur()==1)
                {
                    std::cout << " " << "\u25A1" << " ";
                }
            }
            else
            {
                int type = c.getPiece().getType();
                
                if (type < 10)
                {
                    std::cout << " " << type << " ";
                }
                else if (type == 10)
                {
                    std::cout << 'M' << type << " ";
                }
                else
                {
                    std::cout << 'B' << type << " ";
                }
                
            }
        }
    }
}

void Afficheur_Stratego::affichagePartiel(Plateau p, Joueur j)
{
    
}
