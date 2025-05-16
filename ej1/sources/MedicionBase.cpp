#include "../headers/MedicionBase.hpp"
#include <iostream>
#include <fstream>

MedicionBase::MedicionBase(float tiempoMedicion) {
    this->tiempoMedicion = std::make_unique<float>(tiempoMedicion);
}

MedicionBase::MedicionBase(const MedicionBase& other) {
    this->tiempoMedicion = std::make_unique<float>(*(other.tiempoMedicion));
}

void MedicionBase::serializar(std::ostream& out) const {
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

void MedicionBase::deserializar(std::ifstream& in) {
    tiempoMedicion = std::make_unique<float>(0);
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

float MedicionBase::getTiempo() const {
    return *tiempoMedicion;
} 