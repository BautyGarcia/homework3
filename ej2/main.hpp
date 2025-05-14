#include <iostream>
#include <math.h>

using namespace std;

class Punto {
    public:
        Punto(float x, float y);
        float getX() const;
        float getY() const;
        ~Punto() = default;
    private:
        float x;
        float y;
};

class Rectangulo {
    public:
        Rectangulo(Punto& verticeInferiorIzquierdo, float ancho, float alto);
        float getAncho() const;
        float getAlto() const;
        Punto getPosicion() const;
        ~Rectangulo() = default;
    private:
        Punto posicion;
        float ancho;
        float alto;
};

class Circulo {
    public:
        Circulo(Punto& centro, float radio);
        float getRadio() const;
        Punto getCentro() const;
        ~Circulo() = default;
    private:
        Punto centro;
        float radio;
};

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

template<typename T>
struct ProcesadorFigura {
    void calcularArea(T& figura) {
        cout << "No se puede calcular el area de esta figura" << endl;
    }
};

template<>
struct ProcesadorFigura<Rectangulo> {
    float calcularArea(Rectangulo& rect) {
        return rect.getAncho() * rect.getAlto();
    }
};

template<>
struct ProcesadorFigura<Circulo> {
    float calcularArea(Circulo& circ) {
        return M_PI * circ.getRadio() * circ.getRadio();
    }
};

template<>
struct ProcesadorFigura<Elipse> {
    float calcularArea(Elipse& elip) {
        return M_PI * elip.getSemiejeMayor() * elip.getSemiejeMenor();
    }
};
