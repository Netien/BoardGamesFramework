//
//  Jeu_Echecs.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 05/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Jeu_Echecs_hpp
#define Jeu_Echecs_hpp
#include <stdlib.h> 
#include <stdio.h>
#include "Jeu.hpp"
#include "Regles_Echecs.hpp"
#include "Afficheur_Echecs.hpp"
#include "Plateau_Echecs.hpp"
#include "Input_Taker.hpp"
#include "Chess_Robot_Input_Taker.hpp"
#include "Move_Exception.hpp"
#include "Quit_Exception.hpp"
#include "FileIO.hpp"

#endif /* Jeu_Echecs_hpp */

class Jeu_Echecs : public Jeu {
    
    private :
    
    
    public :
    Jeu_Echecs( Plateau_Echecs &p, Regles_Echecs &r, std::vector<Joueur> &v, Afficheur_Echecs &a);
    virtual void remplirListePieces() ;
    virtual void placerDansPlateau();
    virtual void start();
};
