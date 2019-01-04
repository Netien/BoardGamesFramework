#ifndef Move_Exception_hpp
#define Move_Exception_hpp

#include <string>
#include <exception>

class Move_Exception : public std::exception
{
private:
    int numero;
    std::string msg;
    
public:
    Move_Exception(int type);
    virtual ~Move_Exception() throw();
    virtual const char* what();
    
};

#endif
