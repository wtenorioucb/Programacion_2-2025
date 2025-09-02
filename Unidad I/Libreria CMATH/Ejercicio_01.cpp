#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double numero = 0;
    double raiz_cuadrada = 0;
    // Validar que el numero sea mayor que cero
    do
    {
        system("cls");
        cout << "Ingrese un numero entero: ";
        cin >> numero;
        if (numero <= 0)
        {
            cout << "El numero debe ser mayor que cero. Intente nuevamente." << endl;
            system("pause");
        }
    } while (numero <= 0);
    raiz_cuadrada = sqrt(numero);
    cout << "La raiz cuadrada de " << numero << " es: " << raiz_cuadrada << endl;
    return 0;
}