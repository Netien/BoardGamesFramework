//
//  plateau.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 25/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Plateau_hpp
#define Plateau_hpp

#include <vector>
#include "Case.hpp"
#include "Piece.hpp"

class Plateau {
private :
    int m_largeur;
    int m_hauteur;
    Case **m_damier;
    std::vector<Piece> m_listePieces;
public :
    Plateau(int largeur, int hauteur);
    virtual ~Plateau();
    Case getCase(int x, int y);
    Piece getPiece(int p_id);
    
    void move(int x1, int y1, int x2, int y2);
    void discard(Piece &p);
    void dispatch(Piece &p, int x, int y);
    
    friend class Regles;
};

#endif /* plateau_hpp */
