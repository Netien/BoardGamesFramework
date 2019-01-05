//
//  Regles.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 25/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef R_Stratego_hpp
#define R_Stratego_hpp

#include "Move_Exception.hpp"
#include "Regles.hpp"
#include "Piece.hpp"
#include "Case.hpp"
#include "Plateau_De_Stratego.hpp"
#include <vector>

class R_Stratego : public Regles
{
private:
    std::vector<std::vector<Case> > positions;
    //virtual bool count_Dif_Pos_Ok(Piece &piece, Case &c);
    //virtual void recordMove(Plateau &plateau, Piece &piece, int x, int y);
    
public :
    R_Stratego();
    virtual int checkMove(Plateau &p, int x1, int y1, int x2, int y2, Joueur j_tour);
    virtual void move(Plateau &p, int x1, int y1, int x2, int y2);
    virtual int etatPartie(Plateau &p);
    virtual bool placePiece(Plateau &p, Piece &piece, int x, int y);
};
#endif /* Regles_hpp */
