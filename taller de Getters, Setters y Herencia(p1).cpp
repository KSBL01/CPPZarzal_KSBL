#include <iostream>
#include <string>



using namespace std;

class Vehiculo {
private:
    string marca;
    string modelo;
    int año;
    double velocidadMaxima;

public:
    // Constructor que inicializa todos los atributos
    Vehiculo(string m, string mod, int a, double velMax) {
        marca = m;
        modelo = mod;

        // Validación para el año en el constructor
        if (a > 1886) {
            año = a;
        } else {
            año = 1887; // Valor por defecto si no es válido
            cout << "Año inválido. Se estableció el año por defecto: 1887" << endl;
        }

        // Validación para la velocidad máxima en el constructor
        if (velMax > 0) {
            velocidadMaxima = velMax;
        } else {
            velocidadMaxima = 1.0; // Valor por defecto si no es válido
            cout << "Velocidad máxima inválida. Se estableció 1.0 km/h por defecto" << endl;
        }
    }

    // Getters
    string getMarca() {
        return marca;
    }

    string getModelo() {
        return modelo;
    }

    int getAño() {
        return año;
    }

    double getVelocidadMaxima() {
        return velocidadMaxima;
    }

    // Setters con validaciones
    void setMarca(string m) {
        marca = m;
    }

    void setModelo(string mod) {
        modelo = mod;
    }

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
            cout << "Error: La velocidad máxima debe ser positiva" << endl;
        }
    }

    // Método para mostrar información
    void mostrarInfo() {
        cout << "=== INFORMACIÓN DEL VEHÍCULO ===" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << año << endl;
        cout << "Velocidad Máxima: " << velocidadMaxima << " km/h" << endl;
        cout << "=================================" << endl;
    }

    // Método para acelerar (aumentar velocidad máxima)
    void acelerar(double incremento) {
        if (incremento > 0) {
            velocidadMaxima += incremento;
            cout << "¡Acelerando! Nueva velocidad máxima: " << velocidadMaxima << " km/h" << endl;
        } else {
            cout << "Error: El incremento debe ser positivo" << endl;
        }
    }
};

// Función principal para probar la clase
int main() {
    cout << "=== PRUEBA DE LA CLASE VEHICULO ===" << endl;
    cout << endl;

    // Crear un vehículo
    Vehiculo miAuto("Toyota", "Corolla", 2022, 180.5);

    // Mostrar información inicial
    miAuto.mostrarInfo();

    // Probar setters con datos válidos
    cout << "\n--- Probando setters válidos ---" << endl;
    miAuto.setAño(2023);
    miAuto.setVelocidadMaxima(190.0);
    miAuto.mostrarInfo();

    // Probar setters con datos inválidos
    cout << "\n--- Probando setters inválidos ---" << endl;
    miAuto.setAño(1800);  // Año inválido
    miAuto.setVelocidadMaxima(-50);  // Velocidad inválida

    // Probar método acelerar
    cout << "\n--- Probando método acelerar ---" << endl;
    miAuto.acelerar(15.5);
    miAuto.mostrarInfo();

    // Probar acelerar con incremento inválido
    cout << "\n--- Probando acelerar inválido ---" << endl;
    miAuto.acelerar(-10);

    // Probar getters
    cout << "\n--- Probando getters ---" << endl;
    cout << "Marca: " << miAuto.getMarca() << endl;
    cout << "Modelo: " << miAuto.getModelo() << endl;
    cout << "Año: " << miAuto.getAño() << endl;
    cout << "Velocidad Máxima: " << miAuto.getVelocidadMaxima() << " km/h" << endl;

    return 0;
}
