// El operador ternario en C++ es un atajo para escribir un if–else compacto en una sola línea.
// Se llama “ternario” porque necesita tres partes:
// condición ? valor_si_verdadero : valor_si_falso
// condición: se evalúa a true o false.
// Si es true, el resultado de toda la expresión será valor_si_verdadero.
// Si es false, será valor_si_falso.

#include <iostream>

using namespace std;

int MayorSinIF(int num1, int num2);
int MayorConIF(int num1, int num2);

int main()
{
    int x = 0;
    int y = 0;
    system("cls");
    cout << "Ingrese un número: ";
    cin >> x;
    cout << "Ingrese otro número: ";
    cin >> y;
    cout << "El numero mayor sin IF es: " << MayorSinIF(x,y) << endl;
    cout << "El numero mayor con IF es: " << MayorConIF(x,y) << endl;
    return 0;
}

int MayorSinIF(int num1, int num2)
{
    int mayor = 0;
    mayor = (num1 > num2) ? num1 : num2;
    return mayor;
}

int MayorConIF(int num1, int num2)
{
    int mayor = 0;
    if (num1 > num2)
    {
        mayor = num1;
    }
    else
    {
        mayor = num2;
    }    
    return mayor;
}
