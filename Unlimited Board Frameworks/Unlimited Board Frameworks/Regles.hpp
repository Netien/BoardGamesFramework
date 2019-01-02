//
//  Regles.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 25/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Regles_hpp
#define Regles_hpp

#include <stdio.h>
#include "Plateau.hpp"
#include "Piece.hpp"

class Regles
{
public :
  virtual int checkMove(Plateau &p, int x1, int y1, int x2, int y2, Joueur j_tour) = 0;
  virtual void move(Plateau &p, int x1, int y1, int x2, int y2) = 0;
  virtual int etatPartie(Plateau &p) = 0;
  virtual bool placePiece(Plateau &p, Piece *piece, int x, int y) = 0;
};
#endif /* Regles_hpp */
