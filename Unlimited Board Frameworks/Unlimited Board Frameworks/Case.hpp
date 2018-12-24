//
//  Case.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 24/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Case_hpp
#define Case_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Piece.hpp"


#endif /* Case_hpp */
class Case
{
    
    public :
    
    Case(int coordX, int coordY);
    
    private :
    
    Piece * m_piece;
    int m_coordX;
    int m_coordY;
    std::string couleur;
    
};
