#include <iostream>

int main() {
    // \033[ es el inicio del escape
    // 31m indica texto rojo
    // 0m indica resetear al color por defecto

    // Color,Color de Texto,Color de Fondo
    // Resetear todo,\033[0m,-
    // Negro,\033[30m,\033[40m
    // Rojo,\033[31m,\033[41m
    // Verde,\033[32m,\033[42m
    // Amarillo,\033[33m,\033[43m
    // Azul,\033[34m,\033[44m
    // Magenta,\033[35m,\033[45m
    // Cian,\033[36m,\033[46m
    // Blanco,\033[37m,\033[47m

    std::cout << "\033[31m" << "Este texto es rojo." << "\033[0m" << std::endl;
    std::cout << "\033[32m" << "Este texto es verde." << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\033[43m" << "Texto azul sobre fondo amarillo." << "\033[0m" << std::endl;
    std::cout << "Este texto vuelve a la normalidad." << std::endl;

    return 0;
}