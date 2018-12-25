//
//  plateau.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 25/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef plateau_hpp
#define plateau_hpp

#include <vector>
#include "case.hpp"

class Plateau {
    
private :
    int m_largeur;
    int m_hauteur;
    Case ** m_damier;
    std::vector<Piece> m_listePieces;
public :
    Plateau(int largeur, int hauteur);
    ~Plateau();
    virtual void remplirPlateau();
    
    friend class Regles;
    
    
    
};




#endif /* plateau_hpp */
