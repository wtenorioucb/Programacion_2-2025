#include <iostream>

using namespace std;

void Imprime(int valor, int base = 10);

int main()
{
    int n = 0;
    system("chcp 65001");
    system("cls");
    cout << "Ingrese un número: ";
    cin >> n;
    Imprime(n);
    Imprime(n, 8);
    Imprime(n, 16);
    Imprime(n, 4);
    return 0;
}


void Imprime(int valor, int base)
{
    switch (base) {
        case 8:
            cout << "Octal: " << oct << valor << endl;
            break;
        case 10:
            cout << "Decimal: " << dec << valor << endl;
            break;
        case 16:
            cout << "Hexadecimal: " << hex << valor << endl;
            break;
        default:
            cout << "Función Imprime(): Representación en base "
             << base << " NO definida" << endl;
    }
}

