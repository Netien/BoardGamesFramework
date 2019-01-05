//
//  Affichage.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 03/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Affichage.hpp"

void Affichage::demanderMouvement()
{
    std::cout << "Quel déplacement voulez vous faire ?, (format \"a1 b2\")" << std::endl;
}

void Affichage::demanderMouvement(Joueur& j)
{
    std::cout << "Quel déplacement voulez vous faire, " << j.getNom() << "? (format \"a1 b2\")" << std::endl;
}

void Affichage::demanderPlacement()
{
    std::cout << "Où voulez vous placer la piece ? (format \"a1\")" << std::endl;
}

void Affichage::demanderPlacement(Piece& p)
{
    std::cout << "ou voulez vous placer le pion, " << p.getJoueur().getNom() << " ?";
}

void Affichage::affichageErreurPlacement()
{
    std::cout << "vous ne pouvez pas placer le pion ici" << std::endl;
}
