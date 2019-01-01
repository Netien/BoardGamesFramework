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

class Regles
{
private:
  Plateau p;

public :
  virtual bool checkMove(int x1, int y1, int x2, int y2){ return false; };
  virtual void move(int x1, int y1, int x2, int y2){};
  virtual int etatPartie(){ return 0; };
};
#endif /* Regles_hpp */
