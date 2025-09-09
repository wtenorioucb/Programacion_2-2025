#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int numero_aleatorio = 0;
    int max = 0;
    int min = 0;
    // Inicializar la semilla para generar números aleatorios
    srand(time(0));   

    cout << "\nEntre 40 y 200" << endl;
    cout << "numero_aleatorio = ( rand() % (max - min + 1) ) + min" << endl;
    max = 2000;
    min = 40;
    // Generar y mostrar 10 números aleatorios
    for (int i = 1; i <= 10; ++i)
    {
        numero_aleatorio = (rand() % (max - min+ 1)) + min;
        cout << numero_aleatorio << " - ";
    }
    return 0;
}