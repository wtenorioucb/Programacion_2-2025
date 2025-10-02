#include <iostream>
#include <string>

using namespace std;

int main()
{
    string nombre;
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    cout << "Usando Insert: " << nombre.insert(1,"  ") << endl;
    cout << "Usando Erase: " << nombre.erase(1, 2) << endl;
    cout << "Usando Replace: " << nombre.replace(1,2,"RRRRR") << endl;
    cout << "Usando Find: " << nombre.find("R",0) << endl;
    cout << "Usando SubStr: " << nombre.substr(6,2) << endl;
    return 0;
}