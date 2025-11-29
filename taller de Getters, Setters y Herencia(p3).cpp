#include <iostream>
#include <string>



using namespace std;

// Clase base Vehiculo
class Vehiculo {
protected:
    string marca;
    string modelo;
    int año;
    double velocidadMaxima;

public:
    // Constructor
    Vehiculo(string m, string mod, int a, double velMax) {
        marca = m;
        modelo = mod;

        if (a > 1886) {
            año = a;
        } else {
            año = 1887;
            cout << "Año invalido. Se establecio el año por defecto: 1887" << endl;
        }

        if (velMax > 0) {
            velocidadMaxima = velMax;
        } else {
            velocidadMaxima = 1.0;
            cout << "Velocidad maxima invalida. Se establecio 1.0 km/h por defecto" << endl;
        }
    }

    // Getters
    string getMarca() { return marca; }
    string getModelo() { return modelo; }
    int getAño() { return año; }
    double getVelocidadMaxima() { return velocidadMaxima; }

    // Setters
    void setMarca(string m) { marca = m; }
    void setModelo(string mod) { modelo = mod; }

    void setAño(int a) {
        if (a > 1886) {
            año = a;
        } else {
            cout << "Error: El año debe ser mayor a 1886" << endl;
        }
    }

    void setVelocidadMaxima(double velMax) {
        if (velMax > 0) {
            velocidadMaxima = velMax;
        } else {
            cout << "Error: La velocidad maxima debe ser positiva" << endl;
        }
    }

    // Método virtual para mostrar información
    virtual void mostrarInfo() {
        cout << "=== INFORMACION DEL VEHICULO ===" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << año << endl;
        cout << "Velocidad Maxima: " << velocidadMaxima << " km/h" << endl;
    }

    // Método para acelerar
    void acelerar(double incremento) {
        if (incremento > 0) {
            velocidadMaxima += incremento;
            cout << "Acelerando! Nueva velocidad maxima: " << velocidadMaxima << " km/h" << endl;
        } else {
            cout << "Error: El incremento debe ser positivo" << endl;
        }
    }
};

// Clase Auto que hereda de Vehiculo
class Auto : public Vehiculo {
private:
    int numeroPuertas;
    string tipoCombustible;

public:
    // Constructor
    Auto(string m, string mod, int a, double velMax, int puertas, string combustible)
        : Vehiculo(m, mod, a, velMax) {

        if (puertas > 0) {
            numeroPuertas = puertas;
        } else {
            numeroPuertas = 4;
            cout << "Numero de puertas invalido. Se establecio 4 por defecto" << endl;
        }

        tipoCombustible = combustible;
    }

    // Getters
    int getNumeroPuertas() { return numeroPuertas; }
    string getTipoCombustible() { return tipoCombustible; }

    // Setters
    void setNumeroPuertas(int puertas) {
        if (puertas > 0) {
            numeroPuertas = puertas;
        } else {
            cout << "Error: El numero de puertas debe ser positivo" << endl;
        }
    }

    void setTipoCombustible(string combustible) {
        tipoCombustible = combustible;
    }

    // Override del método mostrarInfo
    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Tipo: Auto" << endl;
        cout << "Numero de Puertas: " << numeroPuertas << endl;
        cout << "Tipo de Combustible: " << tipoCombustible << endl;
        cout << "=================================" << endl;
    }
};

// Clase Motocicleta que hereda de Vehiculo
class Motocicleta : public Vehiculo {
private:
    bool tieneAleron;
    int cilindrada;

public:
    // Constructor
    Motocicleta(string m, string mod, int a, double velMax, bool aleron, int cilind)
        : Vehiculo(m, mod, a, velMax) {

        tieneAleron = aleron;

        if (cilind > 0) {
            cilindrada = cilind;
        } else {
            cilindrada = 125;
            cout << "Cilindrada invalida. Se establecio 125 cc por defecto" << endl;
        }
    }

    // Getters
    bool getTieneAleron() { return tieneAleron; }
    int getCilindrada() { return cilindrada; }

    // Setters
    void setTieneAlaron(bool aleron) {
        tieneAleron = aleron;
    }

    void setCilindrada(int cilind) {
        if (cilind > 0) {
            cilindrada = cilind;
        } else {
            cout << "Error: La cilindrada debe ser positiva" << endl;
        }
    }

    // Override del método mostrarInfo
    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Tipo: Motocicleta" << endl;
        cout << "Tiene Aleron: " << (tieneAleron ? "Si" : "No") << endl;
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
        cout << "=================================" << endl;
    }
};

// Función principal para probar las clases
int main() {
    cout << "PRUEBA DE HERENCIA - VEHICULOS" << endl << endl;

    // Crear un Auto
    Auto miAuto("Ferrari", "F40", 1992, 320, 2, "Gasolina");

    // Crear una Motocicleta
    Motocicleta miMoto("Himalayan", "Royal-Enfield", 2016, 155, true, 411);

    // Mostrar información de ambos vehículos
    cout << "--- INFORMACION DEL AUTO ---" << endl;
    miAuto.mostrarInfo();

    cout << "\n--- INFORMACION DE LA MOTOCICLETA ---" << endl;
    miMoto.mostrarInfo();

    // Probar setters en el Auto
    cout << "\n--- MODIFICANDO EL AUTO ---" << endl;
    miAuto.setNumeroPuertas(2);
    miAuto.setTipoCombustible("Electrico");
    miAuto.setVelocidadMaxima(250);
    miAuto.mostrarInfo();

    // Probar setters en la Motocicleta
    cout << "\n--- MODIFICANDO LA MOTOCICLETA ---" << endl;
    miMoto.setTieneAlaron(false);
    miMoto.setCilindrada(1500);
    miMoto.acelerar(25);
    miMoto.mostrarInfo();

    // Probar getters
    cout << "\n--- PROBANDO GETTERS ---" << endl;
    cout << "Auto - Marca: " << miAuto.getMarca() << endl;
    cout << "Auto - Puertas: " << miAuto.getNumeroPuertas() << endl;
    cout << "Moto - Cilindrada: " << miMoto.getCilindrada() << " cc" << endl;
    cout << "Moto - Tiene aleron: " << (miMoto.getTieneAleron() ? "Si" : "No") << endl;

    // Probar validaciones
    cout << "\n--- PROBANDO VALIDACIONES ---" << endl;
    miAuto.setNumeroPuertas(-2);
    miMoto.setCilindrada(-100);

    return 0;
}
