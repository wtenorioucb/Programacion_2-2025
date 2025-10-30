#include <iostream>
#include <string.h>

using namespace std;

struct Producto
{
    char nombre[30];
    float precio;
    int cantidad_inventario;
    char observaciones[100];
};

Producto CrearProducto();

int main()
{
    int n = 0;
    float mayorPrecio = 0.0;
    int cantidadTotal = 0;
    Producto producto;
    system("cls");
    cout << "Ingrese la cantidad de productos a registrar: ";
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        cout << "PRODUCTO " << i << endl;
        cout << "===========" << endl;
        producto = CrearProducto();
        if (producto.precio > mayorPrecio)
        {
            mayorPrecio = producto.precio;
        }
        cantidadTotal += producto.cantidad_inventario;
        if (strcmp(producto.observaciones, "PRUDUCTO CON BAJA CANTIDAD DE INVENTARIO") == 0)
        {
            cout << "\tNombre: " << producto.nombre << "\n\tCantidad en inventario: " << producto.cantidad_inventario << "\n\tObservaciones: " << producto.observaciones << endl;
        }
    }
    cout << "\nEl mayor precio registrado es: " << mayorPrecio << endl;
    cout << "La cantidad total de productos en inventario es: " << cantidadTotal << endl;
    return 0;
}

Producto CrearProducto()
{
    Producto producto;
    cout << "Ingrese el nombre del producto: ";
    cin.getline(producto.nombre, 30);
    cout << "Ingrese el precio del producto: ";
    cin >> producto.precio;
    cout << "Ingrese la cantidad en inventario: ";
    cin >> producto.cantidad_inventario;
    if (producto.cantidad_inventario < 5)
    {
        strcpy(producto.observaciones, "PRUDUCTO CON BAJA CANTIDAD DE INVENTARIO");
    }
    else
    {
        strcpy(producto.observaciones, "");
    }
    cin.ignore();
    return producto;
}

