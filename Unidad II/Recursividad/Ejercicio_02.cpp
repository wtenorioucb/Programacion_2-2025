#include <iostream>

using namespace std;

int SerieFibonacci(int n);

int main()
{
    int n;
    system("cls");
    cout << "Calculo del n-esimo termino de la Serie de Fibonacci" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    cout << "El " << n << "-esimo termino de la Serie de Fibonacci es: " << SerieFibonacci(n) << endl;
    return 0;
}

int SerieFibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return SerieFibonacci(n - 1) + SerieFibonacci(n - 2);
}