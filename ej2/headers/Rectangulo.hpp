#ifndef RECTANGULO_HPP
#define RECTANGULO_HPP
#include "Punto.hpp"

class Rectangulo {
    public:
        Rectangulo(Punto& verticeInferiorIzquierdo, float ancho, float alto);
        float getAncho() const;
        float getAlto() const;
        Punto getPosicion() const;
        void setAncho(float ancho);
        void setAlto(float alto);
        void setPosicion(Punto& posicion);
        ~Rectangulo() = default;
    private:
        Punto posicion;
        float ancho;
        float alto;
};

#endif 