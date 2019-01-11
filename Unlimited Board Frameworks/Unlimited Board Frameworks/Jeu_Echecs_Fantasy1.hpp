//
//  Jeu_Echecs_Fantasy1.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 11/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Jeu_Echecs_Fantasy1_hpp
#define Jeu_Echecs_Fantasy1_hpp

#include <stdio.h>
#include "Jeu_Echecs.hpp"
#include "Plateau_Echecs_Fantasy.hpp"
#include "Regles_Echecs_Fantasy.hpp"


class Jeu_Echecs_Fantasy1 : public Jeu_Echecs
{
public:
    Jeu_Echecs_Fantasy1( Plateau_Echecs_Fantasy &p, Regles_Echecs_Fantasy &r, std::vector<Joueur> &v, Afficheur_Echecs &a);
    void start();
    void remplirListePieces();
    
};


#endif /* Jeu_Echecs_Fantasy1_hpp */

