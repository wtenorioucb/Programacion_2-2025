#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int NumeroAleatorio(int min, int max);
void DesplegarMatriz(int matriz[3][3]);

int main()
{
    int matriz_01[3][3];
    int matriz_02[3][3];
    srand(time(0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz_01[i][j] = NumeroAleatorio(1, 10);
        }
    }
    
    DesplegarMatriz(matriz_01);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz_02[i][j] = matriz_01[j][i];
        }
    }

    DesplegarMatriz(matriz_02);
    
    return 0;
}

int NumeroAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void DesplegarMatriz(int matriz[3][3])
{
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}