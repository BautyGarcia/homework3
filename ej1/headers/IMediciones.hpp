#ifndef IMEDICIONES_HPP
#define IMEDICIONES_HPP
#include <iostream>
#include <fstream>

class IMediciones {
    public:
        virtual void serializar(std::ostream& out) const = 0;
        virtual void deserializar(std::ifstream& in) = 0;
        virtual ~IMediciones() = default;
};

#endif
