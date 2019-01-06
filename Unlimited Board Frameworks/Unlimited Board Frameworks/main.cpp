//
//  main.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 24/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Joueur.hpp"
#include "Regles_Echecs.hpp"
#include "Plateau_Echecs.hpp"
#include "Afficheur_Echecs.hpp"
#include "Jeu_Echecs.hpp"
#include "Plateau_De_Stratego.hpp"
#include "R_Stratego.hpp"
#include "Afficheur_Stratego.hpp"
#include "Jeu_De_Stratego.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
//    Plateau_De_Stratego p{};
//    R_Stratego r{};
//    vector<Joueur> l_j{};
//    Afficheur_Stratego afS;
//    
//    Joueur b = Joueur("Bob");
//    Joueur v = Joueur("Alice");
//    cout << b.getId() << endl;
//    cout << v.getId() << endl;
//    l_j.push_back(b);
//    l_j.push_back(v);
//
//    Jeu_De_Stratego j{p, r, l_j, afS};
//    j.startTest();
    
    
    
    Plateau_Echecs p{};
    Regles_Echecs r{};
    vector<Joueur> l_j{};
    Afficheur_Echecs afS;
    
    Joueur b = Joueur("Bob");
    Joueur v = Joueur("Alice");
    cout << b.getId() << endl;
    cout << v.getId() << endl;
    l_j.push_back(b);
    l_j.push_back(v);
    
    Jeu_Echecs j{p, r, l_j, afS};
    j.start();
    
    return 0;

}
