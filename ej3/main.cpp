#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

template<typename T>
string vectorToString(const vector<T>& vec) {
    if constexpr (is_integral_v<T> || is_floating_point_v<T>) {
        ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            if constexpr (is_floating_point_v<T>)
                oss << fixed << setprecision(1);  // Solamente para que quede mas lindo

            oss << vec[i];
            if (i < vec.size() - 1)
                oss << ", ";
        }
        oss << "]";
        return oss.str();
    } else {
        return "Tipo de dato no soportado";
    }
}

template<typename T>
class Contenedor {
    std::vector<T> elementos;
public:
    void agregar(const T& elem) {
        elementos.push_back(elem);
    }

    string procesar() const {
        if (elementos.empty()) {
            return "Sin datos";
        }
        if constexpr (is_same_v<T, double>) {
            return vectorToString(elementos);
        }
        else if constexpr (is_same_v<T, string>) {
            string resultado = "[";
            for (size_t i = 0; i < elementos.size(); ++i) {
                resultado += "\"" + elementos[i] + "\"";
                if (i < elementos.size() - 1) {
                    resultado += ", ";
                }
            }
            resultado += "]";
            return resultado;
        }
        else if constexpr (is_same_v<T, vector<int>>) {
            string resultado = "[ \n";
            for (size_t i = 0; i < elementos.size(); ++i) {
                resultado += "\t" + vectorToString(elementos[i]);  // margen manual
                if (i < elementos.size() - 1) {
                    resultado += ", \n";
                }
            }
            resultado += "\n  ]";
            return resultado;
        }
        else {
            return "Tipo de dato no soportado";
        }
    }
};

class JSONGenerator {
    private:
        vector<pair<string, string>> info;
    public:
        template<typename T>
        void agregar(const string& key, const Contenedor<T>& value) {
            info.push_back(make_pair(key, value.procesar()));
        }

        void imprimir() const {
            cout << "{" << endl;
            for (size_t i = 0; i < info.size(); ++i) {
                cout << "  \"" << info[i].first << "\": " << info[i].second;
                if (i < info.size() - 1) {
                    cout << ",";
                }
                cout << endl;
            }
            cout << "}" << endl;
        }
};

int main() {
    Contenedor<double> doubles;
    doubles.agregar(1.3);
    doubles.agregar(2.1);
    doubles.agregar(3.2);

    Contenedor<string> palabras;
    palabras.agregar("Hola");
    palabras.agregar("Mundo");

    Contenedor<vector<int>> listas;
    listas.agregar({1, 2});
    listas.agregar({3, 4});

    JSONGenerator generador;
    generador.agregar("vec_doubles", doubles);
    generador.agregar("palabras", palabras);
    generador.agregar("listas", listas);

    generador.imprimir();
    return 0;
}
