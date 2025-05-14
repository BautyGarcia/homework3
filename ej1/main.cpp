#include "main.hpp"

MedicionBase::MedicionBase(float tiempoMedicion) {
    this->tiempoMedicion = make_unique<float>(tiempoMedicion);
};

void MedicionBase::serializar(ostream& out) const {
    out.write(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

void MedicionBase::deserializar(ifstream& in) {
    unique_ptr<float> tiempoMedicion = make_unique<float>(0);
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

float MedicionBase::getTiempo() const {
    return *tiempoMedicion;
};

Presion::Presion(float presionEstatica, float presionDinamica, float tiempoMedicion) : 
    MedicionBase(tiempoMedicion),
    presionEstatica(presionEstatica),
    presionDinamica(presionDinamica) 
{};

void Presion::serializar(ostream& out) const {
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion::deserializar(ifstream& in) {
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion::imprimir() const {
    cout << "Presion Estatica: " << presionEstatica << endl;
    cout << "Presion Dinamica: " << presionDinamica << endl;
    cout << "Tiempo de Medicion: " << getTiempo() << endl;
}

Posicion::Posicion(float latitud, float longitud, float altitud, float tiempoMedicion) :
    MedicionBase(tiempoMedicion),
    latitud(latitud),
    longitud(longitud),
    altitud(altitud)
{};

void Posicion::serializar(ostream& out) const {
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
}

void Posicion::deserializar(ifstream& in) {
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
}

void Posicion::imprimir() const {   
    cout << "Latitud: " << latitud << endl;
    cout << "Longitud: " << longitud << endl;
    cout << "Altitud: " << altitud << endl;
    cout << "Tiempo de Medicion: " << getTiempo() << endl;
}



int main() {
    try {
        Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3);
        Presion presion(101.3f, 5.8f, 6.1f);

        posicion.imprimir();
        presion.imprimir();
        return 0;
    } catch (const std::bad_alloc& e) {
        cerr << "Error de memoria: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Error." << endl;
        return 1;
    }
}