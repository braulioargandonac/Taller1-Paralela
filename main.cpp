#include "Estudiante.h"
#include "Funciones.h"

//Ir a la carpeta del programa en la terminal y ejecutar lo siguiente:
//1) make
//2) ./dist/programa estudiantes.csv

int main(int argc, char** argv) {
    std::vector<Estudiante> E;

    if (argc > 1) {
        std::string archivo(argv[1]);
        std::ifstream lectura(archivo);
        int c=0;

        if (lectura) {
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
            c--;
            Funciones(E, c);
            std::cout<<std::endl<<"PROGRAMA EJECUTADO CORRECTAMENTE"<<std::endl;
            std::cout<<"SE HAN GENERADO LOS RESPECTIVOS ARCHIVOS"<<std::endl;
            Participantes();
        }else{
            std::cout<<std::endl<<"NO HA INGRESADO NINGUN ARCHIVO VALIDO"<<std::endl;
            Participantes();
        }
    }else{
        std::cout<<std::endl<<"NO HA INGRESADO NINGUN ARCHIVO"<<std::endl;
        Participantes();
    }
    return EXIT_SUCCESS;
}

