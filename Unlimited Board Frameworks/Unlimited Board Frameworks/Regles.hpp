
//
//  Regles.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 25/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Regles_hpp
#define Regles_hpp

#include <stdio.h>
#include "Plateau.hpp"
#include "Piece.hpp"
#include "Move_Exception.hpp"

class Regles
{
protected :
    //Toutes ces methodes peuvent lancer une Move_Exception,
    //et permettent facilement aux classes filles de vérifier les mouvements de leurs pieces.
    void checkOutOfBounds(Plateau& plateau, int x, int y);//Sortie du plateau
    void checkOrthogonal(int x1, int y1, int x2, int y2);//Verif si déplacement est bien orthogonal
    void checkDiagonal(int x1, int y1, int x2, int y2);//Verif si déplacement est bien diagonal
    void checkNonOrthogonal(int x1, int y1, int x2, int y2);//Verif si déplacement pas orthogonal
    void checkNonDiagonal(int x1, int y1, int x2, int y2);//Verif si déplacement pas diagonal
    void checkDiagoOrthogonal(int x1, int y1, int x2, int y2);//Déplacement orthogonal ou diagonal
    void checkDidntMove(int x1, int y1, int x2, int y2);//Case de départ et d'arrivee identique
    void checkStartingBoxEmpty(Plateau& plateau, int x1, int y1);//Case de depart vide
    void checkOwner(Plateau& plateau, Joueur& j_tour, int x, int y);//Joueur en cours pas proprietaire de la piece
    void checkMove1Box(int x1, int y1, int x2, int y2);//Déplacement de seulement une case
    void checkUpward(int x1, int y1, int x2, int y2);//Déplacement vers le haut (latéral exclu)
    void checkDownward(int x1, int y1, int x2, int y2);//Déplacement vers le bas (latéral exclu)
    void checkDistanceFromStartLessThanN(int n, int x1, int y1, int x2, int y2);//Deplacement a moins de n cases de distance
    void checkDistanceFromStartExactlyN(int n, int x1, int y1, int x2, int y2);//Deplacement a exactement cases de distance
    virtual void checkPath(Plateau& plateau, Joueur& j_tour, int x1, int y1, int x2, int y2);//Chemin libre
    bool isDiagoOrthogonal(int x1, int y1, int x2, int y2);//Déplacement orthogonal ou diagonal (version booleenne)
    
public :
    virtual int checkMove(Plateau &p, int x1, int y1, int x2, int y2, Joueur& j_tour) = 0;
    virtual void move(Plateau &p, int x1, int y1, int x2, int y2) = 0;
    virtual int etatPartie(Plateau &p) = 0;
    virtual bool placePiece(Plateau &p, Piece &piece, int x, int y) = 0;
    virtual bool isAccessible(Piece& p, Plateau& plat, int x, int y)=0;//Permet de vérifier si la case de coordonées x, y est accessible par la piece p
};
#endif /* Regles_hpp */
