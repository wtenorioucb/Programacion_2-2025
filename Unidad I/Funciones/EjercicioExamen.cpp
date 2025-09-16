#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void SimulacionInscripcion(int n);

int main()
{
    srand(time(0)); 
    // ( rand() % (max - min + 1) ) + min
    int n = 0;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    SimulacionInscripcion(n);
    return 0;
}

void SimulacionInscripcion(int n)
{
    int semestre = 0; // Entre 2 y 5
    int nroMaterias = 0; // Entre 3 y 6
    int carrera = 0; // Entre 1 y 4

    // Variables para almacenar la cantidad de estudiantes por carrera
    int totalINS = 0;
    int totalDD = 0;
    int totalMEC = 0;
    int totalIIE = 0;

    int total2do = 0;
    int total3ro = 0;
    int total4to = 0;
    int total5to = 0;

    int totalMaterias = 0;

    for (int i = 1; i <= n; i++)
    {
        nroMaterias = ( rand() % (6 - 3 + 1) ) + 3;
        totalMaterias += nroMaterias;
        // Extraer la carrera del estudiante
        carrera = ( rand() % (4 - 1 + 1) ) + 1;
        switch (carrera)
        {
            case 1:
                totalINS++;
                break;
            case 2:
                totalDD++;
                break;
            case 3:
                totalMEC++;
                break;
            case 4:
                totalIIE++;
                break;
        }
        // Extraer el semestre del estudiante
        semestre = ( rand() % (5 - 2 + 1) ) + 2;
        switch (semestre)
        {
            case 2:
                total2do++;
                break;
            case 3:
                total3ro++;
                break;
            case 4:
                total4to++;
                break;
            case 5:
                total5to++;
                break;
        }

    }
    cout << "Total de estudiantes INS: " << totalINS << endl;
    cout << "Total de estudiantes DD: " << totalDD << endl;
    cout << "Total de estudiantes MEC: " << totalMEC << endl;
    cout << "Total de estudiantes IIE: " << totalIIE << endl;

    cout << "Total de estudiantes 2do Semestre: " << total2do << endl;
    cout << "Total de estudiantes 3er Semestre: " << total3ro << endl;
    cout << "Total de estudiantes 4to Semestre: " << total4to << endl;
    cout << "Total de estudiantes 5to Semestre: " << total5to << endl;

    cout << "Total Materias: " << totalMaterias << endl;
    cout << "Monto recaudado: " << totalMaterias * 525;

}
