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
        std::ofstream escritura("maximos.csv");
        std::ofstream escrituraA("artistico.csv");
        std::ofstream escrituraH("humanismo.csv");
        std::ofstream escrituraT("tecnicos.csv");
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
            std::string salida;
            std::string salidaA;
            std::string salidaH;
            std::string salidaT;

            quicksort(E, 0, c);
            for(int i=0; i<99; i++){
                salida = std::to_string(E[i].GetIndice())+ ";" + E[i].GetIdent() + ";" + std::to_string(E[i].GetPromedios());
                escritura << salida << std::endl;
            }
            salida = std::to_string(E[99].GetIndice())+ ";" + E[99].GetIdent() + ";" + std::to_string(E[99].GetPromedios());
            escritura << salida;
            salida.clear();

            E.erase(E.begin(), E.begin()+100);

            quicksortA(E, 0, c-100);

            for(int i=0; i<99; i++){
                salidaA = std::to_string(E[i].GetIndice())+ ";" + E[i].GetIdent() + ";" + std::to_string(E[i].GetArtes());
                escrituraA << salidaA << std::endl;
            }
            salidaA = std::to_string(E[99].GetIndice())+ ";" + E[99].GetIdent() + ";" + std::to_string(E[99].GetArtes());
            escrituraA << salidaA;
            salidaA.clear();

            E.erase(E.begin(), E.begin()+100);

            quicksortH(E, 0, c-200);

            for(int i=0; i<99; i++){
                salidaH = std::to_string(E[i].GetIndice())+ ";" + E[i].GetIdent() + ";" + std::to_string(E[i].GetHumanidades());
                escrituraH << salidaH << std::endl;
            }
            salidaH = std::to_string(E[99].GetIndice())+ ";" + E[99].GetIdent() + ";" + std::to_string(E[99].GetHumanidades());
            escrituraH << salidaH;
            salidaH.clear();

            E.erase(E.begin(), E.begin()+100);

            quicksortT(E, 0, c-300);

            for(int i=0; i<99; i++){
                salidaT = std::to_string(E[i].GetIndice())+ ";" + E[i].GetIdent() + ";" + std::to_string(E[i].GetTecnicos());
                escrituraT<< salidaT << std::endl;
            }
            salidaT = std::to_string(E[99].GetIndice())+ ";" + E[99].GetIdent() + ";" + std::to_string(E[99].GetTecnicos());
            escrituraT << salidaT;
            salidaT.clear();

            E.erase(E.begin(), E.begin()+100);
        }
    }else{
        Participantes();
    }
    return EXIT_SUCCESS;
}

