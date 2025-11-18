#include "LibInscripciones.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string archivoEstudiantes = "Estudiantes.bin";
    string archivoMaterias = "Materias.bin";
    string archivoCarreras = "Carreras.bin";
    string archivoInscripciones = "Inscripciones.bin";
    MenuOpciones(archivoEstudiantes, archivoMaterias, archivoCarreras, archivoInscripciones);
    return 0;
}
