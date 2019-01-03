//
//  Affichage_Partiel.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 03/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Affichage_Partiel_hpp
#define Affichage_Partiel_hpp

#include <stdio.h>
#include "Plateau.hpp"
#include "Joueur.hpp"

class Affichage_Partiel
{
    public :
    virtual void afficher(Plateau p, Joueur j)=0;
};


#endif /* Affichage_Partiel_hpp */
