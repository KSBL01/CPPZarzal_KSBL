#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "=== ELEMENTOS DUPLICADOS ===" << endl;
    cout << "Cuantos numeros quieres ingresar? ";
    cin >> n;

    int numeros[n];

    // Leer números
    cout << "Ingresa " << n << " numeros:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Numero " << (i+1) << ": ";
        cin >> numeros[i];
    }

    // Buscar duplicados
    cout << "\nElementos duplicados encontrados:" << endl;
    bool hayDuplicados = false;

    for(int i = 0; i < n; i++) {
        bool esDuplicado = false;

        // Verificar si ya contamos este número
        for(int k = 0; k < i; k++) {
            if(numeros[k] == numeros[i]) {
                esDuplicado = true;
                break;
            }
        }

        if(!esDuplicado) {
            // Contar cuántas veces aparece
            int contador = 0;
            for(int j = i; j < n; j++) {
                if(numeros[i] == numeros[j]) {
                    contador++;
                }
            }

            if(contador > 1) {
                cout << "Numero " << numeros[i] << " aparece " << contador << " veces" << endl;
                hayDuplicados = true;
            }
        }
    }

    if(!hayDuplicados) {
        cout << "No se encontraron elementos duplicados" << endl;
    }

    return 0;
}
