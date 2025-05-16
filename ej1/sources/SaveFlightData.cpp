#include "../headers/SaveFlightData.hpp"
#include <iostream>
#include <fstream>

SaveFlightData::SaveFlightData(Posicion& posicion, Presion& presion):
    posicion(posicion),
    presion(presion)
{}

void SaveFlightData::serializar(std::ostream& out) const {
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(std::ifstream& in) {
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir() const {
    posicion.imprimir();
    presion.imprimir();
} 