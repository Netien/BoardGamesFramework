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
    int m_coordX;
    int m_coordY;
    std::string m_type;
    
public :
    Piece(int coordX, int coordY, std::string type, Joueur & j);
    virtual void promotion();
};

#endif /* Piece_hpp */
