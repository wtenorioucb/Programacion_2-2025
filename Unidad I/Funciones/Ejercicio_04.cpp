#include <iostream>

using namespace std;

void MostrarDobleNumero(int numero);

int main()
{
    int numero = 0;
    system("chcp 65001");
    system("cls");
    cout << "Ingrese un número: ";
    cin >> numero;
    MostrarDobleNumero(numero);
    return 0;
}

void MostrarDobleNumero(int numero)
{
    cout << "El doble del número es: " << numero * 2 << endl;
}

