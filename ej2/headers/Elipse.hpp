#ifndef ELIPSE_HPP
#define ELIPSE_HPP
#include "Punto.hpp"

class Elipse {
    public:
        Elipse(Punto& centro, float semiejeMayor, float semiejeMenor);
        float getSemiejeMayor() const;
        float getSemiejeMenor() const;
        Punto getCentro() const;
        ~Elipse() = default;
    private:
        Punto centro;
        float semiejeMayor;
        float semiejeMenor;
};

#endif 