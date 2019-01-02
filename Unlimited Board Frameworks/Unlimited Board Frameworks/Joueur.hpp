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

class Joueur
{

private :
    std::string m_nom;
    int m_score;
    int const m_id;
    
public :
  Joueur(std::string nom, int id);
    int getId(){ return this->m_id; };
};


#endif /* Joueur_hpp */
