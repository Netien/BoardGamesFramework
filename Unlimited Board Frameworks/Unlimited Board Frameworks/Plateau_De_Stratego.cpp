//
//  Plateau_De_Stratego.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 03/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Plateau_De_Stratego.hpp"


Plateau_De_Stratego::Plateau_De_Stratego() : Plateau(10, 10)
{
    //int type;
    
    for(int y = 4; y < 6; y++)
	{
	    for( int x = 2; x < 4; x++)
		{
		    getCase(x, y).setCouleur(1);
		}
        
	    for( int x = 6; x < 8; x++)
		{
		    getCase(x, y).setCouleur(1);
		}
	}

    /* for(int i = 0; i < 40; i++}{
	if(i = 1)
	    type = 1;
	if(i = 2)
	    type = 2;
	if(i = 10)
	    type = 3;
	if(i = 15)
	    type = 4;
	if(i = 19)
	    type = 5;
	if(i = 23)
	    type = 6;
	if(i = 27)
	    type = 7;
	if(i = 30)
	    type = 8;
	if(i = 32)
	    type = 9;
	if(i = 33)
	    type = 10;
	if(i = 34)
	    type = 11;

	listePiece.push_back(Piece(-1,-1,));
	} */
}

