//
//  Afficheur_Echecs.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 05/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Afficheur_Echecs_hpp
#define Afficheur_Echecs_hpp

#include <stdio.h>
#include "Affichage.hpp"


class Afficheur_Echecs : public Affichage
{
    public :
    void affichageTotal(Plateau & p);
    void affichagePartiel(Plateau & p, Joueur j);
    void affichageBienvenue();
    //void demanderPlacement(Piece& p);
    static std::string quelType(int i);
    //static void annoncerCombat(Piece & p1, Piece & p2);
    static void annoncerVictoire(Piece & p);
    static void annoncerMatchNul();
    static void annoncerEchecs();
    static void toujoursEnEchecs();
    static void vousMetEnEchec();
    static void annonceEchecEtMat(Joueur j);
    static void demanderPromotion();
};


#endif /* Afficheur_Echecs_hpp */
