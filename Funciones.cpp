#include "Funciones.h"

void Participantes() {
    std::cout << std::endl << "=== Taller 1 ===" << std::endl;
    std::cout << std::endl << "- Braulio Argandoña"  << std::endl;
    std::cout << std::endl << "- Kevin Salinas"  << std::endl;
    std::cout << std::endl << "- Rodrigo Aguirre"  << std::endl;
}

std::vector<std::string> ObtenerDatos(std::string fila) {
    std::vector<std::string> arreglo;
    std::stringstream ss(fila);
    std::string item;
    // ss -> "1";"Estudiante 00001";"5.000000";"5.100000";"5.000000";"4.600000";"4.400000";"4.200000";"4.200000";"5.800000"

    while (std::getline(ss, item, ';')) {
        std::string dato=item.c_str();
        dato.erase(dato.begin());
        dato.pop_back();
        arreglo.push_back(dato);
    }
    return arreglo;
}

void Maximos(Estudiante A){
    float promedios = A.GetNotas(0) + A.GetNotas(1) + A.GetNotas(2) + A.GetNotas(3) + A.GetNotas(4) + A.GetNotas(5) + A.GetNotas(6) + A.GetNotas(7);
    promedios /= 8;
    //std::cout << A.GetIdent() << ";" << "Promedios: " << promedios << std::endl;
    A.SetPromedios(promedios);
}

void PromedioArte(Estudiante A){
    float suma = A.GetNotas(6)+ A.GetNotas(7);
    suma = suma / 2;
    //std::cout << A.GetIndice() << ";" << A.GetIdent() << ";"  << "Promedio de Arte: " << suma << std::endl;
    A.SetArtes(suma);
}

void PromedioHumanidades(Estudiante A){
    float suma = A.GetNotas(0)+ A.GetNotas(4);
    suma = suma / 2;
    //std::cout << A.GetIndice() << ";" << A.GetIdent() << ";" << "Promedio de Humanidades: " << suma << std::endl;
    A.SetHumanidades(suma);
} 

void PromedioTecnicos(Estudiante A){
    //std::cout << A.GetNotas(2) <<" - "<< A.GetNotas(3) <<" - "<< A.GetNotas(5) << std::endl;
    float suma = A.GetNotas(2) + A.GetNotas(3) + A.GetNotas(5);
    suma = suma / 3;
    //std::cout << A.GetIndice() << ";" << A.GetIdent() << ";" << "Promedio de Tecnicos: " << suma << std::endl;
    A.SetTecnicos(suma);
} 


//En esta función pasa algo raro, pueden verificar descomentando el comentario
void llenarPromedios(Estudiante A){
    PromedioArte(A);
    PromedioHumanidades(A);
    PromedioTecnicos(A);
    Maximos(A);
    //std::cout << A.GetArtes() <<" ; "<< A.GetHumanidades() <<" ; "<<  A.GetTecnicos() << std::endl;
}

