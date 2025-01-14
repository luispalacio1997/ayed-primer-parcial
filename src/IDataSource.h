#ifndef IDATASOURCE_H
#define IDATASOURCE_H


class IDataSource {
public:
    virtual char getNextChar() = 0; // Metodo para la lectura de caracteres
    virtual ~IDataSource() {}    
};


#endif