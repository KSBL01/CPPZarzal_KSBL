#include <iostream>
#include <string>
#include <iomanip>



using namespace std;

// Clase base Empleado
class Empleado {
protected:
    string nombreCompleto;
    string numeroEmpleado;
    double salarioBase;

public:
    // Constructor
    Empleado(string nombre, string numEmp, double salario) {
        nombreCompleto = nombre;
        numeroEmpleado = numEmp;

        if (salario >= 0) {
            salarioBase = salario;
        } else {
            salarioBase = 0.0;
            cout << "Salario base invalido. Se establecio $0.00 por defecto" << endl;
        }
    }

    // Getters
    string getNombreCompleto() { return nombreCompleto; }
    string getNumeroEmpleado() { return numeroEmpleado; }
    double getSalarioBase() { return salarioBase; }

    // Setters
    void setNombreCompleto(string nombre) { nombreCompleto = nombre; }
    void setNumeroEmpleado(string numEmp) { numeroEmpleado = numEmp; }

    void setSalarioBase(double salario) {
        if (salario >= 0) {
            salarioBase = salario;
        } else {
            cout << "Error: El salario base no puede ser negativo" << endl;
        }
    }

    // Método virtual para calcular salario total
    virtual double calcularSalarioTotal() {
        return salarioBase;
    }

    // Método virtual para mostrar información
    virtual void mostrarInfo() {
        cout << "=== INFORMACION DEL EMPLEADO ===" << endl;
        cout << "Nombre: " << nombreCompleto << endl;
        cout << "Numero de Empleado: " << numeroEmpleado << endl;
        cout << "Salario Base: $" << fixed << setprecision(2) << salarioBase << endl;
    }
};

// Clase EmpleadoTiempoCompleto que hereda de Empleado
class EmpleadoTiempoCompleto : public Empleado {
private:
    string beneficios;
    double bono;

public:
    // Constructor
    EmpleadoTiempoCompleto(string nombre, string numEmp, double salario,
                          string benef, double bonus)
        : Empleado(nombre, numEmp, salario) {

        beneficios = benef;

        if (bonus >= 0) {
            bono = bonus;
        } else {
            bono = 0.0;
            cout << "Bono invalido. Se establecio $0.00 por defecto" << endl;
        }
    }

    // Getters
    string getBeneficios() { return beneficios; }
    double getBono() { return bono; }

    // Setters
    void setBeneficios(string benef) {
        beneficios = benef;
    }

    void setBono(double bonus) {
        if (bonus >= 0) {
            bono = bonus;
        } else {
            cout << "Error: El bono no puede ser negativo" << endl;
        }
    }

    // Override del método calcularSalarioTotal
    double calcularSalarioTotal() override {
        return salarioBase + bono;
    }

    // Override del método mostrarInfo
    void mostrarInfo() override {
        Empleado::mostrarInfo();
        cout << "Tipo: Tiempo Completo" << endl;
        cout << "Beneficios: " << beneficios << endl;
        cout << "Bono: $" << fixed << setprecision(2) << bono << endl;
        cout << "Salario Total: $" << fixed << setprecision(2) << calcularSalarioTotal() << endl;
        cout << "=================================" << endl;
    }
};

// Clase EmpleadoPorHoras que hereda de Empleado
class EmpleadoPorHoras : public Empleado {
private:
    int horasTrabajadas;
    double tarifaPorHora;

public:
    // Constructor
    EmpleadoPorHoras(string nombre, string numEmp, double salario,
                    int horas, double tarifa)
        : Empleado(nombre, numEmp, salario) {

        if (horas >= 0) {
            horasTrabajadas = horas;
        } else {
            horasTrabajadas = 0;
            cout << "Horas trabajadas invalidas. Se establecio 0 por defecto" << endl;
        }

        if (tarifa >= 0) {
            tarifaPorHora = tarifa;
        } else {
            tarifaPorHora = 0.0;
            cout << "Tarifa por hora invalida. Se establecio $0.00 por defecto" << endl;
        }
    }

    // Getters
    int getHorasTrabajadas() { return horasTrabajadas; }
    double getTarifaPorHora() { return tarifaPorHora; }

    // Setters
    void setHorasTrabajadas(int horas) {
        if (horas >= 0) {
            horasTrabajadas = horas;
        } else {
            cout << "Error: Las horas trabajadas no pueden ser negativas" << endl;
        }
    }

    void setTarifaPorHora(double tarifa) {
        if (tarifa >= 0) {
            tarifaPorHora = tarifa;
        } else {
            cout << "Error: La tarifa por hora no puede ser negativa" << endl;
        }
    }

    // Override del método calcularSalarioTotal
    double calcularSalarioTotal() override {
        return horasTrabajadas * tarifaPorHora;
    }

    // Override del método mostrarInfo
    void mostrarInfo() override {
        Empleado::mostrarInfo();
        cout << "Tipo: Por Horas" << endl;
        cout << "Horas Trabajadas: " << horasTrabajadas << endl;
        cout << "Tarifa por Hora: $" << fixed << setprecision(2) << tarifaPorHora << endl;
        cout << "Salario Total: $" << fixed << setprecision(2) << calcularSalarioTotal() << endl;
        cout << "=================================" << endl;
    }
};

// Función principal para probar las clases
int main() {
    cout << "SISTEMA DE GESTION DE EMPLEADOS" << endl << endl;

    // Crear empleados según el ejemplo
    EmpleadoTiempoCompleto emp1("Juan Lopez", "001", 2000, "Seguro medico", 500);
    EmpleadoPorHoras emp2("Maria Garcia", "002", 0, 40, 15);

    // Mostrar información de los empleados
    cout << "--- EMPLEADO TIEMPO COMPLETO ---" << endl;
    emp1.mostrarInfo();

    cout << "\n--- EMPLEADO POR HORAS ---" << endl;
    emp2.mostrarInfo();

    // Probar métodos específicos
    cout << "\n--- CALCULOS DE SALARIO ---" << endl;
    cout << "Emp1 - Salario Total: $" << emp1.calcularSalarioTotal() << endl;
    cout << "Emp2 - Salario Total: $" << emp2.calcularSalarioTotal() << endl;

    // Probar modificaciones
    cout << "\n--- MODIFICANDO EMPLEADOS ---" << endl;
    emp1.setBono(600);
    emp1.setBeneficios("Seguro medico, Vacaciones pagadas");

    emp2.setHorasTrabajadas(45);
    emp2.setTarifaPorHora(16.5);

    cout << "\n--- INFORMACION ACTUALIZADA ---" << endl;
    emp1.mostrarInfo();
    emp2.mostrarInfo();

    // Probar getters
    cout << "\n--- PROBANDO GETTERS ---" << endl;
    cout << "Emp1 - Nombre: " << emp1.getNombreCompleto() << endl;
    cout << "Emp1 - Beneficios: " << emp1.getBeneficios() << endl;
    cout << "Emp2 - Horas Trabajadas: " << emp2.getHorasTrabajadas() << endl;
    cout << "Emp2 - Tarifa por Hora: $" << emp2.getTarifaPorHora() << endl;

    // Probar validaciones
    cout << "\n--- PROBANDO VALIDACIONES ---" << endl;
    emp1.setBono(-100);
    emp2.setHorasTrabajadas(-10);
    emp2.setTarifaPorHora(-5.0);

    return 0;
}
