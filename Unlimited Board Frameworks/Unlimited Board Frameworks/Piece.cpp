//
//  Piece.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 24/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Piece.hpp"

Piece::Piece(int type, int id, Joueur &j) : m_joueur(j), m_coordX(-1),	m_coordY(-1), m_type(type), p_id(id)
{}

void Piece::promotion(int n_type){ m_type = n_type; };

int Piece::getId(){ return p_id; };

int Piece::getX(){ return m_coordX; }

int Piece::getY(){ return m_coordY; }

Joueur Piece::getJoueur(){ return m_joueur; }

int Piece::getType(){ return m_type; }

void Piece::move(int x, int y){ m_coordX = x ; m_coordY = y ; }
