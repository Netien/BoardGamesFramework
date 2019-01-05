//
//  Input_Taker.cpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 04/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#include "Input_Taker.hpp"


std::vector<std::string> Input_Taker::split(const std::string &text, char sep) {
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}//split(std::string chaine, char delimiteur)
//{
//    std::vector<std::string> elements;
//    std::stringstream ss(chaine);
//    std::string sousChaine;
//    
//    while (getline(ss, sousChaine, delimiteur))
//    {
//        elements.push_back(sousChaine);
//    }
//    return elements;
//}

std::vector<std::string> Input_Taker::recupererPlacement()
{
    std::string req;
    std::cin >> req;
    std::vector<std::string> res;
    res = Input_Taker::split(req, ' ');
    if (res.size()!=1)
    {
        throw Input_Exception("un seul mot demandé", "Erreur de format");
    }
    
    std::string mot = res[0];
    unsigned long l = mot.size();
    
    if (l<2 || l>3)
    {
        throw Input_Exception("mot de mauvaise longueur", "Erreur de format");
    }
    
    if (!isalpha(mot[0]))
    {
        throw Input_Exception("Premier caractere doit etre une lettre", "Erreur de format");
    }
    
    if (!isdigit((mot[1])))
    {
        throw Input_Exception("Deuxieme caractere doit etre un chiffre", "Erreur de format");
    }
    
    if (l == 3)
    {
        if (!isdigit((mot[2])))
        {
            throw Input_Exception("Troisieme caractere doit etre un chiffre", "Erreur de format");
        }
    }
    

    return res;

}



std::vector<std::string> Input_Taker::recupererMouvement()
{
    std::string req;
    getline (std::cin, req);
    std::vector<std::string> res = Input_Taker::split(req, ' ');
    
    //std::cout << "res est de longueur " << res.size() << std::endl;
    
    if (res.size()!=2)
    {
        throw Input_Exception("Deux mots demandés", "Erreur de format");
    }
    
    std::string mot1 = res[0];
    unsigned long l1 = mot1.size();
    
    std::string mot2 = res[1];
    unsigned long l2 = mot2.size();
        
        
    if (l1<2 || l1>3)
    {
        throw Input_Exception("mot 1 de mauvaise longueur", "Erreur de format");
    }
    
    if (l2<2 || l2>3)
    {
        throw Input_Exception("mot 2 de mauvaise longueur", "Erreur de format");
    }
    

    if (!isalpha(mot1[0]))
    {
        throw Input_Exception("Premier caractere du premier mot doit etre une lettre", "Erreur de format");
    }
    
    if (!isdigit((mot1[1])))
    {
        throw Input_Exception("Deuxieme caractere du premier mot doit etre un chiffre", "Erreur de format");
    }
    
    if (l1 == 3)
    {
        if (!isdigit((mot1[2])))
        {
            throw Input_Exception("Troisieme caractere du premier mot doit etre un chiffre", "Erreur de format");
        }
    }

    
    if (!isalpha(mot2[0]))
    {
        throw Input_Exception("Premier caractere du deuxieme mot doit etre une lettre", "Erreur de format");
    }
    
    if (!isdigit((mot2[1])))
    {
        throw Input_Exception("Deuxieme caractere du deuxieme mot doit etre un chiffre", "Erreur de format");
    }
    
    if (l2 == 3)
    {
        if (!isdigit((mot2[2])))
        {
            throw Input_Exception("Troisieme caractere du deuxieme mot doit etre un chiffre", "Erreur de format");
        }
    }

    return res;

}


