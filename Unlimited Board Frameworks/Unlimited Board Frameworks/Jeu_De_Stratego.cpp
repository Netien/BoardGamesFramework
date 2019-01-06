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
#include "Input_Taker.hpp"
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
    
    m_affichage.affichageBienvenue();
    
    m_affichage.affichageTotal(m_plateau);
    
    
    vector<std::string> res;
    
    for(unsigned int i = 0; i<m_plateau.getLongListePieces(); i++)
    {
        
        
        
        bool canPass = false;
        
        m_affichage.affichagePartiel(m_plateau, m_plateau.getPiece(i).getJoueur() );
        
        while (canPass == false)
        {
            m_affichage.demanderPlacement(m_plateau.getPiece(i));
            
            
            try{
                res = Input_Taker::recupererPlacement();
                
                char c = res[0][0];
                
                int valX = c - 'a';
                
                std::string strY = res[0].substr(1);
                
                int valY = std::stoi(strY) - 1;
                
                if(m_regles.placePiece(m_plateau, m_plateau.getPiece(i), valX, valY))
                {
                    canPass = true;
                }
                else
                {
                    m_affichage.affichageErreurPlacement();
                }
                
            
                
                
            }
            catch(Input_Exception const& iE)
            {
                cerr << "ERREUR D'INPUT : " << iE.what() << endl;
                canPass = false;
            }
            catch(std::exception const& e)
            {
                cerr << "ERREUR : " << e.what() << endl;
                canPass = false;
            }
        }
    }
    
    int cptTour =0;
    
    while(m_regles.etatPartie(m_plateau)==0)
    {
        
        Joueur currentPlayer;
        
        
        bool canPass = false;
        
        while (canPass == false)
        {
            try
            {
                
                
                currentPlayer = m_listJoueurs[cptTour%2];
                m_affichage.affichagePartiel(m_plateau, currentPlayer);
                cout << "Joueur courant :" << currentPlayer.getNom() << " d'id " << currentPlayer.getId() << endl;
                m_affichage.demanderMouvement(currentPlayer);
                std::vector<string> res = Input_Taker::recupererMouvement();
                
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
                cerr << "ERREUR D'INPUT : " << iE.what() << endl;
                canPass = false;
            }
            
            catch(Move_Exception mE)
            {
                cerr << "ERREUR DE MOUVEMENT : " << mE.what() << endl;
                canPass = false;
            }
        }
        
    }
    
    cout << "Partie finie !" << endl;
    
    

}


void Jeu_De_Stratego::startTest()
{
    
    m_affichage.affichageBienvenue();
    
    m_affichage.affichageTotal(m_plateau);
    
    int i = 0;
    
    
    int ind;
    int j;
    
    for ( ind = 0; ind < 10 ; ind ++)
    {
        for ( j = 0; j<4; j++)
        {
            m_regles.placePiece(m_plateau, m_plateau.getPiece(i), ind, j);
            
            i++;
            
        }
    }
    
    for ( ind = 0; ind < 10 ; ind ++)
    {
        for ( j = 9; j>5; j--)
        {
            //cout << "Allo" << endl;
            m_regles.placePiece(m_plateau, m_plateau.getPiece(i), ind, j);
            
            i++;
            
        }
    }
    
    
    
    m_affichage.affichageTotal(m_plateau);
    
    
    
    
    
    
    int cptTour =0;
    
    while(m_regles.etatPartie(m_plateau)==0)
    {
        
        Joueur currentPlayer;
        
        
        bool canPass = false;
        
        while (canPass == false)
        {
            try
            {
                
                m_affichage.affichageTotal(m_plateau);
                currentPlayer = m_listJoueurs[cptTour%2];
                //cout << "Joueur courent :" << currentPlayer.getNom() << " d'id " << currentPlayer.getId() << endl;
                m_affichage.demanderMouvement(currentPlayer);
                std::vector<string> res = Input_Taker::recupererMouvement();
                
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
                cerr << "ERREUR D'INPUT : " << iE.what() << endl;
                canPass = false;
            }
            
            catch(Move_Exception mE)
            {
                cerr << "ERREUR DE MOUVEMENT : " << mE.what() << endl;
                canPass = false;
            }
        }
        
    }
    
    cout << "Partie finie !" << endl;
    
    
    
}

