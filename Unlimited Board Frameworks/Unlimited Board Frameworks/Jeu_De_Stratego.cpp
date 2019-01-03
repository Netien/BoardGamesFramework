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

Jeu_De_Stratego::Jeu_De_Stratego(Plateau_De_Stratego & p, R_Stratego & r, vector<Joueur> & v, Afficheur_Stratego & a ) : Jeu(p, r, v, a)
{assert(v.size()==2);}

void Jeu_De_Stratego::start()
{
    m_affichage.affichageTotal(m_plateau);
}
