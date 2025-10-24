#include <iostream>
#include <vector>
#include <memory>  // para shared_ptr
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    string placa;
    bool disponible;

public:
    // Constructor
    Vehiculo(string marca, string modelo, string placa)
        : marca(marca), modelo(modelo), placa(placa), disponible(true) {}

    // Destructor virtual (importante en herencia)
    virtual ~Vehiculo() {}

    // Getters
    string getPlaca() const { return placa; }
    bool estaDisponible() const { return disponible; }

    // Cambia el estado del vehículo
    void alquilar() { disponible = false; }
    void devolver() { disponible = true; }

    // Método virtual que puede ser sobrescrito
    virtual void mostrarInformacion() const {
        cout << marca << " " << modelo
             << " | Placa: " << placa
             << " | Estado: " << (disponible ? "Disponible" : "Alquilado");
    }
};

// Clase derivada Auto

class Auto : public Vehiculo {
private:
    int capacidadPasajeros;

public:
    Auto(string marca, string modelo, string placa, int capacidadPasajeros)
        : Vehiculo(marca, modelo, placa), capacidadPasajeros(capacidadPasajeros) {}

    // Sobrescritura del método
    void mostrarInformacion() const override {
        Vehiculo::mostrarInformacion();
        cout << " | Tipo: Auto"
             << " | Capacidad: " << capacidadPasajeros << " pasajeros" << endl;
    }
};

// Clase derivada Bicicleta

class Bicicleta : public Vehiculo {
private:
    string tipoBici;  // Ej: montaña, carretera, eléctrica

public:
    Bicicleta(string marca, string modelo, string placa, string tipoBici)
        : Vehiculo(marca, modelo, placa), tipoBici(tipoBici) {}

    void mostrarInformacion() const override {
        Vehiculo::mostrarInformacion();
        cout << " | Tipo: Bicicleta"
             << " | Estilo: " << tipoBici << endl;
    }
};

// Clase SistemaAlquiler

class SistemaAlquiler {
private:
    vector<shared_ptr<Vehiculo>> vehiculos;

public:
    void registrarVehiculo(shared_ptr<Vehiculo> v) {
        vehiculos.push_back(v);
        cout << "Vehículo registrado: ";
        v->mostrarInformacion();
    }

    void mostrarDisponibles() const {
        cout << "\nVehículos disponibles:\n";
        bool hayDisponibles = false;

        for (const auto& v : vehiculos) {
            if (v->estaDisponible()) {
                v->mostrarInformacion();
                hayDisponibles = true;
            }
        }

        if (!hayDisponibles)
            cout << "No hay vehículos disponibles.\n";
    }

    void alquilarVehiculo(const string& placa) {
        for (auto& v : vehiculos) {
            if (v->getPlaca() == placa) {
                if (v->estaDisponible()) {
                    v->alquilar();
                    cout << "Vehículo alquilado: ";
                    v->mostrarInformacion();
                    return;
                } else {
                    cout << "Este vehículo ya está alquilado.\n";
                    return;
                }
            }
        }
        cout << "No se encontró un vehículo con esa placa.\n";
    }

    void devolverVehiculo(const string& placa) {
        for (auto& v : vehiculos) {
            if (v->getPlaca() == placa) {
                if (!v->estaDisponible()) {
                    v->devolver();
                    cout << "Vehículo devuelto: ";
                    v->mostrarInformacion();
                    return;
                } else {
                    cout << "Este vehículo ya estaba disponible.\n";
                    return;
                }
            }
        }
        cout << "No se encontró un vehículo con esa placa.\n";
    }
};

// Función principal
int main() {
    SistemaAlquiler sistema;

    // Registrar algunos vehículos
    sistema.registrarVehiculo(make_shared<Auto>("Toyota", "Corolla", "ABC123", 5));
    sistema.registrarVehiculo(make_shared<Bicicleta>("Trek", "Marlin 7", "BIC001", "Montaña"));
    sistema.registrarVehiculo(make_shared<Auto>("Ford", "Focus", "DEF456", 4));

    sistema.mostrarDisponibles();

    // Alquilar un vehículo
    sistema.alquilarVehiculo("ABC123");

    sistema.mostrarDisponibles();

    // Devolver el vehículo
    sistema.devolverVehiculo("ABC123");

    sistema.mostrarDisponibles();

    return 0;
}