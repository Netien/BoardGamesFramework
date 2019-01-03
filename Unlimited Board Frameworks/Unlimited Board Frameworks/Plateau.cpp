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
    m_damier = new Case* [hauteur];
    for(int i = 0; i < hauteur; ++i)
    {
        m_damier[i] = new Case[largeur];
    }
    for(int i = 0; i<hauteur; ++i)
    {
        for(int j = 0; j<largeur; j++)
        {
            m_damier[i][j].setCoord(i, j);
        }
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

Plateau::~Plateau(){
    for(int i = 0; i < m_hauteur; ++i)
    {
        delete m_damier[i];
    }
    delete m_damier;
}

Case Plateau::getCase(int x, int y){ return m_damier[x][y]; };

Piece Plateau::getPiece(int p_id){ return m_listePieces[p_id]; }

void Plateau::move(int x1, int y1, int x2, int y2){
    Piece p = getCase(x1, y1).getPiece();
  	discard(p);
  	dispatch(p, x2, y2);
}

void Plateau::discard(Piece &p){
  	if(p.getX() != -1 && p.getY() != -1)
	  	getCase(p.getX(), p.getY() ).setPiece(NULL);
	  p.move(-1, -1);
}

void Plateau::dispatch(Piece &p, int x, int y){
		getCase(x, y).setPiece(&p);
		p.move(x, y);
}


