
//solucion a la primera parte del parcial:
    //1:B
    //2:B
    //3:B
    //4:C
    //5:B
    //6:C
    //7:A
    //8:B
    //9:B
    //10:A
//solucion a la segunda parte del parcial:

    //1:11
    //2:0 1 2
    //3:par
    //4:321
    //5:2 200

//solucion a la tercera parte del parcial:


#include <iostream>
#include <string>

using namespace std;



    int max3(int a, int b, int c);
    int sumaRango(int a, int b);
    bool contieneDigito(int n, int d);
    void tablaMultiplicar(int n);

    //c1)mayor de tres enteros


    int max3(int a, int b, int c) {
        if (a >= b && a >= c) {
            return a;
        } else if (b >= a && b >= c) {
            return b;
        } else {
            return c;
        }
    }


    //c2) suma de todos los enteros en [a, b] (se asume a <= b) usando un bucle.

    int sumaRango(int a, int b) {
        int suma = 0;
        for (int i = a; i <= b; i++) {
            suma += i;
        }
        return suma;
    }


    //c3) Devuelve true si n (no negativo) contiene el dígito d (0–9). Usa operadores aritméticos

    bool contieneDigito(int n, int d) {
        if (n == 0 && d == 0) return true;

        while (n > 0) {
            if (n % 10 == d) {
                return true;
            }
            n /= 10;
        }
        return false;
    }

    //c4) Imprime la tabla de n del 1 al 10 con el formato exacto: n x i = resultado (un renglón por i).
    void tablaMultiplicar(int n) {
        for (int i = 1; i <= 10; i++) {
            cout << n << " x " << i << " = " << (n * i) << endl;
        }
    }

    int main(){


    return 0;
    }

    //si se pregunta por que puse las respuestas aqui tambien es porque tenia dudas no especifico si habia que entregarlo en docx o en cpp xd
