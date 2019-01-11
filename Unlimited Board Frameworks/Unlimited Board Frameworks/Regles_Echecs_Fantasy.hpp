//
//  Regles_Echecs_Fantasy.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 11/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Regles_Echecs_Fantasy_hpp
#define Regles_Echecs_Fantasy_hpp

#include "Regles_Echecs.hpp"

class Regles_Echecs_Fantasy : public Regles_Echecs
{
public :
    int checkMove(Plateau& plateau, int x1, int y1, int x2, int y2, Joueur& j_tour);
    bool isAccessible(Piece& p, Plateau& plat, int x, int y);
    
};


#endif /* Regles_Echecs_Fantasy_hpp */
