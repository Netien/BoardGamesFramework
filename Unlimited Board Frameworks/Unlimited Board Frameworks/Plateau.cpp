//
//  Plateau.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 25/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Plateau.hpp"

using namespace std;



Plateau::Plateau(const int largeur, const int hauteur) : m_largeur(largeur), m_hauteur(hauteur) {
    int x = 0;
    int y = 0;
    m_damier = vector<vector<Case> >(largeur);
    while(x < largeur){
        m_damier.at(x) = std::vector<Case>(hauteur);
        y = 0;
        while(y < hauteur){
            m_damier.at(x).at(y).setCoord(x, y);
            y++;
        }
        x++;
    }
}

bool Plateau::contains(int x, int y)
{
    if (x < 0 || x >= m_largeur)
        return false;
    
    if (y<0 || y>=m_hauteur)
        return false;
    
    return true;
}

int Plateau::getHauteur()
{
    return m_hauteur;
}

int Plateau::getLargeur()
{
    return m_largeur;
}

Case& Plateau::getCase(int x, int y){ return m_damier[x][y]; };

Piece& Plateau::getPiece(int p_id){ return m_listePieces[p_id]; }

const unsigned long Plateau::getLongListePieces() const
{
    return m_listePieces.size();
}

void Plateau::move(int x1, int y1, int x2, int y2){
    Piece &p = getCase(x1, y1).getPiece();
    discard(x1, y1);
    dispatch(p, x2, y2);
}

void Plateau::discard(int x, int y){
    if(not getCase(x, y).isEmpty())
        getCase(x, y).getPiece().move(-1,-1);
    getCase(x, y).setPiece(Case::puit);
}

void Plateau::discard(Piece &p){
    int x = p.getX();
    int y = p.getY();
	
    if(x != -1 && y != -1)
        p.move(-1, -1);
    getCase(x, y).setPiece(Case::puit);
    
}

void Plateau::dispatch(Piece &p, int x, int y){
    if(not getCase(x, y).isEmpty())
        getCase(x, y).getPiece().move(-1,-1);
    getCase(x, y).setPiece(p);
    p.move(x, y);
}

void Plateau::ajoutPiece(Piece &piece){
    for (Piece p : m_listePieces)
    {
        if(p.getId()==piece.getId())
        {
            throw runtime_error("piece deja presente dans plateau");
        }
            
    }
    m_listePieces.push_back(piece);
}

int Plateau::nbPieces(){
    return m_listePieces.size();
}
