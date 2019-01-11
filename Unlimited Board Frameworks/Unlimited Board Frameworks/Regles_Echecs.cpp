//
//  R_Echecs.cpp
//  Unlimited Board Frameworks


#include "Regles_Echecs.hpp"

Regles_Echecs::Regles_Echecs()
{
    
}

int Regles_Echecs::checkMove(Plateau& plateau, int x1, int y1, int x2, int y2, Joueur& j_tour)
{
    
    //Sortie du plateau
    checkOutOfBounds(plateau, x1, y1);
    checkOutOfBounds(plateau, x2, y2);
    
    
    //Mouvement sur la meme case
    checkDidntMove(x1, y1, x2, y2);
    
    //Case de depart vide
    checkStartingBoxEmpty(plateau, x1, y1);
    
    //Piece n'appartient pas au joueur courant
    checkOwner(plateau, j_tour, x1, y1);
    
    int type = plateau.getCase(x1, y1).getPiece().getType();
    
    if (type == 5)//Si c'est un roi
    {
        checkMove1Box(x1, y1, x2, y2);//il ne peut bouger que d'une case
    }
    else if (type == 4)//Si c'est une reine
    {
        checkDiagoOrthogonal(x1, y1, x2, y2);
    }
    else if (type == 3)//Si c'est une tour
    {
        checkOrthogonal(x1, y1, x2, y2);
    }
    
    else if (type == 2)//Si c'est un fou
    {
        checkDiagonal(x1, y1, x2, y2);
    }
    else if (type == 1)//Si c'est un cavalier
    {
        checkNonOrthogonal(x1, y1, x2, y2);//alors si il ne se dáplace pas orthogonalement
        checkNonDiagonal(x1, y1, x2, y2);//pas diagonalement
        checkDistanceFromStartLessThanN(2, x1, y1, x2, y2);//et pas a une distance de plus de 2 cases
        //c'est bon !
    }
    else if (type == 0)//Si c'est un pion (EN COURS)
    {
        
        checkPawnMovement(plateau, j_tour, x1, y1, x2, y2);

    }
    if(type != 1) //Si c'est autre chose qu'un cavalier
    {
        //On regarde si le chemin est libre
        checkPath(plateau, j_tour, x1, y1, x2, y2);
    }
    
    
    return 0;
}

void Regles_Echecs::move(Plateau& plateau, int x1, int y1, int x2, int y2)
{

    
    if(plateau.getCase(x2, y2).isEmpty())
    {
        plateau.move(x1, y1, x2, y2);
    }
    else
    {
        Piece& p = plateau.getCase(x2, y2).getPiece();
        plateau.discard(p);
        plateau.move(x1, y1, x2, y2);
    
	//recordMove(plateau, p1, x2, y2);
    }

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
        if(y<plateau.getHauteur()-2){
            
            return false;
        }
    }
    
    
    if( not (plateau.getCase(x, y).isEmpty()) )
    {
        
        return false;
    }
    
    plateau.dispatch(piece, x, y);
    
    
    return true;
}

bool Regles_Echecs::isPromoted(int x, int y, Joueur& j, Plateau& p)
{
    if(j.getId()==0 && p.getCase(x, y).getPiece().getType() == 0 && y == p.getHauteur()-1)
    {
        return true;
    }
    
    if(j.getId()==1 && p.getCase(x, y).getPiece().getType() == 0 && y == 0)
    {
        return true;
    }
    
    return false;
}

void Regles_Echecs::checkPawnMovement(Plateau& plateau, Joueur& j_tour, int x1, int y1, int x2, int y2)
{
    checkOutOfBounds(plateau, x1, y1);
    checkOutOfBounds(plateau, x2, y2);
    Case c = plateau.getCase(x1, y1);
    
    //
    
    if(j_tour.getId()==0)//Pour le joueur 1
    {
        if (x1==x2 and y2 == y1+1)//Si on essaye d'avancer d'une case tout droit
        {
        
            c = plateau.getCase(x1, y1+1);
            if(not(c.isEmpty()))//Si la case est occupée, peut importe par quelle piece, il ne peut avancer(pion ne peut manger en avançant).
            {
                throw Move_Exception("Case occupée, vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
            }
        }
        else if(x2 == x1 and y2 == y1+2)//Si on essaye d'avancer de 2 cases tout droit
        {
            c = plateau.getCase(x1, y1+2);
            if(not(c.isEmpty()))//Si la case est occupée, peut importe par quelle piece, il ne peut avancer(pion ne peut manger en avançant).
            {
                throw Move_Exception("Case occupée, vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
            }
            if(y1 != 1)//Si le pion n'est pas en position de départ, impossible.
            {
                throw Move_Exception("Ce pion ne peut plus avancer de 2 cases !", "Erreur de déplacement");
            }
            
        }

        else if(x2 == x1-1 and y2 == y1+1)//Si on essaye d'accéder à la case adjacente en diagonale gauche
        {
            if (plateau.contains(x1-1, x1-1))
            {
                c = plateau.getCase(x1-1, y1+1);
                if(c.isEmpty() or c.getPiece().getJoueur().getId()==j_tour.getId())//si la case est vide ou avec une piece a nous: impossible.
                {
                    throw Move_Exception("Vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
                }
            }
        }
        else if(x2 == x1+1 and y2 == y1+1)//Si on essaye d'accéder à la case adjacente en diagonale droite
        {
            if (plateau.contains(x1+1, x1+1))
            {
                c = plateau.getCase(x1+1, y1+1);
                if(c.isEmpty() or c.getPiece().getJoueur().getId()==j_tour.getId())//si la case est vide ou avec une piece a nous: impossible.
                {
                    throw Move_Exception("Vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
                }
            }
        }
        else
        {
            throw Move_Exception("Déplacement impossible pour un pion", "Erreur de déplacement");
        }
        
        
        
    }
    
    
    if(j_tour.getId()==1)//Pour le joueur 2
    {
        if (x1==x2 and y2 == y1-1 )//Si on essaye d'avancer d'une case tout droit
        {
            
            c = plateau.getCase(x1, y1-1);
            if(not(c.isEmpty()))//Si la case est occupée, peut importe par quelle piece, il ne peut avancer(pion ne peut manger en avançant).
            {
                throw Move_Exception("Case occupée, vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
            }
        }
        else if(x2 == x1 and y2 == y1-2)//Si on essaye d'avancer de 2 cases tout droit
        {
            c = plateau.getCase(x1, y1-2);
            if(not(c.isEmpty()))//Si la case est occupée, peut importe par quelle piece, il ne peut avancer(pion ne peut manger en avançant).
            {
                throw Move_Exception("Case occupée, vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
            }
            if(y1 != plateau.getHauteur()-2)//Si le pion n'est pas en position de départ, impossible.
            {
                throw Move_Exception("Ce pion ne peut plus avancer de 2 cases !", "Erreur de déplacement");
            }
            
        }
        
        else if(x2 == x1-1 and y2 == y1-1)//Si on essaye d'accéder à la case adjacente en diagonale gauche
        {
            if (plateau.contains(x1-1, y1-1))
            {
                c = plateau.getCase(x1-1, y1-1);
                if(c.isEmpty() or c.getPiece().getJoueur().getId()==j_tour.getId())//si la case est vide ou avec une piece a nous: impossible.
                {
                    throw Move_Exception("Vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
                }
            }
        }
        else if(x2 == x1+1 and y2 == y1-1)//Si on essaye d'accéder à la case adjacente en diagonale droite
        {
            if (plateau.contains(x1+1, y1-1))
            {
                c = plateau.getCase(x1+1, y1-1);
                if(c.isEmpty() or c.getPiece().getJoueur().getId()==j_tour.getId())//si la case est vide ou avec une piece a nous: impossible.
                {
                    throw Move_Exception("Vous ne pouvez aller sur cette case avec ce pion", "Erreur de déplacement");
                }
            }
        }
        else
        {
            throw Move_Exception("Déplacement impossible pour un pion", "Erreur de déplacement");
        }

    }
    
    
    
    
    
}


bool Regles_Echecs::isAccessible(Piece& p, Plateau& plat, int x, int y)//Permet de vérifier si la case de coordonées x, y est accessible par la piece p sur le plateau plat.
{
    
    int type = p.getType();
    
    try {
        //On regarde si le plateau contient la case d'arrivee
        checkOutOfBounds(plat, x, y);
        
        //Si ce n'est pas un cavalier, il faut déja vérifier que le chemin est libre
        if (type == 5)//Si c'est un roi
        {
            checkMove1Box(p.getX(), p.getY(), x, y);//il ne peut bouger que d'une case
        }
        else if (type == 4)//Si c'est une reine
        {
            checkDiagoOrthogonal(p.getX(), p.getY(), x, y);
        }
        else if (type == 3)//Si c'est une tour
        {
            checkOrthogonal(p.getX(), p.getY(), x, y);
        }
        
        else if (type == 2)//Si c'est un fou
        {
            checkDiagonal(p.getX(), p.getY(), x, y);
        }
        else if (type == 1)//Si c'est un cavalier
        {
            checkNonOrthogonal(p.getX(), p.getY(), x, y);//alors si il ne se dáplace pas orthogonalement
            checkNonDiagonal(p.getX(), p.getY(), x, y);//pas diagonalement
            checkDistanceFromStartLessThanN(2, p.getX(), p.getY(), x, y);//et pas a une distance de plus de 2 cases
            //c'est bon !
        }
        else if (type == 0)//Si c'est un pion
        {
            checkPawnMovement(plat, p.getJoueur(), p.getX(), p.getY(), x, y);
        }
        
        if (type != 1) {
            checkPath(plat, p.getJoueur(), p.getX(), p.getY(), x, y);
        }


        
        
    }
    catch(Move_Exception mE)
    {
        return false;
    }
    
    return true;
}


bool Regles_Echecs::isChecked(Joueur& j, Plateau_Echecs& pE)
{
    //std::cout <<" Coucou !" << std::endl;
    int xK = pE.getCoordKing(j)[0];
    int yK = pE.getCoordKing(j)[1];
    
    //std::cout <<"Le roi est bien en !" << xK << " " << yK  << std::endl;

    
    for (Piece& p : pE.m_listePieces)
    {
        //std::cout << "la piece de type" << p.getType() << " appartenant a " << p.getJoueur().getNom() << " a pour coordonnees x= " << p.getX() << " y= " <<p.getY() << std::endl;
        if(p.getJoueur().getId()!=j.getId() and p.getX()>-1)
        {
            if(isAccessible(p, pE, xK, yK))
            {
                std::cout << j.getNom() << " est en échec " << " par la piece de type " << p.getType() <<
                " appartenant a " << p.getJoueur().getNom() << " de coordonnees " << (char)('a'+p.getX()) << p.getY()+1 << std::endl;
                return true;
            }
        }
    }
    
    //std::cout << j.getNom() << " n'est pas en échec !" << std::endl;
    return false;
}


bool Regles_Echecs::isChecked(Joueur& j, Plateau_Echecs& pE, Piece& piece)//regarde si le joueur est en échec, et met la reference de piece a la piece qui le met en échec si il l'est.
{
    //std::cout <<" Coucou !" << std::endl;
    int xK = pE.getCoordKing(j)[0];
    int yK = pE.getCoordKing(j)[1];
    
    //std::cout <<"Le roi est bien en !" << xK << " " << yK  << std::endl;
    
    
    for (Piece& p : pE.m_listePieces)
    {
        //std::cout << "la piece de type" << p.getType() << " appartenant a " << p.getJoueur().getNom() << " a pour coordonnees x= " << p.getX() << " y= " <<p.getY() << std::endl;
        if(p.getJoueur().getId()!=j.getId() and p.getX()>-1)
        {
            if(isAccessible(p, pE, xK, yK))
            {
                std::cout << j.getNom() << " est en échec " << " par la piece de type " << p.getType() <<
                " appartenant a " << p.getJoueur().getNom() << " de coordonnees " << (char)('a'+p.getX()) << p.getY()+1 << std::endl;
                piece = p;
                
                return true;
            }
        }
    }
    
    //std::cout << j.getNom() << " n'est pas en échec !" << std::endl;
    return false;
}

bool Regles_Echecs::isChecked(Joueur& j, Plateau_Echecs& pE, int xK, int yK)//regarde si le joueur est en échec, version avec directement les coordonnees du roi passees en parametre
{
    
    for (Piece& p : pE.m_listePieces)
    {
        
        if(p.getJoueur().getId()!=j.getId() and p.getX()>-1)
        {
            if(isAccessible(p, pE, xK, yK))
            {
                std::cout << j.getNom() << " est en échec " << " par la piece de type " << p.getType() <<
                " appartenant a " << p.getJoueur().getNom() << " de coordonnees " << (char)('a'+p.getX()) << p.getY()+1 << std::endl;
              
                return true;
            }
        }
    }
    
    //std::cout << j.getNom() << " n'est pas en échec !" << std::endl;
    return false;
}





bool Regles_Echecs::isCheckmated(Joueur& j, Plateau_Echecs& pE, Piece& ennemyPiece)
{
    int x, y, xK, yK, xE, yE;
    
    xK = pE.getCoordKing(j)[0];
    yK = pE.getCoordKing(j)[1];
    
    xE = ennemyPiece.getX();
    yE = ennemyPiece.getY();
    
    //on trouve xK et yK avec getCoordKing
    if(ennemyPiece.getType()!=1)//Si la piece n'est pas un cavalier(dans ce cas on saute la vérification de chemin)
    {
        x = xE;
        y = yE;
        
        while(x !=xK || y != yK) //pour toutes les cases de coordonnees x, y du chemin de la piece ennemie au roy
        {
            std::cout << "On regarde si la case" << x << y << "est accessible" << std::endl;
            for(Piece& p : pE.m_listePieces)
            {
                //si on peut accéder a une de ces cases du chemin avec nos pieces(vivantes, et non le roi)
                if (p.getJoueur().getId()==j.getId() && p.getX()>-1 && p.getType()!=5)
                {
                    
                    if(isAccessible(p, pE, x, y))
                    {
                        std::cout << "Elles est accessible par la piece de type "<< p.getType() << std::endl;
                        
                        return false;//alors ce n'est pas un échec et mat.
                    }
                }
            }
            //incrémentation/décrémentation adaptée
            if(x > xK)
                x--;
            else if(x < xK)
                x++;
            if(y > yK)
                y--;
            else if(y < yK)
                y++;
        }
        
    }
    
    for(x=xK-1; x<=xK+1; ++x)
    {
        for (y=yK-1; y<=yK+1; ++y)
        { //on regarde toutes les cases autour du roy
            
            if (pE.contains(x, y) && (pE.getCase(x, y).isEmpty() || pE.getCase(x, y).getPiece().getJoueur().getId() != j.getId()))
                //si la case estoy sur le champs de bataille et est vide ou possede une piece a l'ennemy
            {
                std::cout << "Le roy tente vaillament la fuite par la case " << x << y << std::endl;
                if (not isChecked(j, pE, x, y))//et si le roi peut s'y déplacer sans être a nouveau en échec
                {
                    //alors on n'est pas en échec et mat
                    std::cout << "Et vit qu'il y sera en sécurité." << std::endl;
                    return false;
                }
            }
        }
    }
    //Si on a épuisé toutes les options, on est bien en échec et mat !
    return true;

}

int Regles_Echecs::etatPartie(Plateau& p)
{
    //TODO
    return 0;
}

