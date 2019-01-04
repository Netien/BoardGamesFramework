//
//  Jeu_De_Stratego.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 03/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Jeu_De_Stratego.hpp"
#include "Plateau_De_Stratego.hpp"
#include <cassert>

using namespace std;

Jeu_De_Stratego::Jeu_De_Stratego(Plateau_De_Stratego &p, R_Stratego &r, vector<Joueur> &v, Afficheur_Stratego &a) : Jeu(p, r, v, a)
{
    if (v.size()!=2)
        throw std::runtime_error("seul 2 joueurs possibles pour ce jeu");
    
    remplirListePieces();
}

void Jeu_De_Stratego::remplirListePieces()
{
    
    
    for(int j = 0; j < 2; j++)
    {
        int type = 0;
        
        for(int i = 0; i < 40; i++)
        {
            
            
            if(i == 1)
                type = 1;
            if(i == 2)
                type = 2;
            if(i == 10)
                type = 3;
            if(i == 15)
                type = 4;
            if(i == 19)
                type = 5;
            if(i == 23)
                type = 6;
            if(i == 27)
                type = 7;
            if(i == 30)
                type = 8;
            if(i == 32)
                type = 9;
            if(i == 33)
                type = 10;
            if(i == 34)
                type = 11;
            
            Piece p(type, m_listJoueurs[j]);
            
            m_plateau.ajoutPiece(p);
            
        }
    }
    
    

}


void Jeu_De_Stratego::start()
{
    m_affichage.affichageTotal(m_plateau);

}
