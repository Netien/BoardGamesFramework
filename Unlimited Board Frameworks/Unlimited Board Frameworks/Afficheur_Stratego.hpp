//
//  Afficheur_Stratego.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 03/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Afficheur_Stratego_hpp
#define Afficheur_Stratego_hpp

#include <stdio.h>
#include "Affichage.hpp"
#include "Plateau_De_Stratego.hpp"

class Afficheur_Stratego : public Affichage
{
public :
    void affichageTotal(Plateau & p);
    void affichagePartiel(Plateau & p, Joueur j);
};


#endif /* Afficheur_Stratego_hpp */
