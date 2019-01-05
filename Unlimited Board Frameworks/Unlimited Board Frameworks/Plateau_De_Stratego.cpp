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

}
