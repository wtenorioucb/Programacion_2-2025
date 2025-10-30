#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct Producto
{
    char nombre[30];
    float precio;
    int cantidad_inventario;
    char observaciones[100];
};

Producto CrearProducto();
vector<Producto> IngresarProductos(int n);
Producto ProductoMayorPrecio(const vector<Producto> productos);
void MostrarProducto(Producto producto);
void MostrarProductosConBajaCantidad(vector<Producto> productos);

int main()
{
    int n = 0;
    float mayorPrecio = 0.0;
    int cantidadTotal = 0;
    vector<Producto> productos;
    system("cls");
    cout << "Ingrese la cantidad de productos a registrar: ";
    cin >> n;
    cin.ignore();
    productos = IngresarProductos(n);
    cout << "El producto con mayor precio es" << endl;
    MostrarProducto(ProductoMayorPrecio(productos));
    MostrarProductosConBajaCantidad(productos);
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
        strcpy(producto.observaciones, "PRODUCTO CON BAJA CANTIDAD DE INVENTARIO");
    }
    else
    {
        strcpy(producto.observaciones, "");
    }
    cin.ignore();
    return producto;
}

vector<Producto> IngresarProductos(int n)
{
    vector<Producto> productos;
    Producto producto;
    for (int i = 1; i <= n; i++)
    {
        cout << "PRODUCTO " << i << endl;
        cout << "===========" << endl;
        producto = CrearProducto();
        productos.push_back(producto);
    }
    return productos;
}

Producto ProductoMayorPrecio(const vector<Producto> productos)
{
    float mayorPrecio = 0.0;
    Producto productoMayor;
    for (int i = 0; i < productos.size(); i++)
    {
        if (productos[i].precio > mayorPrecio)
        {
            productoMayor = productos[i];
        }
    }
    return productoMayor;
}

void MostrarProducto(Producto producto)
{

    cout << "PRODUCTO: " << producto.nombre << endl;
    cout << "===================" << endl;
    cout << "\tPrecio: " << producto.precio << endl;
    cout << "\tCantidad en inventario: " << producto.cantidad_inventario << endl;
    cout << "\tObservaciones: " << producto.observaciones << endl;
}

void MostrarProductosConBajaCantidad(vector<Producto> productos)
{
    cout << "PRODUCTOS CON BAJA CANTIDAD DE INVENTARIO" << endl;
    cout << "==========================================" << endl;
    for (int i = 0; i < productos.size(); i++)
    {
        if (strcmp(productos[i].observaciones, "PRODUCTO CON BAJA CANTIDAD DE INVENTARIO") == 0)
        {
            MostrarProducto(productos[i]);
        }
    }
}