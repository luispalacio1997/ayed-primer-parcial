#include "Validator.h"
#include <stack>
#include <iostream>

Validator::Validator(IDataSource* source) : dataSource(source) {}

bool Validator::validate() {
    std::stack<char> brackets; // Pila para validar llaves y corchetes
    char c;

    while ((c = dataSource->getNextChar()) != '\0') {
        if (c == '{' || c == '[') {
            brackets.push(c); // Abre llaves o corchetes
        } else if (c == '}' || c == ']') {
            if (brackets.empty() || 
                (c == '}' && brackets.top() != '{') || 
                (c == ']' && brackets.top() != '[')) {
                errors.push_back("Error: Cierre inesperado de " + std::string(1, c));
                return false;
            }
            brackets.pop(); // Cierra llaves o corchetes correctamente
        } else if (c == '"') {
            
            if (!validateKey()) {
                return false;
            }
        }
    }

    // Verifica si quedan llaves/corchetes abiertos
    if (!brackets.empty()) {
        errors.push_back("Error: Faltan cerrar llaves o corchetes.");
        return false;
    }

    return true;
}

bool Validator::validateKey() {

    char c;
    std::string key;
    while ((c = dataSource->getNextChar()) != '"' && c != '\0') {
        key += c;
    }
    if (c != '"') {
        errors.push_back("Error: Clave no terminada.");
        return false;
    }
    std::cout << "Clave válida: " << key << std::endl; 
    return true;
}

const std::vector<std::string>& Validator::getErrors() const {
    return errors;
}
