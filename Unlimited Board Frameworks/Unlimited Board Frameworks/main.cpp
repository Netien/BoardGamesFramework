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
#include "R_Stratego.hpp"
#include "Plateau_De_Stratego.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Plateau_De_Stratego p{};
    R_Stratego r{};
    vector<Joueur> l_j{};

    Joueur b = Joueur("Bob");
    Joueur v = Joueur("Alice");
    std::cout << b.getId() << endl;
    std::cout << b.getId() << endl;
    /*l_j.push_back(b);
    l_j.push_back(v);

    Piece p1 = Piece(2, 0, b);
    Piece p2 = Piece(11, 1, b);
    Piece p3 = Piece(3, 2, b);
    Piece q1 = Piece(0, 3, b);
    Piece q2 = Piece(5, 4, b);
    Piece q3 = Piece(10, 1, b);

    std::cout << r.(p1, 2, 3) << endl;
    std::cout << r.(p1, 5, 9) << endl;
    return 0; */
}
