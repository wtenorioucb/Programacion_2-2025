#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    system("chcp 65001");
    system("cls");
    srand(time(0)); // Inicializar la semilla para generar números aleatorios
    int LimSuperior = 400;
    int LimInferior = 200;
    int NumeroAleatorio = ( rand() % (LimSuperior - LimInferior + 1) ) + LimInferior;
    cout << "Número aleatorio generado: " << NumeroAleatorio << endl;
    system("pause");
    return 0;
}

