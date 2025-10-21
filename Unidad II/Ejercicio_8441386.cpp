// SAMUEL ANDRES CASTAÑETA ARGOLLO

#include <iostream>
using namespace std;

void mostrarTablero(char tablero[3][3]) {
  cout << endl;
  cout << "     0   1   2 " << endl;
  cout << "   -------------" << endl;

  for (int i = 0; i < 3; i++) {
    cout << " " << i << " | ";
    for (int j = 0; j < 3; j++) {
      cout << tablero[i][j];
      if (j < 2)
        cout << " | ";
    }
    cout << endl;
    if (i < 2)
      cout << "   -------------" << endl;
  }
  cout << endl;
}

char verificarGanador(char tablero[3][3]) {

  for (int i = 0; i < 3; i++) {
    if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] &&
        tablero[i][0] != ' ')
      return tablero[i][0];
    if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] &&
        tablero[0][i] != ' ')
      return tablero[0][i];
  }
  if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] &&
      tablero[0][0] != ' ')
    return tablero[0][0];
  if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] &&
      tablero[0][2] != ' ')
    return tablero[0][2];

  return ' ';
}
int main() {
  char tablero[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

  int fila, columna;
  char jugadorActual = 'X';
  int turnos = 0;

  cout << "=== TRES EN RAYA (Jugador 1 = X, Jugador 2 = O) ===\n";
  mostrarTablero(tablero);
  while (true) {
    cout << "Turno del Jugador " << ((jugadorActual == 'X') ? 1 : 2) << " ("
         << jugadorActual << ")" << endl;
    cout << "Introduce fila (0-2): ";
    cin >> fila;
    cout << "Introduce columna (0-2): ";
    cin >> columna;
    if (fila < 0 || fila > 2 || columna < 0 || columna > 2) {
      cout << " Posición fuera de rango. Intenta de nuevo." << endl;
      continue;
    }
    if (tablero[fila][columna] != ' ') {
      cout << " Esa posición ya está ocupada. Intenta de nuevo.\n";
      continue;
    }
    tablero[fila][columna] = jugadorActual;
    turnos++;
    mostrarTablero(tablero);
    char ganador = verificarGanador(tablero);
    if (ganador != ' ') {
      cout << " ¡Jugador " << ((ganador == 'X') ? 1 : 2) << " (" << ganador
           << ") gana!\n";
      break;
    }
    if (turnos == 9) {
      cout << " ¡Empate!\n";
      break;
    }
    jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
  }

  cout << "\nFin del juego." << endl;
  return 0;
}