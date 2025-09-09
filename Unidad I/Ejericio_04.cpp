#include <iostream>

using namespace std;

void MostrarMensaje();

int main()
{
    system("chcp 65001");
    system("cls");
    MostrarMensaje();
    return 0;
}

void MostrarMensaje()
{
    cout << "Hola Mundo!" << endl;
}
