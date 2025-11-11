#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Agenda
{
    char nombre[30];
    int telefono;
    int celular;
    char email[30];
    bool eliminado;   
};

void IngresarDatosAgenda(string NombreArchivo);
void MostrarDatosAgenda(string NombreArchivo);
void EncontrarContacto(string NombreArchivo);
void ModificarContacto(string NombreArchivo);
void MenuOpciones(string nombreArchivo);

int main()
{
    string nombreArchivo = "AgendaTelefonica.bin";
    MenuOpciones(nombreArchivo);
    return 0;
}

void IngresarDatosAgenda(string NombreArchivo)
{
    Agenda contacto;
    ofstream archivo;
    // Abrir el archivo en modalidad BINARIO para agregar datos al final
    archivo.open(NombreArchivo, ios::binary | ios::app);
    // Verificar si el archivo se abrió correctamente
    if (archivo.good())
    {
        // Ingresar los datos del contacto en la variable persona que es de tipo Agenda
        cin.ignore();
        cout << "Ingrese el nombre: ";
        cin.getline(contacto.nombre, 30);
        cout << "Ingrese el telefono: ";
        cin >> contacto.telefono;
        cout << "Ingrese el celular: ";
        cin >> contacto.celular;
        cin.ignore();
        cout << "Ingrese el email: ";
        cin.getline(contacto.email, 30);
        contacto.eliminado = false;
        // Escribir los datos en el archivo binario
        archivo.write((char*)&contacto, sizeof(Agenda));
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    // Cerrar el archivo
    archivo.close();
}

void MostrarDatosAgenda(string NombreArchivo)
{
    Agenda contacto;
    ifstream archivo;
    // Abrir el archivo en modalidad BINARIO, para leer los datos 
    archivo.open(NombreArchivo, ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (archivo.good())
    {
        system("cls");
        cout << "LISTADO DE CONTACTOS" << endl;
        // Leer los datos del archivo binario y mostrarlos en pantalla
        while (archivo.read((char*)&contacto, sizeof(Agenda)))
        {
            // Verificar que el contacto no esté eliminado
            if (!contacto.eliminado)
            {
                cout << "CONTACTO:" << contacto.nombre << endl;
                cout << "--------------------------------" << endl;
                cout << "\tTelefono: " << contacto.telefono << endl;
                cout << "\tCelular: " << contacto.celular << endl;
                cout << "\tEmail: " << contacto.email << endl;
                cout     << "--------------------------------" << endl;
            }
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    system("pause");
    // Cerrar el archivo
    archivo.close();
}

void EncontrarContacto(string NombreArchivo)
{
    Agenda contacto;
    ifstream archivo;
    string nombreBuscado;
    // Variable para indicar si se encontró el contacto
    bool encontrado = false;
    system("cls");
    cout << "Ingrese el nombre del contacto a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscado);
    // Abrir el archivo en modalidad BINARIO, para leer los datos 
    archivo.open(NombreArchivo, ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (archivo.good())
    {
        // Leer los datos del archivo binario y buscar el contacto
        while (archivo.read((char*)&contacto, sizeof(Agenda)) && !encontrado)
        {
            if (nombreBuscado == contacto.nombre && !contacto.eliminado)
            {
                cout << "CONTACTO ENCONTRADO: " << contacto.nombre << endl;
                cout << "-----------------------------------" << endl;
                cout << "\tTelefono: " << contacto.telefono << endl;
                cout << "\tCelular: " << contacto.celular << endl;
                cout << "\tEmail: " << contacto.email << endl;
                cout << "-----------------------------------" << endl;
                encontrado = true;
            }
        }
        if (!encontrado)
        {
            cout << "Contacto no encontrado." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    system("pause");
    // Cerrar el archivo
    archivo.close();
}

void ModificarContacto(string NombreArchivo)
{
    Agenda contacto;
    fstream archivo;
    string nombreBuscado;
    // Variable para indicar si se encontró el contacto
    bool encontrado = false;
    system("cls");
    cout << "Ingrese el nombre del contacto a modificar: ";
    cin.ignore();
    getline(cin, nombreBuscado);
    // Abrir el archivo en modalidad BINARIO, para leer y escribir los datos al mismo tiempo
    archivo.open(NombreArchivo,  ios::in | ios::out | ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (archivo.good())
    {
        // Leer los datos del archivo binario y buscar el contacto
        while (archivo.read((char*)&contacto, sizeof(Agenda)) && !encontrado)
        {
            if (nombreBuscado == contacto.nombre && !contacto.eliminado)
            {
                cout << "CONTACTO ENCONTRADO: " << contacto.nombre << endl;
                cout << "-----------------------------------" << endl;
                cout << "\tTelefono: " << contacto.telefono << endl;
                cout << "\tCelular: " << contacto.celular << endl;
                cout << "\tEmail: " << contacto.email << endl;
                cout << "-----------------------------------" << endl;
                encontrado = true;
                // Mover el puntero de escritura al inicio del registro encontrado
                archivo.seekp(-sizeof(Agenda), ios::cur);
                // Ingresar los nuevos datos del contacto
                cout << "Ingrese el nuevo telefono: ";
                cin >> contacto.telefono;
                cout << "Ingrese el nuevo celular: ";
                cin >> contacto.celular;
                cin.ignore();
                cout << "Ingrese el nuevo email: ";
                cin.getline(contacto.email, 30);
                // Escribir los nuevos datos en el archivo binario
                archivo.write((char*)&contacto, sizeof(Agenda));
            }
        }
        if (!encontrado)
        {
            cout << "Contacto no encontrado." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    system("pause");
    // Cerrar el archivo
    archivo.close();
}

void EliminarContacto(string NombreArchivo)
{
    Agenda contacto;
    fstream archivo;
    string nombreBuscado;
    // Variable para indicar si se encontró el contacto
    bool encontrado = false;
    system("cls");
    cout << "Ingrese el nombre del contacto a eliminar: ";
    cin.ignore();
    getline(cin, nombreBuscado);
    // Abrir el archivo en modalidad BINARIO, para leer y escribir los datos al mismo tiempo
    archivo.open(NombreArchivo,  ios::in | ios::out | ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (archivo.good())
    {
        // Leer los datos del archivo binario y buscar el contacto
        while (archivo.read((char*)&contacto, sizeof(Agenda)) && !encontrado)
        {
            if (nombreBuscado == contacto.nombre && !contacto.eliminado)
            {
                cout << "CONTACTO ELIMINADO: " << contacto.nombre << endl;
                cout << "-----------------------------------" << endl;
                cout << "\tTelefono: " << contacto.telefono << endl;
                cout << "\tCelular: " << contacto.celular << endl;
                cout << "\tEmail: " << contacto.email << endl;
                cout << "-----------------------------------" << endl;
                encontrado = true;
                // Mover el puntero de escritura al inicio del registro encontrado
                archivo.seekp(-sizeof(Agenda), ios::cur);
                // Marcar el contacto como eliminado
                contacto.eliminado = true;                
                // Escribir los nuevos datos en el archivo binario
                archivo.write((char*)&contacto, sizeof(Agenda));
            }
        }
        if (!encontrado)
        {
            cout << "Contacto no encontrado." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    system("pause");
    // Cerrar el archivo
    archivo.close();
}

void MenuOpciones(string nombreArchivo)
{
    int opcion = 0;
    do
    {
        system("cls");
        cout << "MENU DE OPCIONES" << endl;
        cout << "================" << endl;
        cout << "\t1. Crear nuevo contacto" << endl;
        cout << "\t2. Listar datos contactos" << endl;
        cout << "\t3. Encontrar contacto" << endl;
        cout << "\t4. Modificar contacto" << endl;
        cout << "\t5. Eliminar contacto" << endl;
        cout << "\t0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1:
                IngresarDatosAgenda(nombreArchivo);
                break;
            case 2:
                MostrarDatosAgenda(nombreArchivo);
                break;
            case 3:
                EncontrarContacto(nombreArchivo);
                break;
            case 4:
                ModificarContacto(nombreArchivo);
                break;
            case 5:
                EliminarContacto(nombreArchivo);
                break;
            default:
                if (opcion != 0)
                {
                    cout << "Opcion no valida." << endl;
                    system("pause");
                }
                
                break;
        }
    } while (opcion != 0);
    system("cls");
}