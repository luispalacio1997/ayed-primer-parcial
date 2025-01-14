#ifndef FILEREADER_H
#define FILEREADER_H


#include <fstream>
#include <string>
#include "IDataSource.h"


class FileReader : public IDataSource
{
private:
    std::ifstream file;                 // Flujo de entrada para leer el archivo

public:
    FileReader(const std::string& fileName); 
    char getNextChar() override;
    ~FileReader();
};


#endif