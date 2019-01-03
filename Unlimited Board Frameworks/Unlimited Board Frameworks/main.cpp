//
//  main.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 24/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Plateau_De_Stratego.hpp"
#include "Afficheur_Stratego.hpp"
#include "R_Stratego.hpp"
#include "Jeu_De_Stratego.hpp"



int main(int argc, const char * argv[]) {
    
    Plateau_De_Stratego p;
    R_Stratego rS;
    std::vector<Joueur> jList{};
    jList.push_back(Joueur("Michel", 0));
    jList.push_back(Joueur("Paul", 1));
    Afficheur_Stratego afS;
    Jeu_De_Stratego j(p, rS, jList, afS);
    
    j.start();
    
    
                
    
    
    return 0;
}
