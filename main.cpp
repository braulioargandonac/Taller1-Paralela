#include "Estudiante.h"
#include "Funciones.h"

using namespace std;
//Ir a la carpeta del programa en la terminal y ejecutar lo siguiente:
//1) make
//2) ./dist/programa estudiantes.csv
//por cada cambio que quieran probar deberar ejecutarlo así

int main(int argc, char** argv) {
    std::vector<Estudiante> E; //Se crea un vector de tipo Estudiante
    if (argc > 1) {
        std::string archivo(argv[1]);
        std::ifstream lectura(archivo);
        std::ofstream escritura("promedio.csv");
        int c=0;
        if (lectura) {
            std::cout << "Si lee el archivo" << std::endl;
            for (std::string linea; getline(lectura,linea) ; ) {
                std::vector<std::string> datos = ObtenerDatos(linea);
                Estudiante A;
                A.SetIndice(std::stoi(datos[0]));
                A.SetIdent(datos[1]);
                for(int j=2; j<10; j++){
                    A.SetNotas(std::stof(datos[j]));
                }
                llenarPromedios(A);
                E.push_back(A);
                c++;
                datos.clear();
            }

            //Acá escribo el archivo promedio de ejemplo para que lo revisen
            for(int i=0; i<c-1; i++){
                std::string salida = std::to_string(E[i].GetIndice())+ ";" + E[i].GetIdent() + ";";
                escritura << salida << std::endl;
            }
            //y esto lo hago aparte para no agregar el salto de linea al final en el ultimo ciclo
            std::string salida = std::to_string(E[c-1].GetIndice())+ ";" + E[c-1].GetIdent() + ";";
            escritura << salida;
        }
    }else{
        Participantes();
    }
    return EXIT_SUCCESS;
}

