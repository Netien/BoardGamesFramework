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
    Joueur & m_joueur; //Une piece a toujours un joeur associé (donc référence)
    int m_coordX = -1;
    int m_coordY = -1;
    int m_type;
    int id;
public :
    Piece(int type, int id, Joueur& j);
    void promotion(int n_type){ m_type = n_type; };
    int getId(){ return id; };
    void move(int x, int y){ m_coordX = x ; m_coordY = y ; };
};

#endif /* Piece_hpp */
