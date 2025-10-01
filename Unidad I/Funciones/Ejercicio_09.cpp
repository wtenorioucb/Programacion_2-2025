#include <iostream>
using namespace std;

int Funcion01(int a);
void Funcion02(int &c, int d);
int Funcion03(int &x, int y);

int main()
{
    system("cls");
    int numero1 = 125, numero2 = 39, resultado = 0;
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