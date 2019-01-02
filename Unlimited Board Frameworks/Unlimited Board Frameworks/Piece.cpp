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

