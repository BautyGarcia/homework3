#ifndef PROCESADORFIGURA_HPP
#define PROCESADORFIGURA_HPP
#include <iostream>
#include <math.h>
#include "Rectangulo.hpp"
#include "Circulo.hpp"
#include "Elipse.hpp"

using namespace std;

template<typename T>
class ProcesadorFigura {
    public:
        void calcularArea(T&) {
            cout << "No se puede calcular el area de esta figura" << endl;
        }
};

template<>
class ProcesadorFigura<Rectangulo> {
    public:
        float calcularArea(Rectangulo& rect) {
            return rect.getAncho() * rect.getAlto();
        }
};

template<>
class ProcesadorFigura<Circulo> {
    public:
        float calcularArea(Circulo& circ) {
            return M_PI * circ.getRadio() * circ.getRadio();
        }
};

template<>
class ProcesadorFigura<Elipse> {
    public:
        float calcularArea(Elipse& elip) {
            return M_PI * elip.getSemiejeMayor() * elip.getSemiejeMenor();
        }
};

#endif 