//
//  R_Echecs.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 05/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Regles_Echecs_hpp
#define Regles_Echecs_hpp

#include "Regles.hpp"
#include "Plateau.hpp"
#include "Plateau_Echecs.hpp"

class Regles_Echecs : public Regles
{
protected :
    void checkPawnMovement(Plateau& plateau, Joueur& j, int x1, int y1, int x2, int y2);
    
public :
    Regles_Echecs();
    bool isChecked(Joueur& j, Plateau_Echecs& pE);//regarde si le joueur est en échec.
    bool isChecked(Joueur& j, Plateau_Echecs& pE, int xK, int yK);//regarde si le joueur est en échec, version avec directement les coordonnees du roi passees en parametre
    bool isChecked(Joueur& j, Plateau_Echecs& pE, Piece& p);//regarde si le joueur est en échec, et initialise la reference de piece a la piece qui le met en échec si il l'est.
    bool isCheckmated(Joueur& j, Plateau_Echecs& pE, Piece& ennemyPiece);

    virtual int checkMove(Plateau &p, int x1, int y1, int x2, int y2, Joueur& j_tour);
    virtual void move(Plateau &p, int x1, int y1, int x2, int y2);
    virtual int etatPartie(Plateau &p);
    virtual bool placePiece(Plateau &plateau, Piece &piece, int x, int y);
    virtual bool isAccessible(Piece& p, Plateau& plat, int x, int y);//Permet de vérifier si la case de coordonées x, y est accessible par la piece p
    bool isPromoted(int x, int y, Joueur& j, Plateau& p);
    
};

#endif /* Regles_Echecs_hpp */
