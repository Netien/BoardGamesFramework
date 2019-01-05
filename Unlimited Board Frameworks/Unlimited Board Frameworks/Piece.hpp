//
//  Piece.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 24/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Piece_hpp
#define Piece_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Joueur.hpp"

class Piece{
private :
    Joueur m_joueur; //Une piece a toujours un joeur associé (donc référence)
    int m_coordX;
    int m_coordY;
    int m_type;
    int p_id;
    static int id;
    
public :
    
    Piece();
    Piece(int type, Joueur &j);
    void promotion(int n_type);
    int getId();
    int getX();
    int getY();
    Joueur getJoueur();
    int getType();
    void move(int x, int y);
};

#endif /* Piece_hpp */
