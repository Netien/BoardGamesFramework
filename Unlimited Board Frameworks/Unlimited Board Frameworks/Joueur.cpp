//
//  Joueur.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 24/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Joueur.hpp"

using namespace std;

int Joueur::id = 0;

Joueur::Joueur() : m_nom("Personne"), m_score(0), m_id(-1)
{
    
}

Joueur::Joueur(string nom) : m_nom(nom), m_score(0), m_id(id)
{
    id++;
}

int Joueur::getId(){ return m_id; }

string Joueur::getNom(){ return m_nom; }
