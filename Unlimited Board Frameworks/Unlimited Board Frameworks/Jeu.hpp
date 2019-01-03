//
//  Jeu.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 03/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Jeu_hpp
#define Jeu_hpp
#include "Regles.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "Case.hpp"
#include "Piece.hpp"
#include <stdio.h>

class Jeu{
    
protected :
    Plateau & m_plateau;
    Regles &  m_regles;
    vector<Joueur> & m_listJoueurs;
    
public :
    virtual void start()=0;
    Jeu(Plateau & p, Regles & r, vector<Joueur> & listJoueurs);
    
    
};


#endif /* Jeu_hpp */
