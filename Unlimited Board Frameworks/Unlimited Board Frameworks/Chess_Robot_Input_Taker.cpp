//
//  Chess_Robot_Input_Taker.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 10/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Chess_Robot_Input_Taker.hpp"

std::vector<std::string> Chess_Robot_Input_Taker::recupererMouvement()
{
    std::string req = "";
    std::vector<std::string> res;
    srand(time(NULL));
    
    
    
    int x1 = rand()%8;
    int y1 = rand()%8;
    int x2 = rand()%8;
    int y2 = rand()%8;
    
    req += (char)('a'+x1);
    req += std::to_string(y1+1);
    req += " ";
    req += (char)('a'+x2);
    req += std::to_string(y2+1);
    req += " ";
    
    res = Input_Taker::split(req, ' ');
    
    std::cout << "le bot essaye de jouer " << req << std::endl;
    
//    //std::cout << "res est de longueur " << res.size() << std::endl;
//    if (res.size()!=2)
//    {
//        throw Input_Exception("Deux mots demandés", "Erreur de format");
//    }
//    
//    std::string mot1 = res[0];
//    unsigned long l1 = mot1.size();
//    
//    std::string mot2 = res[1];
//    unsigned long l2 = mot2.size();
//    if (l1<2 || l1>3)
//    {
//        throw Input_Exception("mot 1 de mauvaise longueur", "Erreur de format");
//    }
//    
//    
//    if (l2<2 || l2>3)
//    {
//        throw Input_Exception("mot 2 de mauvaise longueur", "Erreur de format");
//    }
//    
//    
//    if (!isalpha(mot1[0]))
//    {
//        throw Input_Exception("Premier caractere du premier mot doit etre une lettre", "Erreur de format");
//    }
//    
//    if (!isdigit(mot1[1]))
//    {
//        throw Input_Exception("Deuxieme caractere du premier mot doit etre un chiffre", "Erreur de format");
//    }
//    
//    if (l1 == 3)
//    {
//        if (!isdigit((mot1[2])))
//        {
//            throw Input_Exception("Troisieme caractere du premier mot doit etre un chiffre", "Erreur de format");
//        }
//    }
//    
//    
//    if (!isalpha(mot2[0]))
//    {
//        throw Input_Exception("Premier caractere du deuxieme mot doit etre une lettre", "Erreur de format");
//    }
//    
//    if (!isdigit((mot2[1])))
//    {
//        throw Input_Exception("Deuxieme caractere du deuxieme mot doit etre un chiffre", "Erreur de format");
//    }
//    
//    if (l2 == 3)
//    {
//        if (!isdigit((mot2[2])))
//        {
//            throw Input_Exception("Troisieme caractere du deuxieme mot doit etre un chiffre", "Erreur de format");
//        }
//    }
//    
    return res;
    
}
