#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector> // Libreria para manejar plantilla de vectores

using namespace std;

int NroAleatorio(int LimInf, int LimSup);

int main()
{
    char apellido[7] = {'T','E','N','O','R','I','O'};
    cout << "La variable edades: " << apellido;
    return 0;
}

int NroAleatorio(int LimInf, int LimSup)
{
    return rand() % ((LimSup - LimInf + 1)) - 1;
}