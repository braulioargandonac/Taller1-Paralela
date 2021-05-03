#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Estudiante.h"
#include "Funciones.h"

using namespace std;
//Ir a la carpeta del programa en la terminal y ejecutar lo siguiente:
//1) make
//2) ./dist/programa estudiantes.csv
//por cada cambio que quieran probar deberar ejecutarlo así

void participantes(); //Función que muestra los participantes del grupo
/**
 *
 * @param fila una línea del archivo
 * @return vector con los datos del archivo csv
 */
std::vector<std::string> obtenerDatos(std::string fila);


int main(int argc, char** argv) {
    std::vector<Estudiante> E; //Se crea un vector de tipo Estudiante
    Estudiante A;
    int cont=1;
    if (argc > 1) {
        std::string archivo(argv[1]);
        std::ifstream lectura(archivo);
        std::ofstream escritura("promedio.csv");
        if (lectura) {
            std::cout << "Si lee el archivo" << std::endl;
            for (std::string linea; getline(lectura,linea) ; ) {
                std::vector<std::string> datos = obtenerDatos(linea);
                std::cout << cont << std::endl;
                cont++;
                datos.clear();
            }
        }
    }else{
        participantes();
    }
    return EXIT_SUCCESS;
}

void participantes() {
    std::cout << std::endl << "=== Taller 1 ===" << std::endl;
    std::cout << std::endl << "- Braulio Argandoña"  << std::endl;
    std::cout << std::endl << "- Kevin Salinas"  << std::endl;
    std::cout << std::endl << "- Rodrigo Aguirre"  << std::endl;
}

std::vector<std::string> obtenerDatos(std::string fila) {
    std::vector<std::string> arreglo;
    std::stringstream ss(fila);
    std::string item;
    int cont=0;
    // ss -> "1";"Estudiante 00001";"5.000000";"5.100000";"5.000000";"4.600000";"4.400000";"4.200000";"4.200000";"5.800000"

    while (std::getline(ss, item, ';')) {
        if(cont!=0 && cont!=1){
            arreglo.push_back(item.c_str());
        }
        cont++;
    }
    return arreglo;
}

