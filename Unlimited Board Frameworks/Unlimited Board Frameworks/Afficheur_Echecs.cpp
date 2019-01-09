//
//  Afficheur_Echecs.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 05/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Afficheur_Echecs.hpp"
using namespace std;

void Afficheur_Echecs::affichageTotal(Plateau & p)
{
    cout << endl;
    
    for(int y = p.getHauteur()-1; y >= 0; y--)
    {
        cout << endl;
        cout << endl;
        cout << y+1 << "\t";
        //cout << (char)('a'+ y) << "\t";
        
        for(int x = 0; x< p.getLargeur(); x++)
        {
            Case c = p.getCase(x, y);
            
            if(c.isEmpty())
            {
                if(c.getCouleur()==0)
                {
                    cout << "\u25FB\t";
                }
                
                if(c.getCouleur()==7)
                {
                    cout << "\u25FC\t";
                }
            }
            else
            {
                int type = c.getPiece().getType();
                Joueur proprietaire = c.getPiece().getJoueur();
                
                if (type == 0)
                {
                    if(proprietaire.getId() == 0)
                    {
                        cout <<"\u265F\t" ;
                    }
                    if(proprietaire.getId() == 1)
                    {
                        cout <<"\u2659\t";
                    }
                }
                else if (type == 1)
                {
                    if(proprietaire.getId() == 0)
                    {
                        cout << "\u265E\t";
                    }
                    if(proprietaire.getId() == 1)
                    {
                        cout <<"\u2658\t" ;
                    }
                }
                else if (type == 2)
                {
                    if(proprietaire.getId() == 0)
                    {
                        cout <<"\u265D\t";
                    }
                    if(proprietaire.getId() == 1)
                    {
                        cout <<"\u2657\t";
                    }
                }
                else if (type == 3)
                {
                    if(proprietaire.getId() == 0)
                    {
                        cout << "\u265C\t";
                    }
                    if(proprietaire.getId() == 1)
                    {
                        cout << "\u2656\t";
                    }
                }
                else if (type == 4)
                {
                    if(proprietaire.getId() == 0)
                    {
                        cout << "\u265B\t";
                    }
                    if(proprietaire.getId() == 1)
                    {
                        cout << "\u2655\t";
                    }
                }
                else if (type == 5)
                {
                    if(proprietaire.getId() == 0)
                    {
                        cout <<"\u265A\t";
                    }
                    if(proprietaire.getId() == 1)
                    {
                        cout <<"\u2654\t";
                    }
                }
            }
        }
    }
    cout << endl;
    cout << endl << "\t";
    
    for(int x = 0; x< p.getLargeur(); x++)
    {
        cout << (char)('a'+ x) << "\t";
    }
    
    cout << endl;
    cout << endl;
}

void Afficheur_Echecs::affichagePartiel(Plateau & p, Joueur j)
{
    
}



void Afficheur_Echecs::demanderPromotion()
{
    cout << "Voulez vous transformer votre pion en Cavalier ou en Reine ? (C/R)" << endl;
}

void Afficheur_Echecs::affichageBienvenue()
{
    cout << "Bienvenu au jeu d'echecs" << endl;
}

void Afficheur_Echecs::annoncerEchecs()
{
    cout << "vous êtes en échec !" << endl;
}

void Afficheur_Echecs::toujoursEnEchecs()
{
    cout << "vous êtes toujours en échec !" << endl;
}

void Afficheur_Echecs::vousMetEnEchec()
{
    cout << "Ce coup vous met en échec !" << endl;
}

void Afficheur_Echecs::annonceEchecEtMat(Joueur j)
{
    std::cout << "Vous êtes en échec et mat, " << j.getNom() <<", vous avez perdu !" << endl;
}

//void affichagePartiel(Plateau & p, Joueur j);

//void demanderPlacement(Piece& p);

static std::string quelType(int i) //fonction qui renvoie le nom en string d'une piece selon i si besoin.
{
    switch (i) {
        case 0:
            return "pion";
            break;
        case 1:
            return "cavalier";
            break;
        case 2:
            return "fou";
            break;
        case 3:
            return "tour";
            break;
        case 4:
            return "reine";
            break;
        case 5:
            return "roi";
            break;
        default:
            return "piece inconnue aux echecs";
            break;
    }
}
