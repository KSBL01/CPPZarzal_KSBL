#include <iostream>
#include <string>
#include <iomanip>



using namespace std;

class Producto {
private:
    string codigo;
    string nombre;
    double precio;
    int cantidad;

public:
    // Constructor que inicializa todos los atributos
    Producto(string cod, string nom, double prec, int cant) {
        codigo = cod;
        nombre = nom;

        // Validación para el precio
        if (prec >= 0) {
            precio = prec;
        } else {
            precio = 0.0;
            cout << "Precio inválido. Se estableció $0.00 por defecto" << endl;
        }

        // Validación para la cantidad
        if (cant >= 0) {
            cantidad = cant;
        } else {
            cantidad = 0;
            cout << "Cantidad inválida. Se estableció 0 por defecto" << endl;
        }
    }

    // Getters
    string getCodigo() {
        return codigo;
    }

    string getNombre() {
        return nombre;
    }

    double getPrecio() {
        return precio;
    }

    int getCantidad() {
        return cantidad;
    }

    // Setters con validaciones
    void setCodigo(string cod) {
        codigo = cod;
    }

    void setNombre(string nom) {
        nombre = nom;
    }

    void setPrecio(double prec) {
        if (prec >= 0) {
            precio = prec;
        } else {
            cout << "Error: El precio no puede ser negativo" << endl;
        }
    }

    void setCantidad(int cant) {
        if (cant >= 0) {
            cantidad = cant;
        } else {
            cout << "Error: La cantidad no puede ser negativa" << endl;
        }
    }

    // Método para calcular el valor total del inventario
    double calcularValorTotal() {
        return precio * cantidad;
    }

    // Método para aplicar descuento al precio
    void aplicarDescuento(double porcentaje) {
        if (porcentaje >= 0 && porcentaje <= 100) {
            double descuento = precio * (porcentaje / 100);
            precio -= descuento;
            cout << " Descuento del " << porcentaje << "% aplicado." << endl;
            cout << " Nuevo precio: $" << fixed << setprecision(2) << precio << endl;
        } else {
            cout << "Error: El porcentaje de descuento debe estar entre 0 y 100" << endl;
        }
    }

    // Método para mostrar información del producto
    void mostrarInfo() {
        cout << "\nINFORMACIÓN DEL PRODUCTO" << endl;
        cout << "────────────────────────────" << endl;
        cout << "Código: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: $" << fixed << setprecision(2) << precio << endl;
        cout << "Cantidad: " << cantidad << " unidades" << endl;
        cout << "Valor total: $" << fixed << setprecision(2) << calcularValorTotal() << endl;
        cout << "────────────────────────────" << endl;
    }
};

// Función principal para probar la clase
int main() {
    cout << "SISTEMA DE GESTION DE PRODUCTOS " << endl << endl;

    // Crear un producto según el ejemplo
    Producto laptop("001", "Laptop HP", 850.00, 5);

    // Mostrar información inicial
    laptop.mostrarInfo();

    // Calcular y mostrar valor total
    cout << "Valor total del inventario: $" << fixed << setprecision(2)
         << laptop.calcularValorTotal() << endl;

    // Aplicar descuento del 10%
    cout << "\nAplicando descuento del 10%" << endl;
    laptop.aplicarDescuento(10);

    // Mostrar información después del descuento
    laptop.mostrarInfo();

    // Probar más funcionalidades
    cout << "\nPROBANDO MÁS FUNCIONALIDADES:" << endl;

    // Probar setters válidos
    cout << "\n--- Setters válidos ---" << endl;
    laptop.setPrecio(800.00);
    laptop.setCantidad(8);
    laptop.mostrarInfo();

    // Probar setters inválidos
    cout << "\n--- Setters inválidos ---" << endl;
    laptop.setPrecio(-100.00);
    laptop.setCantidad(-5);

    // Probar descuento inválido
    cout << "\n--- Descuento inválido ---" << endl;
    laptop.aplicarDescuento(150);

    // Probar getters
    cout << "\n--- Probando getters ---" << endl;
    cout << "Código: " << laptop.getCodigo() << endl;
    cout << "Nombre: " << laptop.getNombre() << endl;
    cout << "Precio: $" << laptop.getPrecio() << endl;
    cout << "Cantidad: " << laptop.getCantidad() << endl;

    // Crear otro producto para más pruebas
    cout << "\nCREANDO OTRO PRODUCTO:" << endl;
    Producto telefono("002", "iPhone 15", 1200.00, 3);
    telefono.mostrarInfo();
    telefono.aplicarDescuento(15);
    telefono.mostrarInfo();

    return 0;
}
