#ifndef MEDICIONBASE_HPP
#define MEDICIONBASE_HPP
#include <memory>
#include "IMediciones.hpp"

class MedicionBase: public IMediciones {
    protected:
        std::unique_ptr<float> tiempoMedicion;
    public:
        MedicionBase(float tiempoMedicion);
        MedicionBase(const MedicionBase& other);
        virtual void serializar(std::ostream& out) const override;
        virtual void deserializar(std::ifstream& in) override;
        float getTiempo() const;
        virtual void imprimir() const = 0;
        virtual ~MedicionBase() = default;
};

#endif