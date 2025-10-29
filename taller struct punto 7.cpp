#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Contacto {
    string nombre;
    string telefono;
    string email;

    Contacto(string n, string t, string e)
        : nombre(n), telefono(t), email(e) {}
};

struct Agenda {
    vector<Contacto> contactos;

    void agregar(Contacto c) {
        contactos.push_back(c);
    }

    bool eliminar(string nombre) {
        for(auto it = contactos.begin(); it != contactos.end(); it++) {
            if(it->nombre == nombre) {
                contactos.erase(it);
                return true;
            }
        }
        return false;
    }

    Contacto* buscar(string nombre) {
        for(auto& c : contactos) {
            if(c.nombre == nombre) {
                return &c;
            }
        }
        return nullptr;
    }

    void listar() const {
        for(const auto& c : contactos) {
            cout << c.nombre << " " << c.telefono << " " << c.email << endl;
        }
    }
};

int main() {
    Agenda agenda;
    int opcion;

    do {
        cout << "1. Agregar 2. Buscar 3. Eliminar 4. Listar 5. Salir: ";
        cin >> opcion;

        if(opcion == 1) {
            string nom, tel, em;
            cout << "Nombre: ";
            cin >> nom;
            cout << "Telefono: ";
            cin >> tel;
            cout << "Email: ";
            cin >> em;
            agenda.agregar(Contacto(nom, tel, em));
        }
        else if(opcion == 2) {
            string nom;
            cout << "Nombre a buscar: ";
            cin >> nom;
            Contacto* encontrado = agenda.buscar(nom);
            if(encontrado) {
                cout << "Encontrado: " << encontrado->telefono << " " << encontrado->email << endl;
            } else {
                cout << "No encontrado" << endl;
            }
        }
        else if(opcion == 3) {
            string nom;
            cout << "Nombre a eliminar: ";
            cin >> nom;
            if(agenda.eliminar(nom)) {
                cout << "Eliminado" << endl;
            } else {
                cout << "No existe" << endl;
            }
        }
        else if(opcion == 4) {
            agenda.listar();
        }
    } while(opcion != 5);

    return 0;
}
