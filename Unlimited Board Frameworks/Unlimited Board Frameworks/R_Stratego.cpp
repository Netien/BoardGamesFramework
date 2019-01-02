#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include "Regles.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "Case.hpp"
#include "Piece.hpp"

class R_Stratego : public Regles{
private:
  Plateau *p;
  std::vector<std::vector<Case> > positions;

  bool count_Dif_Pos_Ok(Piece pi, Case c){
    int id = pi.getId();
    int idx = 1;
    while(idx < 5){
      if(c == positions[id][idx] ||
	 positions[id][0] == positions[id][idx] ||
	 positions[id][idx] != Case() )
	return false;
      idx++;
    }
    return true;
  };

  void recordMove(int x, int y, Piece pi){
    int idx = 3;
    int id = pi.getId();
    while(idx > 0){
      positions[id][idx] = positions[id][idx-1];
      idx--;
    }
    positions[id][idx] = p->getCase(x, y);
  };
  
public:
  R_Stratego(Plateau *board){
    p = board;
    positions = std::vector<std::vector<Case> >(80, std::vector<Case>(4, Case()) );
  };
  
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
  int checkMove(int x1, int y1, int x2, int y2, Joueur &j_tour){
    Case c;
    int type_m;
    int i;
    int j;
    //Sortie du plateau
    if(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
      return 1;
    if(x1 > 9 || y1 > 9 || x2 > 9 || y2 > 9)
      return 1;
    //Déplacement en diagonale
    if(x1 != x2 && y1 != y2)
      return 2;
    //Mouvement sur la meme case
    if(x1 == x2 && y1 == y2)
      return 3;
    //Case de depart vide
    c = p->getCase(x1, y1);
    if(c.isEmpty())
      return 4;
    //Piece n'appartient pas au joueur courant
    Piece pi = c.getPiece();
    if(j_tour.getId() != pi.getJoueur().getId())
      return 10;
    type_m = pi.getType();
    //Piece ne peut pas bouger
    if(type_m == 0 || type_m == 11 )
      return 5;
    if(!count_Dif_Pos_Ok(pi, c))
      return 11;
    //distance de + d'une case interdit 
    if(type_m != 2 && abs(x1-x2+y1-y2) != 1)
      return 6;
    i = x2;
    j = y2;
    while(i != x1 || j != y1){
      c = p->getCase(i, j);
      //Case inutiliable
      if(c.getCouleur() == 1)
	return 7;
      //Case d'arrivée occupée par piece du joueur actif
      if(i == x2 && j == y2){
        if(!c.isEmpty())
	  if(j_tour.getId() == pi.getJoueur().getId())
	    return 8;
      }
      //Case intermediaire non-vide
      if(!c.isEmpty())
	return 9;
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

  void move(int x1, int y1, int x2, int y2){
    Piece p1 = p->getCase(x1, y1).getPiece();
    int t1;
    int t2;
    if(p->getCase(x2, y2).isEmpty()){
      p->move(x1, y1, x2, y2);
      recordMove(x2, y2, p1);
    }
    else{
      Piece p2 = p->getCase(x2, y2).getPiece();
      t1 = p1.getType();
      t2 = p2.getType();
      if((t1 == 1 && t2 == 10)||(t1 == 3 && t2 == 11)||(t1 > t2)){
	p->discard(p2);
	p->move(x1, y1, x2, y2);
        recordMove(x2, y2, p1);
      }
      else if(t2 > t1){
	p->discard(p1);
	p->move(x2, y2, x1, y1);
      }
      else{
	p->discard(p1);
	p->discard(p2);
      }
    }
  };
  
  int etatPartie(){
    bool bFlag = false;
    bool rFlag = false;
    bool bCanPlay = false;
    bool rCanPlay = false;
    int idx = 0;
    while(idx < 80 && !rFlag && !bFlag && !bCanPlay && !rCanPlay){
      Piece pi = p->getPiece(idx);
      if(pi.getType() == 0){
	if(pi.getJoueur().getId() == 0)
	  bFlag = true;
	else
	  rFlag = true;
      }
      if(pi.getType() != 11 && !rCanPlay && !bCanPlay){
	if(pi.getJoueur().getId() == 0)
	  bCanPlay = true;
	else
	  rCanPlay = true;
      }
      idx++;
    }

    if(!bFlag) idx = 1;
    else if(!rFlag) idx = 2;
    else if(!bCanPlay) idx = 3;
    else if(!rCanPlay) idx = 4;
    else idx = 0;
    
    return idx;
  };

  bool placePiece(Piece &pi, int x, int y){
    if(x < 0 || y < 0 || x > 9 || y > 9)
      return false;
    if(!(p->getCase(x, y).isEmpty()) )
      return false;
    p->dispatch(pi, x, y);
    return true;
  }
  
};

