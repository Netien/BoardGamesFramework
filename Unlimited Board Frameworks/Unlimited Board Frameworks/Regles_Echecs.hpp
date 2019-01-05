//
//  R_Echecs.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 05/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Regles_Echecs_hpp
#define Regles_Echecs_hpp

#include "Regles.hpp"
#include "Plateau.hpp"

class Regles_Echecs : public Regles
{
    public :
    Regles_Echecs();
    int checkMove(Plateau &p, int x1, int y1, int x2, int y2, Joueur j_tour);
    void move(Plateau &p, int x1, int y1, int x2, int y2);
    int etatPartie(Plateau &p);
    bool placePiece(Plateau &p, Piece &piece, int x, int y);
};

#endif /* Regles_Echecs_hpp */
