#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void LLenarMatriz(int matrix[][100], int filas, int columnas);
void MostrarMatriz(int matrix[][100], int filas, int columnas);
int GenerarNumeroAleatorio(int min, int max);
void TrasponerMatriz(int matrix[][100], int filas, int columnas, int transpuesta[][100]);

int main()
{
    int filas = 0; // Numero de filas
    int columnas = 0; // Numero de columnas
    srand(time(NULL));
    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;
    int matrix[filas][100]; // Declaration de sintaxis
    int transpuesta[columnas][100];
    LLenarMatriz(matrix, filas, columnas);
    MostrarMatriz(matrix, filas, columnas);
    TrasponerMatriz(matrix, filas, columnas, transpuesta);
    MostrarMatriz(transpuesta, filas, columnas);
    return 0;
}

void LLenarMatriz(int matrix[][100], int filas, int columnas)
{
    // Ejemplo - Inicializacion de la matriz con ceros
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matrix[i][j] = GenerarNumeroAleatorio(1, 100);
        }
    }
}

void MostrarMatriz(int matrix[][100], int filas, int columnas)
{
    cout << endl;
    cout << "Matriz:" << endl;
    cout << "--------" << endl;
    // Ejemplo - Imprimir la matriz
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void TrasponerMatriz(int matrix[][100], int filas, int columnas, int transpuesta[][100])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            transpuesta[j][i] = matrix[i][j];
        }
    }
}

int GenerarNumeroAleatorio(int min, int max)
{
    return rand() % (max - min + 1) + min;
}