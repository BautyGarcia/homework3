#ifndef PUNTO_HPP
#define PUNTO_HPP

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

#endif 