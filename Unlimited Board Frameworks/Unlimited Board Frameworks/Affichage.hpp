//
//  Affichage.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 03/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Affichage_hpp
#define Affichage_hpp

#include "Plateau.hpp"

class Affichage
{
    public :
    virtual void affichageTotal(Plateau & p)=0;
    virtual void affichagePartiel(Plateau & p, Joueur j)=0;
    virtual void affichageBienvenue()=0;
    virtual void affichageErreurPlacement();

    virtual void demanderMouvement();
    virtual void demanderMouvement(Joueur& j);
    virtual void demanderPlacement();
    virtual void demanderPlacement(Piece& p);
    void demanderChargement();
    
};

#endif /* Affichage_hpp */
