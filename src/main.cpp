#include <iostream>
#include "FileReader.h"
#include "Validator.h"

int main() {
    try {
        FileReader reader("archivo_test.json");
        Validator validator(&reader);

        if (validator.validate()) {
            std::cout << "El archivo JSON-AYED es válido." << std::endl;
        } else {
            std::cerr << "Errores encontrados:" << std::endl;
            for (const auto& error : validator.getErrors()) {
                std::cerr << error << std::endl;
            }
        }
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n\nValidación finalizada." << std::endl;
    system("pause");
    return EXIT_SUCCESS;
}
