#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int NumeroAleatorio(int min, int max);
void SimularVotacion(int n, vector<int>& CIRegistrados, vector<string>& nombresVotantes, vector<int>& votos);
string GenerarNombreCompleto();
void MostrarVectorInt(vector<int> vec, string descripcion);
void MostrarVectorString(vector<string> vec, string descripcion);
void MostrarResultadosOficiales(vector<int> votos, vector<string> candidatos);
void MostrarPorcentajePartidos(vector<int> votos, vector<string> candidatos);
int TotalVotosValidos(vector<int> votos);
int ContarVotantesPDCconA(vector<string> nombresVotantes, vector<int> votos);
bool EncontrarLetra(string nombre, char letra);

int main()
{
    int n = 0;
    vector<string> candidatos = {"Libre", "PDC", "Blanco", "Nulo"};
    vector<int> CIRegistrados;
    vector<string> nombresVotantes;
    vector<int> votos(4,0);

    srand(time(0)); // Inicializar la semilla
    cout << "Ingrese la cantidad votos que quiere simular: ";
    cin >> n;
    SimularVotacion(n, CIRegistrados, nombresVotantes, votos);
    cout << "\nResultados de la votacion:\n";
    MostrarVectorInt(CIRegistrados, "CI " );
    MostrarVectorString(nombresVotantes, "Nombre votante ");
    MostrarResultadosOficiales(votos, candidatos);
    MostrarPorcentajePartidos(votos, candidatos);
    cout << "El numero de personas que tienen la letra A es: " << ContarVotantesPDCconA(nombresVotantes, votos);
    return 0;
}

void SimularVotacion(int n, vector<int>& CIRegistrados, vector<string>& nombresVotantes, vector<int>& votos)
{
    int voto = 0;
    for (int i = 1; i <= n; i++)
    {
        CIRegistrados.push_back(NumeroAleatorio(10000 , 99999));
        nombresVotantes.push_back(GenerarNombreCompleto());
        voto = NumeroAleatorio(0, 3);
        votos[voto]++;
    }   
}

string GenerarNombreCompleto()
{
    vector<string> nombres = {"Carlos", "Maria", "Jose", "Ana", "Luis", "Carmen", "Jorge", "Elena", "Ricardo", "Sofia"};
    vector<string> apellidos = {"Garcia", "Lopez", "Medina", "Rocha", "Quispe", "Perez", "Sanchez", "Ramirez", "Torrez", "Herrera"};
    string nombre = nombres[NumeroAleatorio(0, nombres.size() - 1)] + " " + apellidos[NumeroAleatorio(0, apellidos.size() - 1)]  + " " + apellidos[NumeroAleatorio(0, apellidos.size() - 1)];
    return nombre;
}

int NumeroAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void MostrarVectorInt(vector<int> vec, string descripcion)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << descripcion << i << ": " << vec[i] << endl;
    }
}

void MostrarVectorString(vector<string> vec, string descripcion)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << descripcion << i << ": " << vec[i] << endl;
    }
}

void MostrarResultadosOficiales(vector<int> votos, vector<string> candidatos)
{
    cout << "\nResultados Oficiales de la Votacion\n";
    cout << "====================================\n";
    for (int i = 0; i < votos.size(); i++)
    {
        cout << "Candidato: " << candidatos[i] << " - Votos: " << votos[i] << endl;
    }
}

void MostrarPorcentajePartidos(vector<int> votos, vector<string> candidatos)
{
    int totalVotosValidos = TotalVotosValidos(votos);
    cout << "\nPorcentaje de Votos por Partido\n";
    cout << "=================================\n";
    for (int i = 0; i < votos.size(); i++)
    {
        if (i == 0 || i == 1)
        {
            double porcentaje = (static_cast<double>(votos[i]) / totalVotosValidos) * 100;
            cout << "Candidato: " << candidatos[i] << " - Porcentaje: " << porcentaje << "%" << endl;
        }
    }
}

int TotalVotosValidos(vector<int> votos)
{
    int total = 0;
    for (int i = 0; i < votos.size(); i++)
    {
        if (i == 0 || i == 1)
        {
            total += votos[i];
        }
    }
    return total;
}

int ContarVotantesPDCconA(vector<string> nombresVotantes, vector<int> votos)
{
    int contador = 0;
    for (int i = 0; i < nombresVotantes.size(); ++i)
    {
        if (votos[i] == 1)
        {
            if (EncontrarLetra(nombresVotantes[i], 'A') || EncontrarLetra(nombresVotantes[i], 'a'))
            {
                contador++;
            }
        }
    }
    return contador;
}

bool EncontrarLetra(string nombre, char letra)
{
    for (int i = 0; i < nombre.length(); ++i)
    {
        if (nombre[i] == 'a' || nombre[i] == 'A')
        {
            return true;
        }
    }
    return false;
}