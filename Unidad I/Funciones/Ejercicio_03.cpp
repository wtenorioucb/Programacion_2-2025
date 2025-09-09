#include <iostream>

using namespace std;

int Operacion(int n);
int Transformar(int n);
int ProcesoFinal(int a, int b);

int main()
{
    int x = 12, y = 7;
    int resultado = ProcesoFinal(x, y);
    cout << "Resultado final: " << resultado << endl;
    return 0;
}

int Operacion(int n)
{
    int suma = 0;
    while (n > 0)
    {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

int Transformar(int n)
{
    int paso1 = Operacion(n) + n;
    return paso1;
}

int ProcesoFinal(int a, int b)
{
    int t1 = Transformar(a);
    int t2 = Transformar(b);
    return (t1 + t2);
}