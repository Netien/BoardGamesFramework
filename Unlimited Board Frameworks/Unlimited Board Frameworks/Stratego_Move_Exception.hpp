#ifndef Move_Exception_hpp
#define Move_Exception_hpp

#include <string>
#include <exception>

class Stratego_Move_Exception : public std::exception
{
private:
    int numero;
    std::string msg;
    
public:
    Stratego_Move_Exception(int type);
    virtual ~Stratego_Move_Exception() throw();
    virtual const char* what() const throw();
    
};

#endif
