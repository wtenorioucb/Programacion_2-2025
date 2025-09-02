#include <iostream>
using namespace std;

int main() {
    int a = 4, b = 3, c = 2;
    int resultado = 0;
    for (int i = 1; i <= a; i++) 
    {
        if ((i % 2 == 0) || (b % 2 == 0))
        {
            resultado += (i * c) - (b / (i + 1));
        }
        else
        {
            resultado += (b % (i + c));
        }
    }
    cout << "Resultado: " << resultado << endl;
    return 0;
}

