#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_FILAS = 100;
const int MAX_COLUMNAS = 100;

void LlenarMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas);
void MostrarMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas);
int SumarElementosMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas);
int GenerarNumeroAleatorio(int minimo, int maximo);
float CalcularPromedioMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas);

int main()
{
    srand(time(NULL));
    int matriz[MAX_FILAS][MAX_COLUMNAS];
    int filas, columnas;
    do
    {
        system("cls");
        cout << "Ingrese el numero de filas (maximo " << MAX_FILAS << "): ";
        cin >> filas;
        cout << "Ingrese el numero de columnas (maximo " << MAX_COLUMNAS << "): ";
        cin >> columnas;
    } while (filas <= 0 || filas > MAX_FILAS || columnas <= 0 || columnas > MAX_COLUMNAS);

    LlenarMatriz(matriz, filas, columnas);
    cout << "\nMatriz generada\n";
    cout << "===============\n";
    MostrarMatriz(matriz, filas, columnas);
    int suma = SumarElementosMatriz(matriz, filas, columnas);
    cout << "\nLa suma de todos los elementos de la matriz es: " << suma << endl;
    cout << "El promedio de los elementos de la matriz es: " << CalcularPromedioMatriz(matriz, filas, columnas) << endl;
    return 0;
}

int GenerarNumeroAleatorio(int minimo, int maximo)
{
    return minimo + rand() % (maximo - minimo + 1);
}

void LlenarMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = GenerarNumeroAleatorio(1, 100);
        }
    }
}

void MostrarMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

int SumarElementosMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas)
{
    int suma = 0;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            suma += matriz[i][j];
        }
    }
    return suma;
}

float CalcularPromedioMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas)
{
    int suma = SumarElementosMatriz(matriz, filas, columnas);
    return static_cast<float>(suma) / (filas * columnas);
}