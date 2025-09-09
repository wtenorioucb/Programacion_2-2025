#include <iostream>
using namespace std;

int sumar(int a, int b);
double sumar(double a, double b);
int sumar(int a, int b, int c);

int main()
{
    cout << "Suma de enteros: " << sumar(3, 5) << endl;
    cout << "Suma de reales:  " << sumar(2.5, 4.1) << endl;
    cout << "Suma de tres enteros: " << sumar(1, 2, 3) << endl;
    return 0;
}

// Función para sumar dos enteros
int sumar(int a, int b)
{
    return a + b;
}

// Función para sumar dos números reales
double sumar(double a, double b)
{
    return a + b;
}

// Función para sumar tres enteros
int sumar(int a, int b, int c)
{
    return a + b + c;
}
