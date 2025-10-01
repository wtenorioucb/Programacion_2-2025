// Ejemplo del bucle FOR EACH

#include <iostream>
#include <vector>

using namespace std;

void MostrarVectorFor(vector<int> arreglo);
void MostrarVectorForEach(vector<int> arreglo);

int main()
{
    vector<int> Edades;
    Edades.push_back(30);
    Edades.push_back(18);
    Edades.push_back(54);
    Edades.push_back(5);
    Edades.push_back(72);
    system("cls");
    MostrarVectorFor(Edades);
    MostrarVectorForEach(Edades);
    return 0;
}

void MostrarVectorFor(vector<int> arreglo)
{
    cout << "Iterando con un FOR" << endl;
    cout << "===================" << endl;
    for (int i = 0; i < arreglo.size(); i++)
    {
        cout << "Elemento " << i << ": " << arreglo[i] << endl;
    }
    cout << "===================" << endl;
}

void MostrarVectorForEach(vector<int> arreglo)
{
    cout << "Iterando con un FOR EACH" << endl;
    cout << "========================" << endl;
    for (int elemento : arreglo)
    {
        cout << "Elemento: " << elemento << endl;
    }
    cout << "===================" << endl;
}