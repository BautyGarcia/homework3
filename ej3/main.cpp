#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

// Nota: Como no era tanto codigo decidi dejar todo en un solo archivo. Nose si es lo mejor pero me parecio adecuado en este caso. Abz.

// Funcion auxiliar para convertir vectores de numeros a string (como solo llamo a esto cunado es un vector de numeros, no necesito checkear el tipo)
template<typename T>
string vectorToString(const vector<T>& vec) {
    ostringstream oss; // Solamente para sacarle los decimales si es un double y quede mas lindo
    oss << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if constexpr (is_floating_point_v<T>)
            oss << fixed << setprecision(1);  // Capaz hice de mas pero queda muy lindo

        oss << vec[i];
        if (i < vec.size() - 1) // Checkeo para poner la coma o no
            oss << ", ";
    }
    oss << "]";
    return oss.str();
}

// Clase contenedora que guarda un vector de algo (tipo T) y devuelve su string correspondiente al procesar
template<typename T>
class Contenedor {
    std::vector<T> elementos;
public:
    void agregar(const T& elem) {
        elementos.push_back(elem);
    }

    string procesar() const {
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
                resultado += "\t  " + vectorToString(elementos[i]);  // margen manual ('\t  ')
                if (i < elementos.size() - 1) {
                    resultado += ", \n";
                }
            }
            resultado += "\n\t  ]";
            return resultado;
        }
        else { // Por las dudas si me pasan algo que no contemplo (no pasa nunca pero bueno)
            return "";
        }
    }
};

// Clase que asigna una key (string) a su valor (Contenedor<T> -> string)
class JSONGenerator {
    private:
        vector<pair<string, string>> info;
    public:
        template<typename T>
        void agregar(const string& key, const Contenedor<T>& value) {
            info.push_back(make_pair(key, value.procesar()));
        }

        void imprimir() const {
            cout << "{";
            for (size_t i = 0; i < info.size(); ++i) {
                if (i != 0) cout << " "; // Solamente para que quede IGUAL al ejemplo jadsjasjdasjd
                cout << " \"" << info[i].first << "\":" << info[i].second;
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
    // Nose porque el subrayado pero mariano dijo que tenia que ser igual
    palabras.agregar("H͟o͟l͟a͟");
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
