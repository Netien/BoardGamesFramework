//
//  plateau.hpp
//  Unlimited Board Frameworks


#ifndef Plateau_hpp
#define Plateau_hpp

#include <vector>
#include <stdexcept>
#include "Case.hpp"
#include "Piece.hpp"

class Plateau {
    
protected :
    int const m_largeur;
    int const m_hauteur;
    std::vector<std::vector<Case> > m_damier;
    std::vector<Piece> m_listePieces;
    
public :
    
    Plateau(int largeur, int hauteur);
    Case& getCase(int x, int y);
    Piece& getPiece(int p_id);
    const unsigned long getLongListePieces() const;
    virtual bool contains(int x, int y); //Vérifie si case est dans le plateau
    void ajoutPiece(Piece& p);
    
    int getHauteur();
    int getLargeur();

    void move(int x1, int y1, int x2, int y2);
    void discard(int x, int y);
    void discard(Piece& p);
    void dispatch(Piece& p, int x, int y);
    void addPiece(Piece &piece);
    int nbPieces();
    
    friend class Regles;
};

#endif /* plateau_hpp */
