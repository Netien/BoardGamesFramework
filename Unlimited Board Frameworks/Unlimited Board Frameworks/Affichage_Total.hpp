//
//  Affichage_Total.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 03/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Affichage_Total_hpp
#define Affichage_Total_hpp

#include <stdio.h>
#include "Plateau.hpp"
class Affichage_Total
{
public :
    virtual void afficher(Plateau p)=0;
};

#endif /* Affichage_Total_hpp */
