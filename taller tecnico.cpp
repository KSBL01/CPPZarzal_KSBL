
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype> // Para funciones de manejo de caracteres (isalpha, isspace, etc.)
#include <fstream> // Para manejo de archivos (ifstream, ofstream
#include <iomanip>
    using namespace std;

    // ===== EJERCICIO 1: Estadísticas básicas =====
    void leer_arreglo(vector<int>& arr) {
        cout << "Ingrese " << arr.size() << " elementos del arreglo:" << endl;
        for (size_t i = 0; i < arr.size(); i++) {
            cin >> arr[i];  // Leer cada elemento
        }
    }

    void min_max_prom(const vector<int>& arr, int& minv, int& maxv, double& prom) {
        if (arr.empty()) {
            minv = maxv = 0;
            prom = 0.0;
            return;
        }

        minv = arr[0];  // Inicializar mínimo con primer elemento
        maxv = arr[0];  // Inicializar máximo con primer elemento
        double suma = 0.0;

        for (int num : arr) {  // Recorrer con range-based for
            if (num < minv) minv = num;
            if (num > maxv) maxv = num;
            suma += num;  // Acumular suma para promedio
        }

        prom = suma / arr.size();  // Calcular promedio
    }

    void ejercicio1() {
        cout << "\n=== EJERCICIO 1: Estadisticas del arreglo ===" << endl;
        int n;
        cout << "Ingrese el tamaño del arreglo: ";
        cin >> n;

        if (n > 100000) {
            cout << "Error: tamaño muy grande" << endl;
            return;
        }

        vector<int> arr(n);  // Usar vector en lugar de array C
        leer_arreglo(arr);

        int min_val, max_val;
        double promedio;
        min_max_prom(arr, min_val, max_val, promedio);

        cout << "Resultados:" << endl;
        cout << "Minimo: " << min_val << endl;
        cout << "Maximo: " << max_val << endl;
        cout << fixed << setprecision(2) << "Promedio: " << promedio << endl;
    }

    // ===== EJERCICIO 2: Rotación circular =====
    void reverse(vector<int>& arr, int i, int j) {
        while (i < j) {
            swap(arr[i], arr[j]);  // Usar swap de C++
            i++;
            j--;
        }
    }

    void rotar_derecha(vector<int>& arr, int k) {
        if (arr.empty()) return;
        k = k % arr.size();  // Ajustar k si es mayor que tamaño

        reverse(arr, 0, arr.size() - 1);  // Revertir todo el array
        reverse(arr, 0, k - 1);           // Revertir primera parte
        reverse(arr, k, arr.size() - 1);  // Revertir segunda parte
    }

    void ejercicio2() {
        cout << "\n=== EJERCICIO 2: Rotacion circular ===" << endl;
        int n, k;
        cout << "Ingrese tamaño del arreglo: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Ingrese " << n << " elementos: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Ingrese desplazamiento k: ";
        cin >> k;

        cout << "Arreglo original: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;

        rotar_derecha(arr, k);

        cout << "Arreglo rotado: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    // ===== EJERCICIO 3: Normalizar cadenas =====
    string normalizar_espacios(const string& input) {
        string resultado;
        bool en_espacio = true;  // Bandera para controlar espacios duplicados

        for (char c : input) {
            if (isspace(c)) {
                if (!en_espacio) {
                    resultado += ' ';  // Agregar solo un espacio
                    en_espacio = true;
                }
            } else {
                resultado += c;       // Agregar caracter no espacio
                en_espacio = false;
            }
        }

        // Eliminar espacio final si existe
        if (!resultado.empty() && isspace(resultado.back())) {
            resultado.pop_back();
        }

        return resultado;
    }

    void ejercicio3() {
        cout << "\n=== EJERCICIO 3: Normalizar cadena ===" << endl;
        string entrada;

        cout << "Ingrese una cadena: ";
        cin.ignore();  // Limpiar buffer del cin anterior
        getline(cin, entrada);

        string salida = normalizar_espacios(entrada);

        cout << "Cadena original: \"" << entrada << "\"" << endl;
        cout << "Cadena normalizada: \"" << salida << "\"" << endl;
        cout << "Longitud: " << salida.length() << endl;
    }

    // ===== EJERCICIO 4: Matriz sumas =====
    void mat_sumas(const vector<vector<int>>& mat, vector<int>& sumF, vector<int>& sumC) {
        int m = mat.size();
        if (m == 0) return;
        int n = mat[0].size();

        sumF.assign(m, 0);  // Inicializar sumas de filas en 0
        sumC.assign(n, 0);  // Inicializar sumas de columnas en 0

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sumF[i] += mat[i][j];  // Sumar a fila i
                sumC[j] += mat[i][j];  // Sumar a columna j
            }
        }
    }

    void ejercicio4() {
        cout << "\n=== EJERCICIO 4: Sumas de matriz ===" << endl;
        int m, n;
        cout << "Ingrese filas y columnas (m n): ";
        cin >> m >> n;

        vector<vector<int>> mat(m, vector<int>(n));  // Matriz m x n

        cout << "Ingrese " << m << " x " << n << " elementos:" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        vector<int> sumFila, sumCol;
        mat_sumas(mat, sumFila, sumCol);

        cout << "Sumas por fila: [";
        for (size_t i = 0; i < sumFila.size(); i++) {
            cout << sumFila[i];
            if (i < sumFila.size() - 1) cout << ", ";
        }
        cout << "]" << endl;

        cout << "Sumas por columna: [";
        for (size_t j = 0; j < sumCol.size(); j++) {
            cout << sumCol[j];
            if (j < sumCol.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    // ===== EJERCICIO 5: Estructuras estudiantes =====
    struct Estudiante {
        string nombre;
        int edad;
        double promedio;

        Estudiante() : edad(0), promedio(0.0) {}  // Constructor por defecto
    };

    bool cmp_prom_desc(const Estudiante& a, const Estudiante& b) {
        return a.promedio > b.promedio;  // Orden descendente por promedio
    }

    int buscar_nombre(const vector<Estudiante>& estudiantes, const string& clave) {
        for (size_t i = 0; i < estudiantes.size(); i++) {
            if (estudiantes[i].nombre == clave) {
                return i;  // Retornar índice si se encuentra
            }
        }
        return -1;  // No encontrado
    }

    void ejercicio5() {
        cout << "\n=== EJERCICIO 5: Registro estudiantes ===" << endl;
        int n;
        cout << "Cuantos estudiantes? ";
        cin >> n;

        vector<Estudiante> estudiantes(n);

        // Leer datos de estudiantes
        for (int i = 0; i < n; i++) {
            cout << "\nEstudiante " << i + 1 << ":" << endl;
            cout << "Nombre: ";
            cin >> estudiantes[i].nombre;
            cout << "Edad: ";
            cin >> estudiantes[i].edad;
            cout << "Promedio: ";
            cin >> estudiantes[i].promedio;
        }

        // Ordenar por promedio descendente
        sort(estudiantes.begin(), estudiantes.end(), cmp_prom_desc);

        // Mostrar top 3
        cout << "\n=== TOP 3 POR PROMEDIO ===" << endl;
        for (int i = 0; i < 3 && i < n; i++) {
            cout << i + 1 << ". " << estudiantes[i].nombre
                 << " (Edad: " << estudiantes[i].edad
                 << ", Promedio: " << fixed << setprecision(2) << estudiantes[i].promedio << ")" << endl;
        }

        // Buscar por nombre
        string nombre_buscar;
        cout << "\nBuscar estudiante por nombre: ";
        cin >> nombre_buscar;

        int pos = buscar_nombre(estudiantes, nombre_buscar);
        if (pos != -1) {
            cout << "Encontrado en posicion " << pos << ": " << estudiantes[pos].nombre
                 << ", edad " << estudiantes[pos].edad
                 << ", promedio " << estudiantes[pos].promedio << endl;
        } else {
            cout << "Estudiante no encontrado" << endl;
        }
    }

    // ===== EJERCICIO 6: Lista enlazada =====
    struct Nodo {
        int valor;
        Nodo* siguiente;

        Nodo(int v) : valor(v), siguiente(nullptr) {}  // Constructor
    };

    class ListaEnlazada {
    private:
        Nodo* cabeza;
        Nodo* cola;
        int tamaño;

    public:
        ListaEnlazada() : cabeza(nullptr), cola(nullptr), tamaño(0) {}  // Constructor

        ~ListaEnlazada() {  // Destructor para liberar memoria
            clear();
        }

        void push_front(int valor) {
            Nodo* nuevo = new Nodo(valor);  // Crear nuevo nodo
            nuevo->siguiente = cabeza;      // Apuntar al actual cabeza
            cabeza = nuevo;                 // Actualizar cabeza

            if (!cola) cola = nuevo;        // Si lista estaba vacía
            tamaño++;
        }

        void push_back(int valor) {
            Nodo* nuevo = new Nodo(valor);  // Crear nuevo nodo

            if (cola) {
                cola->siguiente = nuevo;    // Enlazar al final
            } else {
                cabeza = nuevo;             // Si lista estaba vacía
            }
            cola = nuevo;                   // Actualizar cola
            tamaño++;
        }

        int pop_front() {
            if (!cabeza) return -1;         // Lista vacía

            Nodo* temp = cabeza;
            int valor = temp->valor;
            cabeza = cabeza->siguiente;     // Mover cabeza al siguiente

            if (!cabeza) cola = nullptr;    // Si lista queda vacía
            delete temp;                    // Liberar memoria
            tamaño--;
            return valor;
        }

        int size() const {
            return tamaño;
        }

        void clear() {
            while (cabeza) {
                pop_front();  // Liberar todos los nodos
            }
        }

        void imprimir() const {
            Nodo* actual = cabeza;
            while (actual) {
                cout << actual->valor << " ";
                actual = actual->siguiente;
            }
        }
    };

    void ejercicio6() {
        cout << "\n=== EJERCICIO 6: Lista enlazada ===" << endl;
        ListaEnlazada lista;

        cout << "Comandos: pf X (push front), pb X (push back), pop (pop front), fin (terminar)" << endl;

        string comando;
        int valor;

        while (true) {
            cout << "> ";
            cin >> comando;

            if (comando == "pf") {
                cin >> valor;
                lista.push_front(valor);
                cout << "Agregado " << valor << " al frente" << endl;
            } else if (comando == "pb") {
                cin >> valor;
                lista.push_back(valor);
                cout << "Agregado " << valor << " al final" << endl;
            } else if (comando == "pop") {
                valor = lista.pop_front();
                if (valor != -1) {
                    cout << "Eliminado: " << valor << endl;
                } else {
                    cout << "Lista vacia" << endl;
                }
            } else if (comando == "fin") {
                break;
            } else {
                cout << "Comando desconocido" << endl;
            }
        }

        // Mostrar contenido final
        cout << "\nContenido final de la lista: ";
        lista.imprimir();
        cout << "\nTamaño: " << lista.size() << endl;
    }

    // ===== EJERCICIO 7: Punteros a función =====
    int doble(int x) {
        return x * 2;  // Retornar el doble
    }

    int cuadrado(int x) {
        return x * x;  // Retornar el cuadrado
    }

    void aplicar(vector<int>& arr, int (*operacion)(int)) {
        for (size_t i = 0; i < arr.size(); i++) {
            arr[i] = operacion(arr[i]);  // Aplicar función a cada elemento
        }
    }

    void ejercicio7() {
        cout << "\n=== EJERCICIO 7: Punteros a funcion ===" << endl;
        int n;
        cout << "Tamaño del arreglo: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Ingrese " << n << " elementos: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Arreglo original: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;

        int opcion;
        cout << "Operacion: 1=Doble, 2=Cuadrado: ";
        cin >> opcion;

        if (opcion == 1) {
            aplicar(arr, doble);
            cout << "Despues de doble: ";
        } else if (opcion == 2) {
            aplicar(arr, cuadrado);
            cout << "Despues de cuadrado: ";
        } else {
            cout << "Opcion invalida" << endl;
            return;
        }

        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    // ===== EJERCICIO 8: Archivo ventas =====
    struct Venta {
        string producto;
        int unidades;
        double precio;

        Venta() : unidades(0), precio(0.0) {}  // Constructor por defecto
    };

    void ejercicio8() {
        cout << "\n=== EJERCICIO 8: Estadisticas de ventas ===" << endl;

        // Crear archivo de ejemplo
        ofstream archivoSalida("ventas.csv");
        if (archivoSalida.is_open()) {
            archivoSalida << "Laptop,5,1200.50\n";
            archivoSalida << "Mouse,15,25.75\n";
            archivoSalida << "Teclado,8,45.30\n";
            archivoSalida << "Monitor,3,350.00\n";
            archivoSalida.close();
            cout << "Archivo 'ventas.csv' creado con datos de ejemplo" << endl;
        }

        // Leer archivo
        ifstream archivoEntrada("ventas.csv");
        if (!archivoEntrada.is_open()) {
            cout << "Error abriendo archivo" << endl;
            return;
        }

        vector<Venta> ventas;
        string linea;

        while (getline(archivoEntrada, linea)) {
            Venta venta;
            size_t pos1 = linea.find(',');
            size_t pos2 = linea.find(',', pos1 + 1);

            if (pos1 != string::npos && pos2 != string::npos) {
                venta.producto = linea.substr(0, pos1);  // Extraer producto
                venta.unidades = stoi(linea.substr(pos1 + 1, pos2 - pos1 - 1));  // Extraer unidades
                venta.precio = stod(linea.substr(pos2 + 1));  // Extraer precio
                ventas.push_back(venta);
            }
        }
        archivoEntrada.close();

        // Calcular estadísticas
        double totalVendido = 0.0;
        int maxUnidades = -1;
        string productoMasVendido;
        double sumaTickets = 0.0;

        for (const Venta& venta : ventas) {
            double ventaTotal = venta.unidades * venta.precio;
            totalVendido += ventaTotal;  // Acumular total vendido

            if (venta.unidades > maxUnidades) {
                maxUnidades = venta.unidades;
                productoMasVendido = venta.producto;  // Actualizar producto más vendido
            }

            sumaTickets += ventaTotal;  // Acumular para promedio
        }

        double ticketPromedio = !ventas.empty() ? sumaTickets / ventas.size() : 0.0;

        cout << "\n=== ESTADISTICAS DE VENTAS ===" << endl;
        cout << fixed << setprecision(2);
        cout << "Total vendido: $" << totalVendido << endl;
        cout << "Producto mas vendido: " << productoMasVendido << " (" << maxUnidades << " unidades)" << endl;
        cout << "Ticket promedio: $" << ticketPromedio << endl;
    }

    // ===== MENU PRINCIPAL =====
    int main() {
        cout << "====== TALLER INTEGRAL EN C++ ======" << endl;
        cout << "Ejercicios de bucles, arreglos, funciones, estructuras y punteros" << endl;

        int opcion;
        do {
            cout << "\n=== MENU PRINCIPAL ===" << endl;
            cout << "1. Estadisticas basicas de arreglo" << endl;
            cout << "2. Rotacion circular" << endl;
            cout << "3. Normalizar cadenas" << endl;
            cout << "4. Matriz - sumas por filas y columnas" << endl;
            cout << "5. Registro de estudiantes" << endl;
            cout << "6. Lista enlazada dinamica" << endl;
            cout << "7. Punteros a funcion" << endl;
            cout << "8. Archivo + estructuras - ventas" << endl;
            cout << "0. Salir" << endl;
            cout << "Seleccione ejercicio: ";

            cin >> opcion;

            switch (opcion) {
                case 1: ejercicio1(); break;
                case 2: ejercicio2(); break;
                case 3: ejercicio3(); break;
                case 4: ejercicio4(); break;
                case 5: ejercicio5(); break;
                case 6: ejercicio6(); break;
                case 7: ejercicio7(); break;
                case 8: ejercicio8(); break;
                case 0: cout << "Saliendo..." << endl; break;
                default: cout << "Opcion invalida" << endl;
            }

        } while (opcion != 0);

        return 0;
    }
