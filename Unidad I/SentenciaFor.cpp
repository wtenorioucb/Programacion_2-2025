#include <iostream>
using namespace std;

int main()
{
    int numero;
    cout << "Ingrese un numero:" << endl;
    cin >> numero;
    for (int i = 1; i <= numero; i++)
    {
        cout << i << " - ";
    }
    cout << endl;
    return 0;
}