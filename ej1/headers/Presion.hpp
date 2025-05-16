#ifndef PRESION_HPP
#define PRESION_HPP
#include "MedicionBase.hpp"

class Presion: public MedicionBase {
    public:
        float presionEstatica;
        float presionDinamica;
        Presion(float presionEstatica, float presionDinamica, float tiempoMedicion);
        void serializar(std::ostream& out) const override;
        void deserializar(std::ifstream& in) override;
        void imprimir() const override;
        ~Presion() = default;
};

#endif