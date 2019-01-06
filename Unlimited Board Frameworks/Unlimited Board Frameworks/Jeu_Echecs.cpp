//
//  Jeu_Echecs.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 05/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Jeu_Echecs.hpp"
#include "Input_Taker.hpp"
#include "Move_Exception.hpp"

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
    
    int i = 0;
    
    
    int x;
    int y;
    
    //On place les pieces dans le plateau
    
    for ( y = 0; y < 2 ; y ++)
    {
        for ( x = 0; x<8; x ++)
        {
            m_regles.placePiece(m_plateau, m_plateau.getPiece(i), x, y);
            
            i++;
            
        }
    }
    
    for ( y = 7; y >= 6 ; y --)
    {
        for ( x = 0; x<8; x ++)
        {
            //cout << "Allo" << endl;
            m_regles.placePiece(m_plateau, m_plateau.getPiece(i), x, y);
            
            i++;
            
        }
    }
    
    m_affichage.affichageTotal(m_plateau);
    
    int cptTour =0;
    
    Joueur currentPlayer = m_listJoueurs[0];
    
    while(m_regles.etatPartie(m_plateau)==0)
    {
        
        
        
        
        bool canPass = false;
        
        while (canPass == false)
        {
            try
            {
                
                m_affichage.affichageTotal(m_plateau);
                currentPlayer = m_listJoueurs[cptTour%2];
                //cout << "Joueur courant :" << currentPlayer.getNom() << " d'id " << currentPlayer.getId() << endl;
                m_affichage.demanderMouvement(currentPlayer);
                std::vector<std::string> res = Input_Taker::recupererMouvement();
                
                char c1 = res[0][0];
                int valX1 = c1 - 'a';
                std::string strY1 = res[0].substr(1);
                int valY1 = std::stoi(strY1) - 1;
                
                char c2 = res[1][0];
                int valX2 = c2 - 'a';
                std::string strY2 = res[1].substr(1);
                int valY2 = std::stoi(strY2) - 1;
                if(m_regles.checkMove(m_plateau, valX1, valY1, valX2, valY2, currentPlayer) == 0)
                {
                    m_regles.move(m_plateau, valX1, valY1, valX2, valY2);
                }
                
                cptTour++;
            }
            catch(Input_Exception iE)
            {
                std::cerr << "ERREUR D'INPUT : " << iE.what() << std::endl;
                canPass = false;
            }
            
            catch(Move_Exception mE)
            {
                std::cerr << "ERREUR DE MOUVEMENT : " << mE.what() << std::endl;
                canPass = false;
            }
        }
        
    }
    
    std::cout << "Partie finie !" << std::endl;
    
    


}
