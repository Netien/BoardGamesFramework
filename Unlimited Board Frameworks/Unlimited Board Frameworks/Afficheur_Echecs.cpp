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
                int type = c.getPiece()->getType();
                Joueur proprietaire = c.getPiece()->getJoueur();
                
                if (type == 0)
                {
                    if(proprietaire.getId() == 0)
                    {
                        cout <<"\u2659\t" ;
                    }
                    if(proprietaire.getId() == 1)
                    {
                        cout <<"\u265F\t";
                    }
                }
                else if (type == 1)
                {
                    if(proprietaire.getId() == 0)
                    {
                        cout << "\u2658\t";
                    }
                    if(proprietaire.getId() == 1)
                    {
                        cout <<"\u265E\t" ;
                    }
                }
                else if (type == 2)
                {
                    if(proprietaire.getId() == 0)
                    {
                        cout <<"\u2657\t";
                    }
                    if(proprietaire.getId() == 1)
                    {
                        cout <<"\u265D\t";
                    }
                }
                else if (type == 3)
                {
                    if(proprietaire.getId() == 0)
                    {
                        cout << "\u2656\t";
                    }
                    if(proprietaire.getId() == 1)
                    {
                        cout << "\u265C\t";
                    }
                }
                else if (type == 4)
                {
                    if(proprietaire.getId() == 0)
                    {
                        cout << "\u2655\t";
                    }
                    if(proprietaire.getId() == 1)
                    {
                        cout << "\u265B\t";
                    }
                }
                else if (type == 5)
                {
                    if(proprietaire.getId() == 0)
                    {
                        cout <<"\u2654\t";
                    }
                    if(proprietaire.getId() == 1)
                    {
                        cout <<"\u265A\t";
                    }
                }


                
            }
        }
    }
    cout << endl;
    cout << endl;
}

void Afficheur_Echecs::affichagePartiel(Plateau & p, Joueur j)
{
    
}

void Afficheur_Echecs::affichageBienvenue()
{
    cout << "Bienvenu au jeu d'echecs" << endl;
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
