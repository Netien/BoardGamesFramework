//
//  Input_Exception.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 04/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef Input_Exception_hpp
#define Input_Exception_hpp

#include <stdio.h>
#include <string>

#include <exception>

class Input_Exception: public std::exception
{
    
private:
    std::string m_type;               //Type de l'erreur
    std::string m_phrase;            //Description de l'erreur
public:
    Input_Exception(std::string phrase="Une erreur d'entree a eu lieu", std::string type= "Erreur d'input") throw()
    :m_type(type),m_phrase(phrase)
    {}
    
    virtual const char* what() const throw()
    {
        return (m_type + " : " + m_phrase).c_str();
    }
    
    std::string getType() const throw()
    {
        return m_type;
    }
    
    virtual ~Input_Exception() throw()
    {}
    

    
};
#endif /* Input_Exception_hpp */
