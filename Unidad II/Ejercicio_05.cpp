#include <iostream>

using namespace std;

int main() 
{
    int numeroprimo = 0;
    int promedio = 0;
    int contadorprimo = 0;
    int sumaprimo = 0;
    
    cout << "Ingrese un numero primo (ingrese 0 o negativo para terminar)" << endl;
    cin >> numeroprimo;
    
    while (numeroprimo > 0)
    {
        int contador = 0; 
        for (int i = 2; i < numeroprimo; i++)
        {
            if (numeroprimo % i == 0)
            {
                contador++;
            }
        }
        if (contador == 0) 
        {
            cout << "El numero es primo" << endl;
            contadorprimo++;
            sumaprimo += numeroprimo;
        }
        else
        {
            cout << "El numero no es primo" << endl;
        }
        cout << "Ingrese otro numero primo (ingrese 0 o negativo para terminar)" << endl;
        cin >> numeroprimo;
    }
    if (contadorprimo > 0)
    {
        promedio = sumaprimo / contadorprimo;
        cout << "El promedio de los numeros primos ingresados es: " << promedio << endl;
    }
    else
    {
        cout << "No se ingresaron numeros primos" << endl;
    }
    return 0;
}