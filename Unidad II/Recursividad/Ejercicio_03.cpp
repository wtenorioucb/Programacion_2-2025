#include <iostream>
#include <vector>

using namespace std;

void MostrarElementosFor(vector<int> vec);
void MostrarElementosForAsc(vector<int> vec);
int MostrarElementosRecursivo(vector<int> vec, int indice);
int MostrarElementosRecursivoAsc(vector<int> vec, int indice);

int main()
{
    vector<int> numeros = {10, 20, 30, 40, 50};
    cout << "\nElementos del vector en orden ascendente:" << endl;
    MostrarElementosRecursivoAsc(numeros, 0);
    cout << "\nElementos del vector en orden inverso:" << endl;
    MostrarElementosRecursivo(numeros, numeros.size() - 1);
    cout << endl << "\nElementos del vector en orden ascendente usando for:" << endl;
    MostrarElementosForAsc(numeros);
    cout << endl << "\nElementos del vector en orden inverso usando for:" << endl;
    MostrarElementosFor(numeros);
    return 0;
}

int MostrarElementosRecursivo(vector<int> vec, int indice)
{
    if (indice < 0)
    {
        return 0;
    }
    else
    {
        cout << vec[indice] << "\t";
        return MostrarElementosRecursivo(vec, indice - 1);
    }
}

int MostrarElementosRecursivoAsc(vector<int> vec, int indice)
{
    if (indice >= vec.size())
    {
        return 0;
    }
    else
    {
        cout << vec[indice] << "\t";
        return MostrarElementosRecursivoAsc(vec, indice + 1);
    }
}

void MostrarElementosFor(vector<int> vec)
{
    for (int i = vec.size() - 1; i >= 0; --i)
    {
        cout << vec[i] << "\t";
    }
}

void MostrarElementosForAsc(vector<int> vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << "\t";
    }
}