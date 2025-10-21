#include <iostream>

using namespace std;

int gcd(int m, int n);

int main()
{
    system("cls");
    cout << "Calculo del MCD (Maximo Comun Divisor)" << endl;
    cout << "--------------------------------------" << endl;
    int a, b;
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;
    cout << "El MCD de " << a << " y " << b << " es: " << gcd(a, b) << endl;
    return 0;
}

int gcd(int m, int n)
{
    if (n == 0)
        return m;
    else
        return gcd(n, m % n);
}
