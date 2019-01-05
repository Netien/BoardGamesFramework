//
//  Plateau_Echecs.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 05/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Plateau_Echecs_hpp
#define Plateau_Echecs_hpp

#include <stdio.h>
#include "Plateau.hpp"
class Plateau_Echecs : public Plateau
{
public :
    Plateau_Echecs();
    Plateau_Echecs(int l, int h);
    friend class Regles_Echecs;
};
#endif /* Plateau_Echecs_hpp */
