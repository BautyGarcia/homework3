#ifndef POSICION_HPP
#define POSICION_HPP
#include "MedicionBase.hpp"

class Posicion: public MedicionBase {
    public:
        float latitud;
        float longitud;
        float altitud;
        Posicion(float latitud, float longitud, float altitud, float tiempoMedicion);
        void serializar(std::ostream& out) const override;
        void deserializar(std::ifstream& in) override;
        void imprimir() const override;
        ~Posicion() = default;
};

#endif