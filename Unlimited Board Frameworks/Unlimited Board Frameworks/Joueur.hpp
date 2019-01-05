//
//  Joueur.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 24/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Joueur_hpp
#define Joueur_hpp

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

class Joueur{
private :
    std::string m_nom;
    int m_score;
    int m_id;
    static int id;
    
public :
    Joueur();
    Joueur(std::string nom);
    int getId();
    std::string getNom();
};


#endif /* Joueur_hpp */
