#ifndef SAVEFLIGHTDATA_HPP
#define SAVEFLIGHTDATA_HPP
#include "Posicion.hpp"
#include "Presion.hpp"

class SaveFlightData {
    public:
        Posicion posicion;
        Presion presion;
        SaveFlightData(Posicion& posicion, Presion& presion);
        void serializar(std::ostream & out) const;
        void deserializar(std::ifstream & in);
        void imprimir() const;
        ~SaveFlightData() = default;
};

#endif