#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int NroAleatorio(int LimInf, int LimSup);

int main()
{
    srand(time(0));
    int edad;
    edad = NroAleatorio(1,99);;
    cout << "La edad de la persona es: " << edad << endl;

    int edades[] = {NroAleatorio(1,99),NroAleatorio(1,99),NroAleatorio(1,99),NroAleatorio(1,99),NroAleatorio(1,99)};
    //int edades[5];
    //edades[0] = NroAleatorio(1,99);
    //edades[1] = NroAleatorio(1,99);
    //edades[2] = NroAleatorio(1,99);
    //edades[3] = NroAleatorio(1,99);
    //edades[4] = NroAleatorio(1,99);
    for (int i = 0; i < 5; i++)
    {
        cout << "Valor de la variable edades en la posicion " << i << ": " << edades[i] << endl;
    }
    return 0;
}

int NroAleatorio(int LimInf, int LimSup)
{
    return rand() % ((LimSup - LimInf + 1)) - 1;
}