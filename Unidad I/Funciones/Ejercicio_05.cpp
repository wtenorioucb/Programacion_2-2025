#include <iostream>
using namespace std;

void sumarPorValor(int x);
void sumarPorReferencia(int &y);

int main()
{
    int a = 10, b = 10;

    cout << "Antes de sumarPorValor, a = " << a << endl;
    sumarPorValor(a);
    cout << "Despues de sumarPorValor, a = " << a << endl;

    cout << "\nAntes de sumarPorReferencia, b = " << b << endl;
    sumarPorReferencia(b);
    cout << "Despues de sumarPorReferencia, b = " << b << endl;

    return 0;
}

void sumarPorValor(int x)
{
    x = x + 5;
    cout << "[Dentro de sumarPorValor] x = " << x << endl;
}

void sumarPorReferencia(int &y)
{
    y = y + 5;
    cout << "[Dentro de sumarPorReferencia] y = " << y << endl;
}