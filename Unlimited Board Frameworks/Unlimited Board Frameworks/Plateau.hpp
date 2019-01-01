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
    std::vector<std::vector<Case>> m_damier;
    std::vector<Piece> m_listePieces;
public :
    Plateau(int largeur, int hauteur);
    ~Plateau();
    virtual void remplirPlateau();
    virtual Case getCase(int x, int y);
    virtual void move(int x1, int y1, int x2, int y2);
    virtual void discard(const Piece &p);
    friend class Regles;
};




#endif /* plateau_hpp */
