#ifndef Move_Exception_hpp
#define Move_Exception_hpp

#include <string>
#include <exception>

class Stratego_Move_Exception : public std::exception
{
private:
    std::string msg;//Description de l'erreur
    std::string m_type;//Type de l'erreur
public:
    Stratego_Move_Exception(std::string message);
    
    virtual ~Stratego_Move_Exception() throw();
    
    Stratego_Move_Exception(std::string phrase="Une erreur de déplacement a eu lieu", std::string type= "Erreur de déplacement") throw()
    :m_type(type),msg(phrase)
    {}
    
    virtual const char* what() const throw()
    {
        return (m_type + " : " + msg).c_str();
    }
    
    std::string getType() const throw()
    {
        return m_type;
    }
    
    
    
};

#endif
