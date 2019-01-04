//
//  Jeu_De_Stratego.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 03/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Jeu_De_Stratego_hpp
#define Jeu_De_Stratego_hpp

#include "Jeu.hpp"
#include "Plateau_De_Stratego.hpp"
#include "R_Stratego.hpp"
#include "Afficheur_Stratego.hpp"

class Jeu_De_Stratego : public Jeu {
    
public :
    Jeu_De_Stratego( Plateau_De_Stratego &p, R_Stratego &r, vector<Joueur> &v, Afficheur_Stratego &a);
    void start();
};

#endif /* Jeu_De_Stratego_hpp */
