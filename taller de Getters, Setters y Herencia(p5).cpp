#include <iostream>
#include <string>
#include <iomanip>



using namespace std;

// Clase base Animal
class Animal {
protected:
    string nombre;
    int edad;
    double peso;

public:
    // Constructor
    Animal(string nom, int ed, double pes) {
        nombre = nom;

        if (ed >= 0) {
            edad = ed;
        } else {
            edad = 0;
            cout << "Edad invalida. Se establecio 0 por defecto" << endl;
        }

        if (pes >= 0) {
            peso = pes;
        } else {
            peso = 0.0;
            cout << "Peso invalido. Se establecio 0.0 por defecto" << endl;
        }
    }

    // Getters
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    double getPeso() { return peso; }

    // Setters
    void setNombre(string nom) { nombre = nom; }

    void setEdad(int ed) {
        if (ed >= 0) {
            edad = ed;
        } else {
            cout << "Error: La edad no puede ser negativa" << endl;
        }
    }

    void setPeso(double pes) {
        if (pes >= 0) {
            peso = pes;
        } else {
            cout << "Error: El peso no puede ser negativo" << endl;
        }
    }

    // Métodos virtuales
    virtual void hacerSonido() {
        cout << "El animal hace un sonido generico" << endl;
    }

    virtual void mostrarInfo() {
        cout << "=== INFORMACION DEL ANIMAL ===" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Peso: " << fixed << setprecision(2) << peso << " kg" << endl;
    }
};

// Clase intermedia Mamifero hereda de Animal
class Mamifero : public Animal {
protected:
    bool tieneColaMamifero;

public:
    // Constructor
    Mamifero(string nom, int ed, double pes, bool cola)
        : Animal(nom, ed, pes) {
        tieneColaMamifero = cola;
    }

    // Getters y Setters
    bool getTieneColaMamifero() { return tieneColaMamifero; }
    void setTieneColaMamifero(bool cola) { tieneColaMamifero = cola; }

    // Override de métodos
    void hacerSonido() override {
        cout << "El mamifero emite un sonido caracteristico" << endl;
    }

    void mostrarInfo() override {
        Animal::mostrarInfo();
        cout << "Tipo: Mamifero" << endl;
        cout << "Tiene cola: " << (tieneColaMamifero ? "Si" : "No") << endl;
    }
};

// Clase intermedia Ave hereda de Animal
class Ave : public Animal {
protected:
    double envergaduraAlas;

public:
    // Constructor
    Ave(string nom, int ed, double pes, double envergadura)
        : Animal(nom, ed, pes) {

        if (envergadura >= 0) {
            envergaduraAlas = envergadura;
        } else {
            envergaduraAlas = 0.0;
            cout << "Envergadura invalida. Se establecio 0.0 por defecto" << endl;
        }
    }

    // Getters y Setters
    double getEnvergaduraAlas() { return envergaduraAlas; }

    void setEnvergaduraAlas(double envergadura) {
        if (envergadura >= 0) {
            envergaduraAlas = envergadura;
        } else {
            cout << "Error: La envergadura no puede ser negativa" << endl;
        }
    }

    // Override de métodos
    void hacerSonido() override {
        cout << "El ave emite un sonido caracteristico" << endl;
    }

    void mostrarInfo() override {
        Animal::mostrarInfo();
        cout << "Tipo: Ave" << endl;
        cout << "Envergadura de alas: " << fixed << setprecision(2) << envergaduraAlas << " cm" << endl;
    }
};

// Clase final Perro hereda de Mamifero
class Perro : public Mamifero {
private:
    string raza;

public:
    // Constructor
    Perro(string nom, int ed, double pes, bool cola, string raz)
        : Mamifero(nom, ed, pes, cola) {
        raza = raz;
    }

    // Getters y Setters
    string getRaza() { return raza; }
    void setRaza(string raz) { raza = raz; }

    // Override de métodos
    void hacerSonido() override {
        cout << nombre << " dice: ¡Guau guau!" << endl;
    }

    void mostrarInfo() override {
        Mamifero::mostrarInfo();
        cout << "Especie: Perro" << endl;
        cout << "Raza: " << raza << endl;
        cout << "=================================" << endl;
    }
};

// Clase final Gato hereda de Mamifero
class Gato : public Mamifero {
private:
    string colorPelaje;

public:
    // Constructor
    Gato(string nom, int ed, double pes, bool cola, string color)
        : Mamifero(nom, ed, pes, cola) {
        colorPelaje = color;
    }

    // Getters y Setters
    string getColorPelaje() { return colorPelaje; }
    void setColorPelaje(string color) { colorPelaje = color; }

    // Override de métodos
    void hacerSonido() override {
        cout << nombre << " dice: ¡Miau miau!" << endl;
    }

    void mostrarInfo() override {
        Mamifero::mostrarInfo();
        cout << "Especie: Gato" << endl;
        cout << "Color de pelaje: " << colorPelaje << endl;
        cout << "=================================" << endl;
    }
};

// Clase final Loro hereda de Ave
class Loro : public Ave {
private:
    bool puedeHablar;

public:
    // Constructor
    Loro(string nom, int ed, double pes, double envergadura, bool hablar)
        : Ave(nom, ed, pes, envergadura) {
        puedeHablar = hablar;
    }

    // Getters y Setters
    bool getPuedeHablar() { return puedeHablar; }
    void setPuedeHablar(bool hablar) { puedeHablar = hablar; }

    // Override de métodos
    void hacerSonido() override {
        if (puedeHablar) {
            cout << nombre << " dice: ¡Hola! Soy un loro parlanchin!" << endl;
        } else {
            cout << nombre << " hace: ¡Graaac graaac!" << endl;
        }
    }

    void mostrarInfo() override {
        Ave::mostrarInfo();
        cout << "Especie: Loro" << endl;
        cout << "Puede hablar: " << (puedeHablar ? "Si" : "No") << endl;
        cout << "=================================" << endl;
    }
};

// Clase final Aguila hereda de Ave
class Aguila : public Ave {
private:
    double velocidadVuelo;

public:
    // Constructor
    Aguila(string nom, int ed, double pes, double envergadura, double velocidad)
        : Ave(nom, ed, pes, envergadura) {

        if (velocidad >= 0) {
            velocidadVuelo = velocidad;
        } else {
            velocidadVuelo = 0.0;
            cout << "Velocidad invalida. Se establecio 0.0 por defecto" << endl;
        }
    }

    // Getters y Setters
    double getVelocidadVuelo() { return velocidadVuelo; }

    void setVelocidadVuelo(double velocidad) {
        if (velocidad >= 0) {
            velocidadVuelo = velocidad;
        } else {
            cout << "Error: La velocidad no puede ser negativa" << endl;
        }
    }

    // Override de métodos
    void hacerSonido() override {
        cout << nombre << " emite: ¡Kiiii kiiii!" << endl;
    }

    void mostrarInfo() override {
        Ave::mostrarInfo();
        cout << "Especie: Aguila" << endl;
        cout << "Velocidad de vuelo: " << fixed << setprecision(2) << velocidadVuelo << " km/h" << endl;
        cout << "=================================" << endl;
    }
};

// Función principal para probar la jerarquía
int main() {
    cout << "JERARQUIA DE ANIMALES - HERENCIA MULTINIVEL" << endl << endl;

    // Crear animales de diferentes tipos
    Perro miPerro("Rex", 5, 25.5, true, "Labrador");
    Gato miGato("Mimi", 3, 4.2, true, "Negro");
    Loro miLoro("Paco", 2, 0.5, 30.0, true);
    Aguila miAguila("Thor", 4, 6.8, 200.0, 160.0);

    // Mostrar información de todos los animales
    cout << "--- INFORMACION DE LOS ANIMALES ---" << endl;
    miPerro.mostrarInfo();
    miGato.mostrarInfo();
    miLoro.mostrarInfo();
    miAguila.mostrarInfo();

    // Probar el método hacerSonido
    cout << "--- SONIDOS DE LOS ANIMALES ---" << endl;
    miPerro.hacerSonido();
    miGato.hacerSonido();
    miLoro.hacerSonido();
    miAguila.hacerSonido();

    // Probar modificaciones
    cout << "\n--- MODIFICANDO ANIMALES ---" << endl;
    miPerro.setEdad(6);
    miPerro.setPeso(28.0);

    miGato.setColorPelaje("Blanco y negro");

    miLoro.setPuedeHablar(false);
    miLoro.setEnvergaduraAlas(32.5);

    miAguila.setVelocidadVuelo(180.0);

    // Mostrar información actualizada
    cout << "\n--- INFORMACION ACTUALIZADA ---" << endl;
    miPerro.mostrarInfo();
    miGato.mostrarInfo();
    miLoro.mostrarInfo();
    miAguila.mostrarInfo();

    // Probar polimorfismo con punteros a la clase base
    cout << "\n--- POLIMORFISMO CON CLASE BASE ---" << endl;
    Animal* animales[] = {&miPerro, &miGato, &miLoro, &miAguila};

    for (int i = 0; i < 4; i++) {
        animales[i]->hacerSonido();
    }

    return 0;
}
