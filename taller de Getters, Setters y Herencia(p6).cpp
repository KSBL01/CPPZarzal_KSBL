#include <iostream>
#include <string>
#include <iomanip>



using namespace std;

// Clase base Cuenta
class Cuenta {
protected:
    string numeroCuenta;
    string propietario;
    double saldo;

public:
    // Constructor
    Cuenta(string numCuenta, string prop, double sal) {
        numeroCuenta = numCuenta;
        propietario = prop;

        if (sal >= 0) {
            saldo = sal;
        } else {
            saldo = 0.0;
            cout << "Saldo inicial invalido. Se establecio $0.00 por defecto" << endl;
        }
    }

    // Getters
    string getNumeroCuenta() { return numeroCuenta; }
    string getPropietario() { return propietario; }
    double getSaldo() { return saldo; }

    // Setters
    void setNumeroCuenta(string numCuenta) { numeroCuenta = numCuenta; }
    void setPropietario(string prop) { propietario = prop; }

    void setSaldo(double sal) {
        if (sal >= 0) {
            saldo = sal;
        } else {
            cout << "Error: El saldo no puede ser negativo" << endl;
        }
    }

    // Métodos virtuales
    virtual void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito exitoso: $" << fixed << setprecision(2) << monto << endl;
            cout << "Nuevo saldo: $" << fixed << setprecision(2) << saldo << endl;
        } else {
            cout << "Error: El monto a depositar debe ser positivo" << endl;
        }
    }

    virtual void retirar(double monto) {
        if (monto > 0) {
            if (monto <= saldo) {
                saldo -= monto;
                cout << "Retiro exitoso: $" << fixed << setprecision(2) << monto << endl;
                cout << "Nuevo saldo: $" << fixed << setprecision(2) << saldo << endl;
            } else {
                cout << "Error: Fondos insuficientes. Saldo actual: $"
                     << fixed << setprecision(2) << saldo << endl;
            }
        } else {
            cout << "Error: El monto a retirar debe ser positivo" << endl;
        }
    }

    virtual void mostrarInfo() {
        cout << "=== INFORMACION DE LA CUENTA ===" << endl;
        cout << "Numero de Cuenta: " << numeroCuenta << endl;
        cout << "Propietario: " << propietario << endl;
        cout << "Saldo: $" << fixed << setprecision(2) << saldo << endl;
    }
};

// Clase CuentaAhorro hereda de Cuenta
class CuentaAhorro : public Cuenta {
private:
    double tasaInteres;

public:
    // Constructor
    CuentaAhorro(string numCuenta, string prop, double sal, double tasa)
        : Cuenta(numCuenta, prop, sal) {

        if (tasa >= 0) {
            tasaInteres = tasa;
        } else {
            tasaInteres = 0.0;
            cout << "Tasa de interes invalida. Se establecio 0% por defecto" << endl;
        }
    }

    // Getters y Setters
    double getTasaInteres() { return tasaInteres; }

    void setTasaInteres(double tasa) {
        if (tasa >= 0) {
            tasaInteres = tasa;
        } else {
            cout << "Error: La tasa de interes no puede ser negativa" << endl;
        }
    }

    // Método para generar intereses
    void generarInteres() {
        double interes = saldo * (tasaInteres / 100);
        saldo += interes;
        cout << "Interes generado: $" << fixed << setprecision(2) << interes << endl;
        cout << "Nuevo saldo con intereses: $" << fixed << setprecision(2) << saldo << endl;
    }

    // Override de depositar (puede incluir bonificaciones, etc.)
    void depositar(double monto) override {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito en cuenta de ahorro exitoso: $" << fixed << setprecision(2) << monto << endl;
            cout << "Nuevo saldo: $" << fixed << setprecision(2) << saldo << endl;

            // Bonificación por depósitos grandes en cuenta de ahorro
            if (monto >= 1000) {
                double bonificacion = monto * 0.001; // 0.1% de bonificación
                saldo += bonificacion;
                cout << "Bonificacion por deposito grande: $" << fixed << setprecision(2) << bonificacion << endl;
                cout << "Saldo final con bonificacion: $" << fixed << setprecision(2) << saldo << endl;
            }
        } else {
            cout << "Error: El monto a depositar debe ser positivo" << endl;
        }
    }

    // Override de retirar (puede tener restricciones adicionales)
    void retirar(double monto) override {
        if (monto > 0) {
            if (monto <= saldo) {
                // En cuentas de ahorro, mantener un saldo mínimo recomendado
                double saldoMinimoRecomendado = 50.0;
                if ((saldo - monto) < saldoMinimoRecomendado) {
                    cout << "Advertencia: El retiro dejara un saldo menor al minimo recomendado ($"
                         << fixed << setprecision(2) << saldoMinimoRecomendado << ")" << endl;
                }

                saldo -= monto;
                cout << "Retiro de cuenta de ahorro exitoso: $" << fixed << setprecision(2) << monto << endl;
                cout << "Nuevo saldo: $" << fixed << setprecision(2) << saldo << endl;
            } else {
                cout << "Error: Fondos insuficientes en cuenta de ahorro. Saldo actual: $"
                     << fixed << setprecision(2) << saldo << endl;
            }
        } else {
            cout << "Error: El monto a retirar debe ser positivo" << endl;
        }
    }

    // Override de mostrarInfo
    void mostrarInfo() override {
        Cuenta::mostrarInfo();
        cout << "Tipo: Cuenta de Ahorro" << endl;
        cout << "Tasa de Interes: " << fixed << setprecision(2) << tasaInteres << "%" << endl;
        cout << "=================================" << endl;
    }
};

// Clase CuentaCorriente hereda de Cuenta
class CuentaCorriente : public Cuenta {
private:
    double limiteDescubierto;

public:
    // Constructor
    CuentaCorriente(string numCuenta, string prop, double sal, double limite)
        : Cuenta(numCuenta, prop, sal) {

        if (limite >= 0) {
            limiteDescubierto = limite;
        } else {
            limiteDescubierto = 0.0;
            cout << "Limite de descubierto invalido. Se establecio $0.00 por defecto" << endl;
        }
    }

    // Getters y Setters
    double getLimiteDescubierto() { return limiteDescubierto; }

    void setLimiteDescubierto(double limite) {
        if (limite >= 0) {
            limiteDescubierto = limite;
        } else {
            cout << "Error: El limite de descubierto no puede ser negativo" << endl;
        }
    }

    // Método para solicitar descubierto
    void solicitarDescubierto(double monto) {
        if (monto > 0 && monto <= limiteDescubierto) {
            saldo -= monto; // Saldo se vuelve negativo
            cout << "Descubierto autorizado: $" << fixed << setprecision(2) << monto << endl;
            cout << "Nuevo saldo: $" << fixed << setprecision(2) << saldo << endl;
        } else if (monto > limiteDescubierto) {
            cout << "Error: El monto solicitado excede el limite de descubierto de $"
                 << fixed << setprecision(2) << limiteDescubierto << endl;
        } else {
            cout << "Error: El monto debe ser positivo" << endl;
        }
    }

    // Override de depositar
    void depositar(double monto) override {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito en cuenta corriente exitoso: $" << fixed << setprecision(2) << monto << endl;

            // Si el saldo era negativo, informar si se cubrió el descubierto
            if (saldo - monto < 0 && saldo >= 0) {
                cout << "¡Descubierto cubierto completamente!" << endl;
            }

            cout << "Nuevo saldo: $" << fixed << setprecision(2) << saldo << endl;
        } else {
            cout << "Error: El monto a depositar debe ser positivo" << endl;
        }
    }

    // Override de retirar (permite descubierto)
    void retirar(double monto) override {
        if (monto > 0) {
            double saldoDisponible = saldo + limiteDescubierto;

            if (monto <= saldoDisponible) {
                saldo -= monto;
                cout << "Retiro de cuenta corriente exitoso: $" << fixed << setprecision(2) << monto << endl;

                if (saldo < 0) {
                    cout << "Advertencia: Esta utilizando descubierto. Saldo negativo: $"
                         << fixed << setprecision(2) << saldo << endl;
                } else {
                    cout << "Nuevo saldo: $" << fixed << setprecision(2) << saldo << endl;
                }
            } else {
                cout << "Error: Fondos insuficientes. Saldo disponible (incluyendo descubierto): $"
                     << fixed << setprecision(2) << saldoDisponible << endl;
            }
        } else {
            cout << "Error: El monto a retirar debe ser positivo" << endl;
        }
    }

    // Override de mostrarInfo
    void mostrarInfo() override {
        Cuenta::mostrarInfo();
        cout << "Tipo: Cuenta Corriente" << endl;
        cout << "Limite de Descubierto: $" << fixed << setprecision(2) << limiteDescubierto << endl;
        cout << "Saldo Disponible: $" << fixed << setprecision(2) << (saldo + limiteDescubierto) << endl;
        cout << "=================================" << endl;
    }
};

// Función principal para probar el sistema bancario
int main() {
    cout << "SISTEMA BANCARIO - HERENCIA" << endl << endl;

    // Crear cuentas de diferentes tipos
    CuentaAhorro cuentaAhorro("AH-001", "Juan Perez", 1000.0, 2.5);
    CuentaCorriente cuentaCorriente("CC-001", "Maria Garcia", 500.0, 1000.0);

    // Mostrar información inicial
    cout << "--- INFORMACION INICIAL DE LAS CUENTAS ---" << endl;
    cuentaAhorro.mostrarInfo();
    cuentaCorriente.mostrarInfo();

    // Probar operaciones en Cuenta de Ahorro
    cout << "\n--- OPERACIONES EN CUENTA DE AHORRO ---" << endl;
    cuentaAhorro.depositar(500.0);
    cuentaAhorro.retirar(200.0);
    cuentaAhorro.generarInteres();
    cuentaAhorro.mostrarInfo();

    // Probar operaciones en Cuenta Corriente
    cout << "\n--- OPERACIONES EN CUENTA CORRIENTE ---" << endl;
    cuentaCorriente.depositar(300.0);
    cuentaCorriente.retirar(1200.0); // Usará descubierto
    cuentaCorriente.retirar(500.0);  // Excederá el límite
    cuentaCorriente.mostrarInfo();

    // Probar método específico de Cuenta Corriente
    cout << "\n--- SOLICITUD DE DESCUBIERTO ---" << endl;
    cuentaCorriente.solicitarDescubierto(800.0);
    cuentaCorriente.mostrarInfo();

    // Probar validaciones
    cout << "\n--- PROBANDO VALIDACIONES ---" << endl;
    cuentaAhorro.depositar(-100.0);
    cuentaAhorro.retirar(-50.0);
    cuentaAhorro.retirar(5000.0);

    cuentaCorriente.setLimiteDescubierto(-500.0);

    // Probar polimorfismo con punteros a la clase base
    cout << "\n--- POLIMORFISMO CON CLASE BASE ---" << endl;
    Cuenta* cuentas[] = {&cuentaAhorro, &cuentaCorriente};

    for (int i = 0; i < 2; i++) {
        cuentas[i]->depositar(100.0);
        cuentas[i]->retirar(50.0);
        cout << endl;
    }

    return 0;
}
