#include <iostream>
#include <string.h>

using namespace std;

struct Computer
{
    char model[20];
    char brand[20];
    double precio_compra;
    double precio_venta;
    float weight;
    int cantidad_disponible;
    char observaciones[100];
};

Computer IngresarDatoComputadora();
void IngresarDatos(int n);
void DesplegarDatosComputadora(Computer computadora);

int main()
{
    int n = 0;
    system("cls");
    cout << "Ingrese la cantidad de computadoras: ";
    cin >> n;
    IngresarDatos(n);
    return 0;
}

Computer IngresarDatoComputadora()
{
    Computer computadora; // Definir la variable
    cin.ignore();
    cout << "Ingrese el modelo: ";
    cin.getline(computadora.model, 20);
    cout << "Ingrese el marca: ";
    cin.getline(computadora.brand, 20);
    cout << "Ingrese el precio de compra: ";
    cin >> computadora.precio_compra;
    computadora.precio_venta = computadora.precio_compra * 1.2;
    cout << "Ingrese el peso en Kg: ";
    cin >> computadora.weight;
    cout << "Ingrese la cantidad disponible: ";
    cin >> computadora.cantidad_disponible;
    if (computadora.cantidad_disponible < 5)
    {
        strcpy(computadora.observaciones, "Stock bajo");
    }
    else
    {
        strcpy(computadora.observaciones, "");
    }
    return computadora;
}

void IngresarDatos(int n)
{
    Computer computadora;
    for (int i = 1; i <= n; i++)
    {
        computadora = IngresarDatoComputadora();
        //DesplegarDatosComputadora(computadora);
    }    
}

void DesplegarDatosComputadora(Computer computadora)
{
    cout << "-------------------------------------------" << endl;
    cout << "\tModelo: " << computadora.model << endl;
    cout << "\tMarca: " << computadora.brand << endl;
    cout << "\tPrecio compra: " << computadora.precio_compra << endl;
    cout << "\tPrecio venta: " << computadora.precio_venta << endl;
    cout << "\tPeso: " << computadora.weight << endl;
    cout << "\tCantidad disponible: " << computadora.cantidad_disponible << endl;
    cout << "\tObservaciones: " << computadora.observaciones << endl;
    cout << "-------------------------------------------" << endl;
}
