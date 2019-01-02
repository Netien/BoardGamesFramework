//
//  Joueur.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 24/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Joueur.hpp"

using namespace std;

Joueur::Joueur(string nom, int id) : m_nom(nom), m_score(0), m_id(id){}

int Joueur::getId(){ return m_id; }
