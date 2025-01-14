#include "FileReader.h"
#include <stdexcept>
#include <string>


FileReader::FileReader(const std::string &fileName) {   // Implementa el constructor de FileReader
    file.open(fileName);                                // Para abrir el archivo a leer
    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo: " + fileName);
    }
}


char FileReader::getNextChar() {    // Implementa el metodo getNextChar
    char c;                         // Para devolver el caracter leido
    if (file.get(c)) {
        return c;
    }
    return '\0';                    // Fin de lectura
}

FileReader::~FileReader() { file.close(); } // Se cierra el archivo al usar el destructor