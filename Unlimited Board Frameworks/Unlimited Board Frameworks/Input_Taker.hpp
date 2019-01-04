//
//  Input_Taker.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 04/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Input_Taker_hpp
#define Input_Taker_hpp


#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <cctype>

#include "Input_Exception.hpp"

#endif /* Input_Taker_hpp */

class Input_Taker
{
public :
    static std::vector<std::string> split(std::string, char delimiteur);
    static std::vector<std::string> recupererPlacement();
    static std::vector<std::string> recupererMouvement();
};
