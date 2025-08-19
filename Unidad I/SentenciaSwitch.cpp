#include <iostream>
using namespace std;

int main()
{
    int dia;
    system("chcp 65001");
    system("cls");
    cout << "Ingrese un numero del 1 al 7 para saber el dia de la semana: ";
    cin >> dia;
    switch (dia)
    {
        case 1:
            cout << "Lunes" << endl;
            break;
        case 2:
            cout << "Martes" << endl;
            break;
        case 3:
            cout << "Miércoles" << endl;
            break;
        case 4:
            cout << "Jueves" << endl;
            break;
        case 5:
            cout << "Viernes" << endl;
            break;
        case 6:
            cout << "Sábado" << endl;
            break;
        case 7:
            cout << "Domingo" << endl;
            break;
        default:
            cout << "Numero no valido. Debe ser entre 1 y 7." << endl;
    }
    return 0;
}