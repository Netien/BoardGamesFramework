//
//  Regles.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 25/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef R_Stratego_hpp
#define R_Stratego_hpp

#include "Regles.hpp"
#include "Plateau.hpp"
#include "Piece.hpp"
#include "Case.hpp"
#include "Plateau_De_Stratego.hpp"
#include <vector>

using namespace std;

class R_Stratego : public Regles
{
private:
  vector<vector<Case> > positions;
  virtual bool count_Dif_Pos_Ok(Piece &piece, Case &c);
  virtual void recordMove(Plateau_De_Stratego &plateau, Piece &piece, int x, int y);
  
public :
  R_Stratego();
  virtual int checkMove(Plateau_De_Stratego &p, int x1, int y1, int x2, int y2, Joueur j_tour);
  virtual void move(Plateau_De_Stratego &p, int x1, int y1, int x2, int y2);
  virtual int etatPartie(Plateau_De_Stratego &p);
  virtual bool placePiece(Plateau_De_Stratego &p, Piece &piece, int x, int y, Joueur j);
};
#endif /* Regles_hpp */
