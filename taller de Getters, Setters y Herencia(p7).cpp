#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

// Forward declarations (declaraciones anticipadas)
class Curso;
class Profesor;

// ==================== CLASE PERSONA (BASE) ====================
class Persona {
protected:
    string nombre;
    int edad;
    string cedula;

public:
    // Constructor con lista de inicialización
    Persona(string nom, int ed, string ced) : nombre(nom), edad(ed), cedula(ced) {
        // Validación de edad
        if (edad < 0) {
            edad = 0;
            cout << "Advertencia: Edad no puede ser negativa. Se establecio 0." << endl;
        }
    }

    // Getters (métodos de acceso)
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    string getCedula() const { return cedula; }

    // Setters (métodos de modificación)
    void setNombre(string nom) { nombre = nom; }
    void setEdad(int ed) {
        if (ed >= 0) {
            edad = ed;
        } else {
            cout << "Error: La edad no puede ser negativa" << endl;
        }
    }
    void setCedula(string ced) { cedula = ced; }

    // Método virtual para mostrar información (polimorfismo)
    virtual void mostrarInfo() const {
        cout << "=== INFORMACION PERSONAL ===" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Cedula: " << cedula << endl;
    }

    // Destructor virtual para liberación correcta de memoria
    virtual ~Persona() {}
};

// ==================== CLASE CURSO ====================
class Curso {
private:
    string codigo;
    string nombre;
    int creditos;
    Profesor* profesor;  // Puntero al profesor que imparte el curso
    map<string, double> calificaciones; // Mapa: cedula_estudiante -> calificación

public:
    // Constructor
    Curso(string cod, string nom, int cred, Profesor* prof = nullptr)
        : codigo(cod), nombre(nom), creditos(cred), profesor(prof) {
        // Validación de créditos
        if (creditos < 0) creditos = 0;
    }

    // Getters
    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    int getCreditos() const { return creditos; }
    Profesor* getProfesor() const { return profesor; }

    // Setters
    void setCodigo(string cod) { codigo = cod; }
    void setNombre(string nom) { nombre = nom; }
    void setCreditos(int cred) {
        if (cred >= 0) creditos = cred;
    }
    void setProfesor(Profesor* prof) { profesor = prof; }

    // Método para agregar calificación de un estudiante
    void agregarCalificacion(string cedulaEstudiante, double calificacion) {
        // Validar rango de calificación
        if (calificacion >= 0 && calificacion <= 100) {
            calificaciones[cedulaEstudiante] = calificacion;  // Insertar en mapa
        } else {
            cout << "Error: La calificacion debe estar entre 0 y 100" << endl;
        }
    }

    // Método para obtener calificación de un estudiante
    double obtenerCalificacion(string cedulaEstudiante) const {
        auto it = calificaciones.find(cedulaEstudiante);  // Buscar en mapa
        if (it != calificaciones.end()) {
            return it->second;  // Retornar calificación si existe
        }
        return -1; // Retornar -1 si no hay calificación
    }

    // Método para mostrar información del curso
    void mostrarInfo() const {
        cout << "--- INFORMACION DEL CURSO ---" << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Creditos: " << creditos << endl;
        if (profesor) {
            cout << "Profesor: " << profesor->getNombre() << endl;
        } else {
            cout << "Profesor: No asignado" << endl;
        }
        cout << "Estudiantes matriculados: " << calificaciones.size() << endl;
    }

    // Método para mostrar todas las calificaciones del curso
    void mostrarCalificaciones() const {
        cout << "Calificaciones del curso " << nombre << ":" << endl;
        // Recorrer mapa de calificaciones
        for (const auto& calif : calificaciones) {
            cout << "  Estudiante " << calif.first << ": " << calif.second << endl;
        }
    }
};

// ==================== CLASE ESTUDIANTE ====================
class Estudiante : public Persona {  // Herencia de Persona
private:
    string carrera;
    double promedio;
    int semestre;
    vector<Curso*> cursosMatriculados;  // Vector de punteros a cursos
    map<string, double> calificacionesPorCurso; // Mapa: codigo_curso -> calificación

public:
    // Constructor que llama al constructor de la clase base
    Estudiante(string nom, int ed, string ced, string carr, int sem)
        : Persona(nom, ed, ced), carrera(carr), semestre(sem) {
        promedio = 0.0;
        // Validación de semestre
        if (semestre < 1) semestre = 1;
    }

    // Getters
    string getCarrera() const { return carrera; }
    double getPromedio() const { return promedio; }
    int getSemestre() const { return semestre; }
    const vector<Curso*>& getCursosMatriculados() const { return cursosMatriculados; }

    // Setters
    void setCarrera(string carr) { carrera = carr; }
    void setSemestre(int sem) {
        if (sem >= 1) semestre = sem;
    }

    // Método para matricular un curso
    void matricularCurso(Curso* curso) {
        // Verificar si ya está matriculado en el curso
        for (auto* cursoMat : cursosMatriculados) {
            if (cursoMat->getCodigo() == curso->getCodigo()) {
                cout << "Error: Ya esta matriculado en este curso" << endl;
                return;
            }
        }

        // Agregar curso al vector de cursos matriculados
        cursosMatriculados.push_back(curso);
        cout << "Curso " << curso->getNombre() << " matriculado exitosamente" << endl;
    }

    // Método para retirar un curso
    void retirarCurso(string codigoCurso) {
        // Buscar curso en el vector
        for (auto it = cursosMatriculados.begin(); it != cursosMatriculados.end(); ++it) {
            if ((*it)->getCodigo() == codigoCurso) {
                cursosMatriculados.erase(it);  // Eliminar del vector
                calificacionesPorCurso.erase(codigoCurso);  // Eliminar calificación
                cout << "Curso retirado exitosamente" << endl;
                return;
            }
        }
        cout << "Error: No esta matriculado en este curso" << endl;
    }

    // Método para agregar calificación de un curso
    void agregarCalificacion(string codigoCurso, double calificacion) {
        // Verificar que el estudiante esté matriculado en el curso
        bool estaMatriculado = false;
        for (auto* curso : cursosMatriculados) {
            if (curso->getCodigo() == codigoCurso) {
                estaMatriculado = true;
                break;
            }
        }

        if (estaMatriculado) {
            calificacionesPorCurso[codigoCurso] = calificacion;  // Agregar al mapa
        } else {
            cout << "Error: No esta matriculado en este curso" << endl;
        }
    }

    // Método para calcular el promedio actual
    double calcularPromedioActual() {
        if (calificacionesPorCurso.empty()) {
            return 0.0;  // Retornar 0 si no hay calificaciones
        }

        double suma = 0.0;
        // Sumar todas las calificaciones
        for (const auto& calif : calificacionesPorCurso) {
            suma += calif.second;
        }

        // Calcular promedio
        promedio = suma / calificacionesPorCurso.size();
        return promedio;
    }

    // Método para ver todas las calificaciones
    void verCalificaciones() const {
        cout << "--- CALIFICACIONES DE " << nombre << " ---" << endl;
        // Recorrer mapa de calificaciones
        for (const auto& calif : calificacionesPorCurso) {
            cout << "Curso " << calif.first << ": " << calif.second << endl;
        }
        cout << "Promedio actual: " << fixed << setprecision(2) << promedio << endl;
    }

    // Método para mostrar cursos matriculados
    void mostrarCursosMatriculados() const {
        cout << "--- CURSOS MATRICULADOS ---" << endl;
        // Recorrer vector de cursos
        for (const auto* curso : cursosMatriculados) {
            cout << "- " << curso->getNombre() << " (" << curso->getCodigo() << ")" << endl;
        }
    }

    // Override del método mostrarInfo (polimorfismo)
    void mostrarInfo() const override {
        Persona::mostrarInfo();  // Llamar método de clase base
        cout << "Tipo: Estudiante" << endl;
        cout << "Carrera: " << carrera << endl;
        cout << "Semestre: " << semestre << endl;
        cout << "Promedio: " << fixed << setprecision(2) << promedio << endl;
        cout << "Cursos matriculados: " << cursosMatriculados.size() << endl;
        cout << "=================================" << endl;
    }
};

// ==================== CLASE PROFESOR ====================
class Profesor : public Persona {  // Herencia de Persona
private:
    string especialidad;
    int añosExperiencia;
    int numeroEstudiantes;
    vector<Curso*> cursosAsignados;  // Vector de punteros a cursos

public:
    // Constructor
    Profesor(string nom, int ed, string ced, string esp, int añosExp)
        : Persona(nom, ed, ced), especialidad(esp), añosExperiencia(añosExp) {
        numeroEstudiantes = 0;
        // Validación de años de experiencia
        if (añosExperiencia < 0) añosExperiencia = 0;
    }

    // Getters
    string getEspecialidad() const { return especialidad; }
    int getAñosExperiencia() const { return añosExperiencia; }
    int getNumeroEstudiantes() const { return numeroEstudiantes; }
    const vector<Curso*>& getCursosAsignados() const { return cursosAsignados; }

    // Setters
    void setEspecialidad(string esp) { especialidad = esp; }
    void setAñosExperiencia(int años) {
        if (años >= 0) añosExperiencia = años;
    }
    void setNumeroEstudiantes(int num) {
        if (num >= 0) numeroEstudiantes = num;
    }

    // Método para asignar un curso al profesor
    void asignarCurso(Curso* curso) {
        cursosAsignados.push_back(curso);  // Agregar al vector
        curso->setProfesor(this);  // Establecer profesor en el curso
        cout << "Curso " << curso->getNombre() << " asignado al profesor " << nombre << endl;
    }

    // Método para verificar disponibilidad según hora del día
    bool estaDisponible(int horaDelDia) const {
        // Horario laboral: 8:00 - 18:00
        return (horaDelDia >= 8 && horaDelDia <= 18);
    }

    // Método para calificar a un estudiante en un curso
    void calificarEstudiante(Curso* curso, string cedulaEstudiante, double calificacion) {
        curso->agregarCalificacion(cedulaEstudiante, calificacion);
        cout << "Calificacion asignada al estudiante " << cedulaEstudiante << endl;
    }

    // Método para mostrar cursos asignados
    void mostrarCursosAsignados() const {
        cout << "--- CURSOS ASIGNADOS A " << nombre << " ---" << endl;
        // Recorrer vector de cursos
        for (const auto* curso : cursosAsignados) {
            cout << "- " << curso->getNombre() << " (" << curso->getCodigo() << ")" << endl;
        }
    }

    // Override del método mostrarInfo
    void mostrarInfo() const override {
        Persona::mostrarInfo();  // Llamar método de clase base
        cout << "Tipo: Profesor" << endl;
        cout << "Especialidad: " << especialidad << endl;
        cout << "Años de Experiencia: " << añosExperiencia << endl;
        cout << "Numero de Estudiantes: " << numeroEstudiantes << endl;
        cout << "Cursos asignados: " << cursosAsignados.size() << endl;
        cout << "Disponibilidad: " << (estaDisponible(14) ? "Disponible" : "No disponible") << endl;
        cout << "=================================" << endl;
    }
};

// ==================== CLASE PERSONAL ====================
class Personal : public Persona {  // Herencia de Persona
private:
    string puesto;
    string departamento;
    double salario;

public:
    // Constructor
    Personal(string nom, int ed, string ced, string pue, string dep, double sal)
        : Persona(nom, ed, ced), puesto(pue), departamento(dep), salario(sal) {
        // Validación de salario
        if (salario < 0) salario = 0;
    }

    // Getters
    string getPuesto() const { return puesto; }
    string getDepartamento() const { return departamento; }
    double getSalario() const { return salario; }

    // Setters
    void setPuesto(string pue) { puesto = pue; }
    void setDepartamento(string dep) { departamento = dep; }
    void setSalario(double sal) {
        if (sal >= 0) salario = sal;
    }

    // Método para calcular salario mensual
    double calcularSalarioMensual() const {
        return salario; // Salario mensual (podría incluir bonificaciones, etc.)
    }

    // Método para calcular salario anual
    double calcularSalarioAnual() const {
        return salario * 12;  // Salario mensual * 12 meses
    }

    // Método para aplicar aumento de salario
    void aplicarAumento(double porcentaje) {
        if (porcentaje > 0) {
            double aumento = salario * (porcentaje / 100);  // Calcular aumento
            salario += aumento;  // Aplicar aumento
            cout << "Aumento aplicado: $" << fixed << setprecision(2) << aumento << endl;
            cout << "Nuevo salario: $" << fixed << setprecision(2) << salario << endl;
        }
    }

    // Override del método mostrarInfo
    void mostrarInfo() const override {
        Persona::mostrarInfo();  // Llamar método de clase base
        cout << "Tipo: Personal Administrativo" << endl;
        cout << "Puesto: " << puesto << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "Salario Base: $" << fixed << setprecision(2) << salario << endl;
        cout << "Salario Mensual: $" << fixed << setprecision(2) << calcularSalarioMensual() << endl;
        cout << "Salario Anual: $" << fixed << setprecision(2) << calcularSalarioAnual() << endl;
        cout << "=================================" << endl;
    }
};

// ==================== FUNCIÓN PRINCIPAL ====================
int main() {
    cout << "SISTEMA UNIVERSITARIO COMPLETO" << endl;
    cout << "===============================" << endl << endl;

    // ========== CREACIÓN DE OBJETOS ==========

    // Crear profesores (instanciación de objetos)
    Profesor prof1("Dr. Carlos Rodriguez", 45, "12345678", "Informatica", 15);
    Profesor prof2("Dra. Ana Martinez", 38, "87654321", "Matematicas", 10);

    // Crear cursos (instanciación de objetos)
    Curso curso1("CS101", "Programacion I", 4, &prof1);
    Curso curso2("MA201", "Calculo I", 5, &prof2);
    Curso curso3("CS102", "Estructuras de Datos", 4, &prof1);

    // Asignar cursos a profesores
    prof1.asignarCurso(&curso1);
    prof1.asignarCurso(&curso3);
    prof2.asignarCurso(&curso2);

    // Crear estudiantes (instanciación de objetos)
    Estudiante est1("Juan Perez", 20, "11111111", "Ingenieria de Sistemas", 3);
    Estudiante est2("Maria Lopez", 19, "22222222", "Matematicas", 2);
    Estudiante est3("Carlos Gomez", 21, "33333333", "Ingenieria de Sistemas", 4);

    // ========== OPERACIONES DEL SISTEMA ==========

    cout << "\n--- MATRICULANDO ESTUDIANTES ---" << endl;
    // Matricular estudiantes en cursos
    est1.matricularCurso(&curso1);
    est1.matricularCurso(&curso2);
    est2.matricularCurso(&curso1);
    est2.matricularCurso(&curso3);
    est3.matricularCurso(&curso2);
    est3.matricularCurso(&curso3);

    cout << "\n--- ASIGNANDO CALIFICACIONES ---" << endl;
    // Profesores califican estudiantes
    prof1.calificarEstudiante(&curso1, "11111111", 85.5);
    prof1.calificarEstudiante(&curso1, "22222222", 92.0);
    prof2.calificarEstudiante(&curso2, "11111111", 78.0);
    prof2.calificarEstudiante(&curso2, "33333333", 88.5);
    prof1.calificarEstudiante(&curso3, "22222222", 95.0);
    prof1.calificarEstudiante(&curso3, "33333333", 82.5);

    // Estudiantes registran sus calificaciones
    est1.agregarCalificacion("CS101", 85.5);
    est1.agregarCalificacion("MA201", 78.0);
    est2.agregarCalificacion("CS101", 92.0);
    est2.agregarCalificacion("CS102", 95.0);
    est3.agregarCalificacion("MA201", 88.5);
    est3.agregarCalificacion("CS102", 82.5);

    // Crear personal administrativo
    Personal admin1("Roberto Silva", 35, "44444444", "Coordinador", "Admisiones", 2500.0);
    Personal admin2("Laura Mendoza", 28, "55555555", "Asistente", "Registro", 1800.0);

    // ========== MOSTRAR INFORMACIÓN ==========

    cout << "\n--- INFORMACION DE ESTUDIANTES ---" << endl;
    est1.mostrarInfo();
    est2.mostrarInfo();
    est3.mostrarInfo();

    cout << "\n--- INFORMACION DE PROFESORES ---" << endl;
    prof1.mostrarInfo();
    prof2.mostrarInfo();

    cout << "\n--- INFORMACION DE PERSONAL ---" << endl;
    admin1.mostrarInfo();
    admin2.mostrarInfo();

    cout << "\n--- INFORMACION DE CURSOS ---" << endl;
    curso1.mostrarInfo();
    curso2.mostrarInfo();
    curso3.mostrarInfo();

    // ========== FUNCIONALIDADES ESPECÍFICAS ==========

    cout << "\n--- FUNCIONALIDADES ESPECIFICAS ---" << endl;

    // Calcular promedios de estudiantes
    cout << "Promedio de " << est1.getNombre() << ": " << est1.calcularPromedioActual() << endl;
    cout << "Promedio de " << est2.getNombre() << ": " << est2.calcularPromedioActual() << endl;
    cout << "Promedio de " << est3.getNombre() << ": " << est3.calcularPromedioActual() << endl;

    // Verificar disponibilidad de profesores
    cout << "\nProfesor " << prof1.getNombre() << " a las 14:00: "
         << (prof1.estaDisponible(14) ? "Disponible" : "No disponible") << endl;
    cout << "Profesor " << prof2.getNombre() << " a las 20:00: "
         << (prof2.estaDisponible(20) ? "Disponible" : "No disponible") << endl;

    // Calcular salarios
    cout << "\nSalario anual de " << admin1.getNombre() << ": $"
         << fixed << setprecision(2) << admin1.calcularSalarioAnual() << endl;

    // Aplicar aumento al personal
    cout << "\nAplicando aumento del 10% a " << admin2.getNombre() << ":" << endl;
    admin2.aplicarAumento(10);

    // Mostrar calificaciones de estudiantes
    cout << "\n--- CALIFICACIONES DE ESTUDIANTES ---" << endl;
    est1.verCalificaciones();
    est2.verCalificaciones();
    est3.verCalificaciones();

    // Mostrar cursos matriculados
    cout << "\n--- CURSOS MATRICULADOS ---" << endl;
    est1.mostrarCursosMatriculados();
    est2.mostrarCursosMatriculados();

    // Mostrar cursos asignados a profesores
    cout << "\n--- CURSOS ASIGNADOS A PROFESORES ---" << endl;
    prof1.mostrarCursosAsignados();
    prof2.mostrarCursosAsignados();

    // ========== DEMOSTRACIÓN DE POLIMORFISMO ==========

    cout << "\n--- POLIMORFISMO CON CLASE BASE ---" << endl;
    vector<Persona*> personas;  // Vector de punteros a clase base
    personas.push_back(&est1);   // Estudiante
    personas.push_back(&prof1);  // Profesor
    personas.push_back(&admin1); // Personal

    // Polimorfismo: cada objeto llama a su propia implementación de mostrarInfo()
    for (Persona* persona : personas) {
        persona->mostrarInfo();  // Llamada polimórfica
        cout << endl;
    }

    return 0;
}
