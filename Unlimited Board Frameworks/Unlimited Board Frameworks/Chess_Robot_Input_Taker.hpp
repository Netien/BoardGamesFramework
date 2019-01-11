//
//  Chess_Robot_Input_Taker.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 10/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Chess_Robot_Input_Taker_hpp
#define Chess_Robot_Input_Taker_hpp

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Input_Taker.hpp"

class Chess_Robot_Input_Taker : public Input_Taker
{
public:
    std::vector<std::string> recupererMouvement();

    
    
    
};


#endif /* Chess_Robot_Input_Taker_hpp */
