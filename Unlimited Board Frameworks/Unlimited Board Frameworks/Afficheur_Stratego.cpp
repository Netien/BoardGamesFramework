//
//  Afficheur_Stratego.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 03/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Afficheur_Stratego.hpp"

using namespace std;

void Afficheur_Stratego::affichagePartiel(Plateau & p, Joueur j)
{

    cout << endl;
    for(int y = p.getHauteur()-1; y >= 0; y--)
    {
        cout << endl;
        cout << y+1 << "\t";
        
        for(int x = 0; x< p.getLargeur(); x++)
        {
            Case c = p.getCase(x, y);
            
            if(c.isEmpty())
            {
                if(c.getCouleur()==0)
                {
                    cout << " " << "\u25A0" << " ";
                }
                
                if(c.getCouleur()==1)
                {
                    cout << " " << "\u25A1" << " ";
                }
            }
            else
            {
                Piece p = c.getPiece();
                int type = p.getType();
                if (p.getJoueur().getId() != j.getId())
                {
                    cout << " ? ";
                }
                else if (type < 10)
                {
                    cout << " " << type << " ";
                }
                else if (type == 10)
                {
                    cout << " " << 'M' << " ";
                }
                else
                {
                    cout << " " << 'B' << " ";
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


void Afficheur_Stratego::affichageTotal(Plateau & p)
{
    cout << endl;
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
                    cout << " " << "\u25A0" << " ";
                }
                
                if(c.getCouleur()==1)
                {
                    cout << " " << "\u25A1" << " ";
                }
            }
            else
            {
                int type = c.getPiece().getType();
                
                if (type < 10)
                {
                    cout << " " << type << " ";
                }
                else if (type == 10)
                {
                    cout << " " << 'M' << " ";
                }
                else
                {
                    cout << " " << 'B' << " ";
                }
                
            }
        }
    }
    cout << endl;
    cout << endl;
}



void Afficheur_Stratego::affichageBienvenue()
{
    cout << "Bienvenue dans le Stratégo !" << endl;
}

std::string Afficheur_Stratego::quelType(int i)
{
    switch (i) {
        case 0 :
            return "drapeau";
            break;
        case 1 :
            return "espion";
            break;
        case 2 :
            return "eclaireur";
            break;
        case 3 :
            return "demineur";
            break;
        case 4 :
            return "sergeant";
            break;
        case 5 :
            return "lieutenant";
            break;
        case 6 :
            return "capitaine";
            break;
        case 7 :
            return "commandant";
            break;
        case 8 :
            return "colonel";
            break;
        case 9 :
            return "général";
            break;
        case 10 :
            return "maréchal";
            break;
        case 11 :
            return "bombe";
            break;
            
        default:
            return "type inconnu !";
            break;
    }
}

 void Afficheur_Stratego::annoncerCombat(Piece & p1, Piece & p2)
{
    cout << "Un combat a lieu entre le " << quelType(p1.getType()) << " de " << p1.getJoueur().getNom() << " et le "
    << Afficheur_Stratego::quelType(p2.getType()) << " de " << p2.getJoueur().getNom() << endl ;
}

void Afficheur_Stratego::annoncerVictoire(Piece& p)
{
    cout << " La piece " << quelType(p.getType()) << " de " << p.getJoueur().getNom() << " l'emporte." << endl ;
}

void Afficheur_Stratego::annoncerMatchNul()
{
    cout << "Autodestruction mutuelle !" << endl ;
}

void Afficheur_Stratego::demanderPlacement(Piece& p)
{
    cout << "ou voulez vous placer le pion " << quelType(p.getType())<< ", " << p.getJoueur().getNom() << " ?" << endl;
}

