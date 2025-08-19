#include <iostream>
using namespace std;

int main()
{
    int numero;
    system("chcp 65001");
    system("cls");
    cout << "Ingrese un numero entero: ";
    cin >> numero;
    // Estructura if
    if (numero > 0) {
        cout << "El numero es positivo." << endl;
    }
    else if (numero < 0) {
        cout << "El numero es negativo." << endl;
    }
    else {
        cout << "El numero es cero." << endl;
    }
    return 0;
}