#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Estudiante
{
    char ci[10];
    char nombres[30];
    char apellidos[30];
    int codigo_carrera;
};

struct Carrera
{
    int codigo;
    char resumido[4];
    char nombre[30];
};

struct Materia
{
    int codigo;
    char sigla[7];
    char nombre[30];
    int creditos_academicos;
    int creditos_economicos;
};

struct InscripcionMaterias
{
    char ci[10];
    int codigo_materia;
    char fecha_inscripcion[10];
};

void MenuOpciones(string archivoEstudiantes, string archivoMaterias, string archivoCarreras, string archivoInscripciones);
void CrearEstudiante(string archivoEstudiantes, string archivoCarreras);
void CrearMateria(string archivoMaterias);
void CrearCarrera(string archivoCarreras);
void ListadoCarreras(string archivoCarreras);
void ListadoEstudiantes(string archivoEstudiantes, string archivoCarreras);
string ObtenerNombreCarrera(string archivoCarreras, int codigoCarrera);

int main()
{
    string archivoEstudiantes = "Estudiantes.bin";
    string archivoMaterias = "Materias.bin";
    string archivoCarreras = "Carreras.bin";
    string archivoInscripciones = "Inscripciones.bin";
    MenuOpciones(archivoEstudiantes, archivoMaterias, archivoCarreras, archivoInscripciones);
    return 0;
}

void MenuOpciones(string archivoEstudiantes, string archivoMaterias, string archivoCarreras, string archivoInscripciones)
{
    int opcion = 0;
    int subopcion = 0;
    do
    {
        system("cls");
        cout << "MENU DE OPCIONES" << endl;
        cout << "================" << endl;
        cout << "\t1. ABM Estudiantes" << endl;
        cout << "\t2. ABM Materias" << endl;
        cout << "\t3. ABM Carreras" << endl;
        cout << "\t4. Inscripciones" << endl;
        cout << "\t0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1:
                do
                {
                    system("cls");
                    cout << "MENU ESTUDIANTES" << endl;
                    cout << "================" << endl;
                    cout << "\t1. Crear Estudiante" << endl;
                    cout << "\t2. Listado Estudiantes" << endl;
                    cout << "\t0. Salir" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> subopcion;
                    switch (subopcion)
                    {
                        case 1:
                            CrearEstudiante(archivoEstudiantes, archivoCarreras);
                            system("pause");
                            break;
                        case 2:
                            ListadoEstudiantes(archivoEstudiantes, archivoCarreras);
                            system("pause");
                            break;
                        default:
                            if (subopcion != 0)
                            {
                                cout << "Opcion no valida." << endl;
                                system("pause");
                            }
                            break;
                    }
                } while (subopcion != 0);            
                break;
            case 2:
                do
                {
                    system("cls");
                    cout << "MENU MATERIAS" << endl;
                    cout << "=============" << endl;
                    cout << "\t1. Crear Materia" << endl;
                    cout << "\t2. Listado Materias" << endl;
                    cout << "\t0. Salir" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> subopcion;
                    switch (subopcion)
                    {
                        case 1:
                            cout << "Crear Materias" << endl;
                            system("pause");
                            break;
                        case 2:
                            cout << "Listado Materias" << endl;
                            system("pause");
                            break;
                        default:
                            if (subopcion != 0)
                            {
                                cout << "Opcion no valida." << endl;
                                system("pause");
                            }
                            break;
                    }
                } while (subopcion != 0);            
                break;
            case 3:
                do
                {
                    system("cls");
                    cout << "MENU CARRERAS" << endl;
                    cout << "=============" << endl;
                    cout << "\t1. Crear Carrera" << endl;
                    cout << "\t2. Listado Carreras" << endl;
                    cout << "\t0. Salir" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> subopcion;
                    switch (subopcion)
                    {
                        case 1:
                            CrearCarrera(archivoCarreras);
                            system("pause");
                            break;
                        case 2:
                            ListadoCarreras(archivoCarreras);
                            system("pause");
                            break;
                        default:
                            if (subopcion != 0)
                            {
                                cout << "Opcion no valida." << endl;
                                system("pause");
                            }
                            break;
                    }
                } while (subopcion != 0); 
                break;
            case 4:
                cout << "Inscribir Materias" << endl;
                system("pause");
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

void CrearEstudiante(string archivoEstudiantes, string archivoCarreras)
{
    Estudiante _estudiante;
    ofstream archivo;
    archivo.open(archivoEstudiantes, ios::binary | ios::app);
    if (archivo.good())
    {
        cin.ignore();
        cout << "Ingrese CI: ";
        cin.getline(_estudiante.ci, 10);
        cout << "Ingrese Nombres: ";
        cin.getline(_estudiante.nombres, 30);
        cout << "Ingrese Apellidos: ";
        cin.getline(_estudiante.apellidos, 30);
        ListadoCarreras(archivoCarreras);
        cout << "Ingrese Codigo de Carrera: ";
        cin >> _estudiante.codigo_carrera;
        archivo.write((char*)&_estudiante, sizeof(Estudiante));
        cout << "Estudiante creado exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();
}

void CrearMateria(string archivoMaterias)
{
    Materia _materia;
    ofstream archivo;
    archivo.open(archivoMaterias, ios::binary | ios::app);
    if (archivo.good())
    {
        cin.ignore();
        cout << "Ingrese Codigo: ";
        cin >> _materia.codigo;
        cin.ignore();
        cout << "Ingrese Sigla: ";
        cin.getline(_materia.sigla, 7);
        cout << "Ingrese Nombre: ";
        cin.getline(_materia.nombre, 30);
        cout << "Ingrese Creditos Academicos: ";
        cin >> _materia.creditos_academicos;
        cout << "Ingrese Creditos Economicos: ";
        cin >> _materia.creditos_economicos;
        archivo.write((char*)&_materia, sizeof(Materia));
        cout << "Materia creada exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();
}

void CrearCarrera(string archivoCarreras)
{
    Carrera _carrera;
    ofstream archivo;
    archivo.open(archivoCarreras, ios::binary | ios::app);
    if (archivo.good())
    {
        cout << "Ingrese Codigo: ";
        cin >> _carrera.codigo;
        cin.ignore();
        cout << "Ingrese Resumido: ";
        cin.getline(_carrera.resumido, 4);
        cout << "Ingrese Nombre: ";
        cin.getline(_carrera.nombre, 30);
        archivo.write((char*)&_carrera, sizeof(Carrera));
        cout << "Carrera creada exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();
}

void ListadoCarreras(string archivoCarreras)
{
    Carrera _carrera;
    ifstream archivo;
    archivo.open(archivoCarreras, ios::binary);
    if (archivo.good())
    {
        cout << "CARRERAS" << endl;
        cout << "========" << endl;
        cout << "Codigo\tResumido\tNombre" << endl;
        cout << "------------------------------------------------" << endl;
        while (archivo.read((char*)&_carrera, sizeof(Carrera)))
        {
            cout << _carrera.codigo << "\t" << _carrera.resumido << "\t\t" << _carrera.nombre << endl;
        }
        cout << "------------------------------------------------" << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();
}

void ListadoEstudiantes(string archivoEstudiantes, string archivoCarreras)
{
    Estudiante _estudiante;
    ifstream archivo;
    archivo.open(archivoEstudiantes, ios::binary);
    if (archivo.good())
    {
        cout << "ESTUDIANTES" << endl;
        cout << "============" << endl;
        cout << "CI\tNombres\t\tApellidos\t\tCarrera" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        while (archivo.read((char*)&_estudiante, sizeof(Estudiante)))
        {
            cout << _estudiante.ci << "\t" << _estudiante.nombres << "\t" << _estudiante.apellidos << "\t" << ObtenerNombreCarrera(archivoCarreras, _estudiante.codigo_carrera) << endl;
        }
        cout << "---------------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();
}

string ObtenerNombreCarrera(string archivoCarreras, int codigoCarrera)
{
    Carrera _carrera;
    ifstream archivo;
    string nombreCarrera="";
    archivo.open(archivoCarreras, ios::binary);
    if (archivo.good())
    {
        while (archivo.read((char*)&_carrera, sizeof(Carrera)))
        {
            if (_carrera.codigo == codigoCarrera)
            {
                nombreCarrera = _carrera.nombre;
            }
        }
    }
    archivo.close();
    return nombreCarrera;
}

