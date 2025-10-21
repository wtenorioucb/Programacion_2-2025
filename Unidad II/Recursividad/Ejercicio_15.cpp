#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;
int NumeroAleatorio(int min, int max);
void CerearMatriz(int matriz[3][10]);
void MostrarMatriz(int matriz[3][10]);
void SimulacionVentaGasolina(int TotalGasolina, int matrizGE[3][10], int matrizGP[3][10]);

int main()
{
    srand(time(0));
    int matrizGE[3][10]; // Gasolina Especial
    int matrizGP[3][10]; // Gasolina Premium
    CerearMatriz(matrizGE);
    CerearMatriz(matrizGP);
    cout << "SIMULACION" << endl;
    SimulacionVentaGasolina(250, matrizGE, matrizGP);
    cout << "MATRIZ GE" << endl;
    MostrarMatriz(matrizGE);
    cout << "MATRIZ GP" << endl;
    MostrarMatriz(matrizGP);
    return 0;
}

int NumeroAleatorio(int min, int max)
{
    return rand() % ((max - min + 1) + min);
}

void CerearMatriz(int matriz[3][10])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matriz[i][j] = 0;
        }
    }
}

void MostrarMatriz(int matriz[3][10])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

void SimulacionVentaGasolina(int TotalGasolina, int matrizGE[3][10], int matrizGP[3][10])
{
    int seleccionTipoGasolina = 0;
    int seleccionManguera = 0;
    int manguera1 = 0;
    int manguera2 = 0;
    int manguera3 = 0;
    int manguera4 = 0;
    int manguera5 = 0;
    int manguera6 = 0;
    while (TotalGasolina > 0)
    {
        seleccionTipoGasolina = NumeroAleatorio(1, 2);
        switch (seleccionTipoGasolina)
        {
        case 1: // Gasolina Especial
            seleccionManguera = NumeroAleatorio(0, 2);
            switch (seleccionManguera)
            {
            case 0: // Manguera 1
                matrizGE[seleccionManguera][manguera1] = NumeroAleatorio(20, 50);
                TotalGasolina = TotalGasolina - matrizGE[seleccionManguera][manguera1];
                manguera1++;
                break;
            case 1: // Manguera 2
                matrizGE[seleccionManguera][manguera2] = NumeroAleatorio(20, 50);
                TotalGasolina = TotalGasolina - matrizGE[seleccionManguera][manguera2];
                manguera2++;
                break;
            case 2: // Manguera 3
                matrizGE[seleccionManguera][manguera3] = NumeroAleatorio(20, 50);
                TotalGasolina = TotalGasolina - matrizGE[seleccionManguera][manguera3];
                manguera3++;
                break;
            }
            break;
        case 2: // Gasolina Premium
            seleccionManguera = NumeroAleatorio(0, 2);
            switch (seleccionManguera)
            {
            case 0: // Manguera 1
                matrizGP[seleccionManguera][manguera4] = NumeroAleatorio(20, 50);
                TotalGasolina = TotalGasolina - matrizGP[seleccionManguera][manguera4];
            	manguera4++;
                break;
            case 1: // Manguera 2
                matrizGP[seleccionManguera][manguera5] = NumeroAleatorio(20, 50);
                TotalGasolina = TotalGasolina - matrizGP[seleccionManguera][manguera5];
                manguera5++;
                break;
            case 2: // Manguera 3
                matrizGP[seleccionManguera][manguera6] = NumeroAleatorio(20, 50);
                TotalGasolina = TotalGasolina - matrizGP[seleccionManguera][manguera6];
                manguera6++;
                break;
            }
            break;
        }
    }
}
