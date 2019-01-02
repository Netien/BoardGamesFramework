//
//  plateau.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 25/12/2018.
//  Copyright © 2018 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Plateau_hpp
#define Plateau_hpp

#include <vector>
#include "Case.hpp"
#include "Piece.hpp"

class Plateau {
    
private :
    int m_largeur;
    int m_hauteur;
    std::vector<std::vector<Case>> m_damier;
    std::vector<Piece> m_listePieces;
public :
    Plateau(int largeur, int hauteur);
    Case getCase(int x, int y){ return m_damier[x][y]; };
    Piece getPiece(int p_id){ return m_listePieces[p_id]; };
    
    void move(int x1, int y1, int x2, int y2){
	    Piece p = getCase(x1, y1).getPiece();
    	discard(p);
    	dispatch(p, x2, y2);
    	
    }
    
    void discard(Piece &p){
    	if(p.getX() != -1 && p.getY() != -1)
    		getCase(p.getX(), p.getY() ).setPiece(NULL);
  		p.move(-1, -1);
    }
    
    void dispatch(Piece &p, int x, int y){
    	getCase(x, y).setPiece(&p);
    	p.move(x, y);
    }
    
    friend class Regles;
};

#endif /* plateau_hpp */
