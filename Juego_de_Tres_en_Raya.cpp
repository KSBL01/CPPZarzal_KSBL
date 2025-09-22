#include <iostream>
using namespace std;

void mostrarTablero(char tablero[3][3]) {
    cout << "\n  1 2 3" << endl;
    for(int i = 0; i < 3; i++) {
        cout << i+1 << " ";
        for(int j = 0; j < 3; j++) {
            cout << tablero[i][j];
            if(j < 2) cout << "|";
        }
        cout << endl;
        if(i < 2) cout << "  -+-+-" << endl;
    }
    cout << endl;
}

bool verificarGanador(char tablero[3][3], char jugador) {
    // Verificar filas y columnas
    for(int i = 0; i < 3; i++) {
        if((tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) ||
           (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)) {
            return true;
        }
    }

    // Verificar diagonales
    if((tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) ||
       (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)) {
        return true;
    }

    return false;
}

bool tableroLleno(char tablero[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tablero[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char tablero[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int fila, columna;
    char jugadorActual = 'X';
    bool juegoActivo = true;

    cout << "=== TRES EN RAYA ===" << endl;
    cout << "Instrucciones: Ingresa fila y columna (1-3)" << endl;

    while(juegoActivo) {
        mostrarTablero(tablero);

        // Pedir movimiento
        cout << "Turno del jugador " << jugadorActual << endl;
        cout << "Fila (1-3): ";
        cin >> fila;
        cout << "Columna (1-3): ";
        cin >> columna;

        // Validar movimiento
        if(fila < 1 || fila > 3 || columna < 1 || columna > 3) {
            cout << "Posicion invalida! Usa numeros del 1 al 3." << endl;
            continue;
        }

        if(tablero[fila-1][columna-1] != ' ') {
            cout << "Casilla ocupada! Elige otra." << endl;
            continue;
        }

        // Hacer movimiento
        tablero[fila-1][columna-1] = jugadorActual;

        // Verificar si hay ganador
        if(verificarGanador(tablero, jugadorActual)) {
            mostrarTablero(tablero);
            cout << "¡Felicidades! Jugador " << jugadorActual << " gana!" << endl;
            juegoActivo = false;
        }
        // Verificar empate
        else if(tableroLleno(tablero)) {
            mostrarTablero(tablero);
            cout << "¡Empate!" << endl;
            juegoActivo = false;
        }
        // Cambiar jugador
        else {
            jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
        }
    }

    cout << "¡Juego terminado!" << endl;
    return 0;
}
