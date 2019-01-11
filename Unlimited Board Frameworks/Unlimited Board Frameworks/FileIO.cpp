//
//  FileIO.cpp
//  Unlimited Board Frameworks


#include "FileIO.hpp"

using namespace std;


FileIO::FileIO(std::string pathname) : m_filepath(pathname)
{}

void FileIO::wipe()
{
    ofstream file(m_filepath, ios::out | ios::trunc);
    file.close();
}

void FileIO::init()
{
    ofstream file(m_filepath, ios::out);
    file.close();
}


void FileIO::save(std::string s)
{
    ofstream file(m_filepath, ios::out | ios::app);
    
    if(file)
    {
        cout << "On est censé écrire " << s << " dans " << m_filepath << endl;
        
        file << s.c_str() << endl;
        
        file.close();
    }
    
    else  // sinon
    {
        cerr << "Erreur d'ouverture de " << m_filepath << endl;
    }
    
}

bool FileIO::isNotEmpty()
{
    ifstream file(m_filepath, ios::out | ios::app);
    
    bool isIt = file.peek() == std::ifstream::traits_type::eof();
    
    file.close();
    
    return isIt;
}

bool FileIO::doesExist() {
    ifstream file(m_filepath);
    return file.good();
}
