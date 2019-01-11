//
//  FileIO.hpp
//  Unlimited Board Frameworks
//
//  Created by Etienne Juan Gesta on 10/01/2019.
//  Copyright © 2019 Etienne & Paul-Simon ®. All rights reserved.
//

#ifndef FileWriter_hpp
#define FileWriter_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>

class FileIO
{
    private :
    std::string m_filepath;
    public :
    FileIO(std::string pathname);
    virtual void save(std::string s);
    //virtual void save_as(std::string s, std::string filename);
    virtual void wipe();
    bool isNotEmpty();
    bool doesExist();
    void init();
};


#endif /* FileWriter_hpp */


