#include <cstdlib>
#include <vector>
#include "R_Stratego.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "Case.hpp"
#include "Piece.hpp"


using namespace std;

bool R_Stratego::count_Dif_Pos_Ok(Piece &piece, Case &c){
    int id = piece.getId();
    int idx = 1;
    while(idx < 5){
	if(c == positions.at(id).at(idx) ||
	   positions.at(id).at(0) == positions.at(id).at(id) ||
	   positions.at(id).at(idx) != Case() )
	    return false;
	idx++;
    }
    return true;
};

void R_Stratego::recordMove(Plateau &plateau, Piece &piece, int x, int y){
    int idx = 3;
    int id = piece.getId();
    while(idx > 0){
	positions.at(id).at(idx) = positions.at(id).at(idx-1);
	idx--;
    }
    positions.at(id).at(idx) = plateau.getCase(x, y);
};
  
R_Stratego::R_Stratego() :
    positions(vector<vector<Case> >(80, vector<Case>(4, Case()) ) )
{};
  
/* Relation valeur-identite (pieces):
 * 11 = Bombe
 * 10 = Marechal
 * 9 = General
 * 8 = Colonel
 * 7 = Commandant
 * 6 = Capitaine
 * 5 = Lieutenant
 * 4 = Sergeant
 * 3 = Demineur
 * 2 = Eclaireur
 * 1 = Espion
 * 0 = Drapeau
 */

/* Relation valeur-identite (cases) :
 * 1 - Lac (impraticable)
 * 0 - Terre (libre)
 */

/* Retourne 0 si le mouvement est valide.
 * Retourne une autre valeur si le mouvement est interdit.
 */
int R_Stratego::checkMove(Plateau &plateau, int x1, int y1, int x2, int y2, Joueur j_tour){
    Case c;
    int type_m;
    int i;
    int j;
    //Sortie du plateau
    if( not (plateau.contains(x1, y1))){
	return 1;
    }

    if ( not (plateau.contains(x2, y2))){
	return 1;
    }
    
 
    //Déplacement non orthogonal
    if(x1 != x2 && y1 != y2)
	return 2;
    //Mouvement sur la meme case
    if(x1 == x2 && y1 == y2)
	return 3;
    //Case de depart vide
    c = plateau.getCase(x1, y1);
    if(c.isEmpty())
	return 4;
    //Piece n'appartient pas au joueur courant
    Piece piece = c.getPiece();
    if(j_tour.getId() != piece.getJoueur().getId())
	return 10;
    type_m = piece.getType();
    //Piece ne peut pas bouger
    if(type_m == 0 || type_m == 11 )
	return 5;
    //On passe sur les 2 memes case pendant 5 coups
    if(!count_Dif_Pos_Ok(piece, c))
	return 11;
    //distance de + d'une case interdit 
    if(type_m != 2 && abs(x1-x2+y1-y2) != 1)
	return 6;
    i = x2;
    j = y2;
    while(i != x1 || j != y1){
	c = plateau.getCase(i, j);
	//Case inutiliable
	if(c.getCouleur() == 1)
	    return 7;
	//Case d'arrivée occupée par piece du joueur actif
	if(i == x2 && j == y2){
	    if(!c.isEmpty())
	    {
		if(j_tour.getId() == piece.getJoueur().getId())
		{
		    return 8;
		}
	    }
	}
	//Case intermediaire non-vide
	if( not c.isEmpty())
	    return 9;
      
	//incrémentation/décrémentation adaptée
	if(i > x1)
	    i--;
	else if(i < x1)
	    i++;
	if(j > y1)
	    j--;
	else if(j < y1)
	    j++;
    }
    return 0;
};

void R_Stratego::move(Plateau &plateau, int x1, int y1, int x2, int y2){
    Piece p1 = plateau.getCase(x1, y1).getPiece();
    int t1;
    int t2;
    if(plateau.getCase(x2, y2).isEmpty()){
	plateau.move(x1, y1, x2, y2);
	recordMove(plateau, p1, x2, y2);
    }
    else{
	Piece p2 = plateau.getCase(x2, y2).getPiece();
	t1 = p1.getType();
	t2 = p2.getType();
	if((t1 == 1 && t2 == 10)||(t1 == 3 && t2 == 11)||(t1 > t2)){
	    plateau.discard(p2);
	    plateau.move(x1, y1, x2, y2);
	    recordMove(plateau, p1, x2, y2);
	}
	else if(t2 > t1){
	    plateau.discard(p1);
	}
	else{
	    plateau.discard(p1);
	    plateau.discard(p2);
	}
    }
};

int R_Stratego::etatPartie(Plateau &plateau){
    bool bFlag = false;
    bool rFlag = false;
    bool bCanPlay = false;
    bool rCanPlay = false;
    int idx = 0;
    while(idx < 80 && not (rFlag && bFlag && bCanPlay && rCanPlay) ){
	Piece piece = plateau.getPiece(idx);
	if(piece.getType() == 0){
	    if(piece.getJoueur().getId() == 0)
		bFlag = true;
	    else
		rFlag = true;
	}
	else if(piece.getType() != 11 && not (rCanPlay && bCanPlay)){
	    if(piece.getJoueur().getId() == 0)
		bCanPlay = true;
	    else
		rCanPlay = true;
	}
	idx++;
    }
  
    
    //Si le bleu s'est fait capturer son drapeau (victoire des rouges).
    if(!bFlag) return 1;
    //Si le rouge s'est fait capturer son drapeau (victoire des bleu).
    else if(!rFlag) return 2;
    //Si le rouge ET le bleu ne peuvent jouer (égalité).
    else if(!bCanPlay && !rCanPlay) return 3;
    //Si le bleu ne peut plus jouer (victoire des rouges).
    else if(!bCanPlay) return 4;
    //Si le rouge ne peut plus jouer (victoire des bleu).
    else if(!rCanPlay) return 5;
    //Sinon
    else return 0;
}

bool R_Stratego::placePiece(Plateau &plateau, Piece &piece, int x, int y)
{
    if(not plateau.contains(x, y))
	return false;
    
    if(piece.getJoueur().getId() == 0)
    {
	if(y>=4){
	    return false;
	}
    }

    if(piece.getJoueur().getId() == 1)
    {
	if(y<=6){
	    return false;
	}
    }

  
    if( not (plateau.getCase(x, y).isEmpty()) )
	return false;
    
    plateau.dispatch(piece, x, y);
    plateau.addPiece(piece);
    
    return true;
}
