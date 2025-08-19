#include <iostream>

using namespace std;

int main()
{
    system("chcp 65001");
    system("cls");
    // Ejemplos de los tipos de variables más comunes en C++   
    int entero = 25;                // Números enteros
    float decimalCorto = 3.14f;     // Decimales de precisión simple
    double decimalLargo = 3.141592; // Decimales de mayor precisión
    char caracter = 'A';            // Un solo carácter
    bool logico = true;             // Valores lógicos: true (1) o false (0)
    string texto = "Hola C++";      // Cadenas de texto (requiere <string>)
    // Mostrar en pantalla los valores y tipos
    cout << "Tipos de variables en C++:" << endl;
    cout << "---------------------------------" << endl;
    cout << "int: " << entero << endl;
    cout << "float: " << decimalCorto << endl;
    cout << "double: " << decimalLargo << endl;
    cout << "char: " << caracter << endl;
    cout << "bool: " << logico << endl;
    cout << "string: " << texto << endl;
    
    return 0;
}