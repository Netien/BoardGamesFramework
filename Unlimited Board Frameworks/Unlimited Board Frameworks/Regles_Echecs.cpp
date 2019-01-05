//
//  R_Echecs.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 05/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Regles_Echecs.hpp"

Regles_Echecs::Regles_Echecs()
{
    
}

int Regles_Echecs::checkMove(Plateau &p, int x1, int y1, int x2, int y2, Joueur j_tour)
{
    //TODO
    return 0;
}

void Regles_Echecs::move(Plateau &p, int x1, int y1, int x2, int y2)
{
    //TODO
}

int Regles_Echecs::etatPartie(Plateau &p)
{
    //TODO
    return 0;
}


bool Regles_Echecs::placePiece(Plateau &plateau, Piece &piece, int x, int y)
{
    if(not plateau.contains(x, y)){
        
        return false;
    }
    
    
    if(piece.getJoueur().getId() == 0)
    {
        if(y>=2){
            //cout << "la" << endl;
            return false;
        }
    }
    
    if(piece.getJoueur().getId() == 1)
    {
        if(y<6){
            
            return false;
        }
    }
    
    
    if( not (plateau.getCase(x, y).isEmpty()) )
    {
        
        return false;
    }
    
    plateau.dispatch(&piece, x, y);
    
    
    return true;
}
