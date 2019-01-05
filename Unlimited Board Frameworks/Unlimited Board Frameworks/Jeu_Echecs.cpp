//
//  Jeu_Echecs.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 05/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Jeu_Echecs.hpp"


Jeu_Echecs::Jeu_Echecs(Plateau_Echecs& p, Regles_Echecs& r, std::vector<Joueur>& v, Afficheur_Echecs& a) : Jeu(p, r, v, a)
{
    if (v.size()!=2)
        throw std::runtime_error("seul 2 joueurs possibles pour ce jeu");
    
    remplirListePieces();
}



void Jeu_Echecs::remplirListePieces()
{
    for(int j = 0; j < 2; j++)
    {
        int type = 0;
        for(int i = 0; i < 16; i++)
        {
            
            //on place les piece dans la liste de piece dans un ordre qui permet de les placer facilement sur le plateau après.
            if(i == 0)
                type = 3;//tour
            else if(i == 1)
                type = 1;//cavalier
            else if(i == 2)
                type = 2;//fou
            else if(i == 3)
                type = 4;//reine
            else if(i == 4)
                type = 5;//roi
            else if(i == 5)
                type = 2;//2e fou
            else if(i == 6)
                type = 1;//2e cavalier
            else if(i == 7)
                type = 3;//2e tour
            else
                type = 0;//les pions
            
            
            Piece p(type, m_listJoueurs[j]);
            
            m_plateau.ajoutPiece(p);
            
        }
    }
}

void Jeu_Echecs::start()
{
    m_affichage.affichageBienvenue();
    
    m_affichage.affichageTotal(m_plateau);
}
