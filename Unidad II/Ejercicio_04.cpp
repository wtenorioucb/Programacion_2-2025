#include <iostream>
#include <string>

using namespace std;

int main()
{
    int edad = 0;
    string nombre = "";
    cout << "Ingrese su edad: ";
    cin >> edad;
    cin.ignore(); // Limpiar el buffer de entrada
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    cout << "Su nombre es: " << nombre << " y tiene " << edad << " años";
    return 0;
}