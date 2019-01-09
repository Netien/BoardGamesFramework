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
    
    //On met les pieces dans le plateau
    remplirListePieces();
    //On place les pieces dans le plateau
    placerDansPlateau();
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

void Jeu_Echecs::placerDansPlateau()
{
    int i = 0;
    int x;
    int y;
    
    //On place les pieces dans le plateau
    for ( y = 0; y < 2 ; y ++)
    {
        for ( x = 0; x < m_plateau.getLargeur(); x ++)
        {
            
            m_regles.placePiece(m_plateau, m_plateau.getPiece(i), x, y);
            i++;
            
        }
    }
    
    for ( y = m_plateau.getHauteur()-1; y >= m_plateau.getHauteur()-2; y --)
    {
        for ( x = 0; x <  m_plateau.getLargeur(); x ++)
        {
            
            m_regles.placePiece(m_plateau, m_plateau.getPiece(i), x, y);
            i++;
            
        }
    }

}

void Jeu_Echecs::start()
{

    m_affichage.affichageBienvenue();
    
    m_affichage.affichageTotal(m_plateau);
    
    int cptTour =0;
    bool isCurrentChecked = false;
    Joueur currentPlayer = m_listJoueurs[0];
    Joueur ennemyPlayer = m_listJoueurs[1];
    
    Regles_Echecs* pRE = dynamic_cast<Regles_Echecs*>(&m_regles);//Dynamic casts pour accéder de façon plus sûre aux informations spécifiques aux objets dérivés
    Plateau_Echecs* pPE = dynamic_cast<Plateau_Echecs*>(&m_plateau);
    
    if(pRE == 0 or pPE ==0)
    {
        throw std::runtime_error("dynamic cast a échoué");
    }
    
    while(m_regles.etatPartie(m_plateau)==0)
    {
        
        bool canPass = false;
        
        while (canPass == false)
        {
            
            try
            {
            
                isCurrentChecked = false;
                
                
                
                m_affichage.affichageTotal(m_plateau);
                currentPlayer = m_listJoueurs[cptTour%2];
                
                ennemyPlayer = m_listJoueurs[(cptTour+1)%2];
                
                //std::cout << "Joueur courant :" << currentPlayer.getNom() << " d'id " << currentPlayer.getId() << std::endl;
                
                
                Piece& p = Case::puit;
            
                
                if(pRE->isChecked(currentPlayer, *pPE, p))
                {
                    if(pRE->isCheckmated(currentPlayer, *pPE, p))
                    {
                        Afficheur_Echecs::annonceEchecEtMat(currentPlayer);
                    }
                    Afficheur_Echecs::annoncerEchecs();
                    isCurrentChecked = true;
                }
                pRE->isChecked(ennemyPlayer, *pPE);
                
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
                    
                    Piece& ptemp = m_plateau.getCase(valX2, valY2).getPiece();
                    m_regles.move(m_plateau, valX1, valY1, valX2, valY2);
                    if(pRE->isChecked(currentPlayer, *pPE))
                    {
                        if(isCurrentChecked == false)
                        {
                            m_regles.move(m_plateau, valX2, valY2, valX1, valY1);
                            m_plateau.dispatch(ptemp, valX2, valY2);
                            std::cout << "la piece de type" << ptemp.getType() << "est gentiement remise en place sans bobo"<<std::endl;
                            throw Move_Exception("Mouvement impossible : vous met en échec !", "Erreur de mouvement");
                        }
                        else
                        {
                            m_regles.move(m_plateau, valX2, valY2, valX1, valY1);
                            m_plateau.dispatch(ptemp, valX2, valY2);
                            //std::cout << "la piece de type" << ptemp.getType() << "est gentiement remise en place sans bobo"<<std::endl;
                            throw Move_Exception("Mouvement impossible : vous êtes toujours en échec !", "Erreur de mouvement");
                        }
                    }
                }
                
                if(pRE->isPromoted(valX2, valY2, currentPlayer, *pPE))
                {
                    Afficheur_Echecs::demanderPromotion();
                    std::string s = Input_Taker::recupererCommande();
                    if (s == "C") {
                        pPE->getCase(valX2, valY2).getPiece().promotion(1);
                    }
                    else
                    {
                        pPE->getCase(valX2, valY2).getPiece().promotion(4);
                    }
                    
                }
                
                cptTour++;
            }
            catch(Input_Exception iE)
            {
                std::cerr << std::endl << std::endl << "ERREUR D'INPUT : " << iE.what() << std::endl;
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
