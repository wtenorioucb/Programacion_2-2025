#include <iostream>
using namespace std;

int main()
{
    int numero;
    do
    {
        cout << "Ingrese un numero positivo: ";
        cin >> numero;
        if (numero <= 0)
        {
            cout << "El numero no es positivo. Intente de nuevo." << endl;
        }

    } while (numero <= 0);
    cout << "Correcto! El numero ingresado es: " << numero << endl;
    return 0;
}