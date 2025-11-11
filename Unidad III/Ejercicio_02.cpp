#include <iostream>
#include <string.h>
#include <vector>

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
void IngresarDatos(vector<Computer> &listComputers, int n);
void DesplegarDatosComputadora(Computer computadora);
void MostrarListaComputadoras(vector<Computer> listComputers);
void MostrarListaComputadorasStockMinimo(vector<Computer> listComputers);

int main()
{
    int n = 0;
    vector<Computer> listComputers;
    system("cls");
    cout << "Ingrese la cantidad de computadoras: ";
    cin >> n;
    IngresarDatos(listComputers, n);
    system("pausa");
    system("cls");
    cout << "LISTA DE COMPUTADORAS" << endl;
    cout << "=====================" << endl;
    MostrarListaComputadorasStockMinimo(listComputers);
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

void IngresarDatos(vector<Computer> &listComputers, int n)
{
    for (int i = 0; i < n; i++)
    {
        listComputers.push_back(IngresarDatoComputadora());
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

void MostrarListaComputadoras(vector<Computer> listComputers)
{
    for (int i = 0; i < listComputers.size(); i++)
    {
        DesplegarDatosComputadora(listComputers[i]);
    }   
}

void MostrarListaComputadorasStockMinimo(vector<Computer> listComputers)
{
    for (int i = 0; i < listComputers.size(); i++)
    {
        if (strcmp(listComputers[i].observaciones,"Stock bajo") == 0)
        {
            DesplegarDatosComputadora(listComputers[i]);
        }
    }   
}