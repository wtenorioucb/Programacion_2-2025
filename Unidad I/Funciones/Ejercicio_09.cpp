#include <iostream>
using namespace std;

int Funcion01(int a);
void Funcion02(int &c, int d);
int Funcion03(int &x, int y);

int main()
{
    int numero1, numero2, resultado;
    cout << "Ingrese el primer número: ";
    cin >> numero1;
    cout << "Ingrese el segundo número: ";
    cin >> numero2;

    resultado = Funcion03(numero1, numero2);

    cout << "\nValor final de la variable numero1: " << numero1 << endl;
    cout << "Valor final de la variable numero2: " << numero2 << endl;
    cout << "Valor final de la variable resultado: " << resultado << endl;

    return 0;
}

int Funcion01(int a)
{
    return a % 10;
}

void Funcion02(int &c, int d)
{
    c += d;
}

int Funcion03(int &x, int y)
{
    Funcion02(x, y);
    return Funcion01(y);
}