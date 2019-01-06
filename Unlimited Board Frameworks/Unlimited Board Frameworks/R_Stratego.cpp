#include <cstdlib>
#include <vector>
#include "R_Stratego.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "Case.hpp"
#include "Piece.hpp"
#include "Afficheur_Stratego.hpp"


using namespace std;



R_Stratego::R_Stratego()
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

    
    
    //Sortie du plateau
    checkOutOfBounds(plateau, x1, y1);
    checkOutOfBounds(plateau, x2, y2);
 
    //Déplacement non orthogonal
    checkOrthogonal(x1, y1, x2, y2);
    
    //Mouvement sur la meme case
    checkDidntMove(x1, y1, x2, y2);
    
    //Case de depart vide
    checkStartingBoxEmpty(plateau, x1, y1);
    
    //Piece n'appartient pas au joueur courant
    checkOwner(plateau, j_tour, x1, y1);
    
    //Essai de déplacer une piece par nature statique
    staticPiece(plateau, x1, y1);

    if(plateau.getCase(x1, y1).getPiece()->getType() != 2)//pour toute piece autre que l'éclaireur...
    {
        //distance de + d'une case interdit.
        checkMove1Box(x1, y1, x2, y2);
    }
    
    //chemin libre
    checkPath(plateau, j_tour, x1, y1, x2, y2);
    return 0;
};

void R_Stratego::move(Plateau &plateau, int x1, int y1, int x2, int y2){
    Piece *p1 = plateau.getCase(x1, y1).getPiece();
    int t1;
    int t2;
    
    if(plateau.getCase(x2, y2).isEmpty())
    {
        plateau.move(x1, y1, x2, y2);
    }
    else
    {
        Piece *p2 = plateau.getCase(x2, y2).getPiece();
        t1 = p1->getType();
        t2 = p2->getType();
        
        Afficheur_Stratego::annoncerCombat(*p1, *p2);
        
        if((t1 == 1 && t2 == 10)||(t1 == 3 && t2 == 11)||(t1 > t2)){
            plateau.discard(p2);
            plateau.move(x1, y1, x2, y2);
            Afficheur_Stratego::annoncerVictoire(*p1);
            //recordMove(plateau, p1, x2, y2);
        }
        else if(t2 > t1){
            plateau.discard(p1);
            Afficheur_Stratego::annoncerVictoire(*p2);
        }
        else{
            Afficheur_Stratego::annoncerMatchNul();
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
    int max = plateau.nbPieces();
    while(idx < max && not (rFlag && bFlag && bCanPlay && rCanPlay) ){
	Piece &piece = plateau.getPiece(idx);
	if(piece.getX() == -1 && piece.getY() == -1){}
        if(piece.getType() == 0){
	    if(piece.getJoueur().getId() == 0)
		bFlag = true;
	    else
		rFlag = true;
	}
	else if(piece.getType() != 11 /*&& not (rCanPlay && bCanPlay)*/){
	    if(piece.getJoueur().getId() == 0)
		bCanPlay = true;
	    else
		rCanPlay = true;
	}
	idx++;
    }
  
    
    //Si le rouge ET le bleu ne peuvent jouer (égalité).
    if(!bCanPlay && !rCanPlay)
	return 3;
    //Si le bleu ne peut plus jouer (victoire des rouges).
    else if(!bCanPlay) return 4;
    //Si le rouge ne peut plus jouer (victoire des bleu).
    else if(!rCanPlay) return 5;
    //Si le bleu s'est fait capturer son drapeau (victoire des rouges).
    else if(!bFlag) return 1;
    //Si le rouge s'est fait capturer son drapeau (victoire des bleu).
    else if(!rFlag) return 2;
    //Sinon
    else return 0;
}

bool R_Stratego::placePiece(Plateau &plateau, Piece &piece, int x, int y)
{
    if(not plateau.contains(x, y)){
        
        return false;
    }
    
    
    if(piece.getJoueur().getId() == 0)
    {
        if(y>=4){
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


void R_Stratego::staticPiece(Plateau &plateau, int x, int y)
{
    Case c = plateau.getCase(x, y);
    Piece piece = *c.getPiece();
    int type_m = piece.getType();
    //Piece ne peut pas bouger
    if(type_m == 0 || type_m == 11 )
        throw Move_Exception("Cette pièce est immobile de nature!", "Erreur de déplacement");
}
