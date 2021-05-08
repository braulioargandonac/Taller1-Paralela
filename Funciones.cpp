#include "Funciones.h"

void Participantes() {
    std::cout << std::endl << "Creado por:" << std::endl;
    std::cout << std::endl << "- Braulio Argandoña"  << std::endl;
    std::cout << std::endl << "- Kevin Salinas"  << std::endl;
    std::cout << std::endl << "- Rodrigo Aguirre"  << std::endl<< std::endl;
}

std::vector<std::string> ObtenerDatos(std::string fila){
    std::vector<std::string> arreglo;
    std::stringstream ss(fila);
    std::string item;

    while (std::getline(ss, item, ';')){
        std::string dato=item.c_str();
        dato.erase(dato.begin());
        dato.pop_back();
        arreglo.push_back(dato);
    }

    return arreglo;
}

void Maximos(Estudiante &A){
    float promedios = A.GetNotas(0) + A.GetNotas(1) + A.GetNotas(2) + A.GetNotas(3) + A.GetNotas(4) + A.GetNotas(5) + A.GetNotas(6) + A.GetNotas(7);
    promedios /= 8;
    A.SetPromedios(promedios, 0);
}

void PromedioArte(Estudiante &A){
    float suma = A.GetNotas(6)+ A.GetNotas(7);
    suma /= 2;
    A.SetPromedios(suma, 1);
}

void PromedioHumanidades(Estudiante &A){
    float suma = A.GetNotas(0)+ A.GetNotas(4);
    suma /= 2;
    A.SetPromedios(suma, 2);
} 

void PromedioTecnicos(Estudiante &A){
    float suma = A.GetNotas(2) + A.GetNotas(3) + A.GetNotas(5);
    suma /= 3;
    A.SetPromedios(suma, 3);
} 

void llenarPromedios(Estudiante &A){
    PromedioArte(A);
    PromedioHumanidades(A);
    PromedioTecnicos(A);
    Maximos(A);
}

void quicksort(std::vector<Estudiante> &E, int prim, int ult, int ind){
    int j, i, pivot;

    if(prim < ult){

        pivot = prim;
        i = prim;
        j = ult;

        while(i < j){

            while(E[i].GetPromedios(ind) >= E[pivot].GetPromedios(ind) && i < ult){
                i++;
            }

            while(E[j].GetPromedios(ind) < E[pivot].GetPromedios(ind)){
                j--;
            }

            if(i < j){
                std::swap(E[j], E[i]);
            }

        }

        std::swap(E[pivot], E[j]);
        quicksort(E, prim, j-1, ind);
        quicksort(E, j+1, ult, ind);
    }
}

void Funciones(std::vector<Estudiante> E, int c){

    std::ofstream escritura("maximos.csv");
    std::ofstream escrituraA("artistico.csv");
    std::ofstream escrituraH("humanismo.csv");
    std::ofstream escrituraT("tecnicos.csv");
    std::string salida;

    quicksort(E, 0, c, 0);

    for(int i=0; i<99; i++){
        salida = '"' + std::to_string(E[i].GetIndice())+ '"' +";" + '"' +E[i].GetIdent() + '"' + ";" + '"' + std::to_string(E[i].GetPromedios(0))+ '"';
        escritura << salida << std::endl;
    }

    salida = '"' + std::to_string(E[99].GetIndice())+ '"' +";" + '"' + E[99].GetIdent() + '"' + ";" + std::to_string(E[99].GetPromedios(0)) + '"';
    escritura << salida;
    salida.clear();

    E.erase(E.begin(), E.begin()+100);

    quicksort(E, 0, c-100, 1);

    for(int i=0; i<99; i++){
        salida = '"' + std::to_string(E[i].GetIndice())+ '"' +";" + '"' +E[i].GetIdent() + '"' + ";" + '"' + std::to_string(E[i].GetPromedios(1))+ '"';
        escrituraA << salida << std::endl;
    }

    salida = '"' + std::to_string(E[99].GetIndice())+ '"' +";" + '"' + E[99].GetIdent() + '"' + ";" + std::to_string(E[99].GetPromedios(1)) + '"';
    escrituraA << salida;
    salida.clear();
    
    quicksort(E, 0, c-200, 2);

    for(int i=0; i<99; i++){
        salida = '"' + std::to_string(E[i].GetIndice())+ '"' +";" + '"' +E[i].GetIdent() + '"' + ";" + '"' + std::to_string(E[i].GetPromedios(2))+ '"';
        escrituraH << salida << std::endl;
    }

    salida = '"' + std::to_string(E[99].GetIndice())+ '"' +";" + '"' + E[99].GetIdent() + '"' + ";" + std::to_string(E[99].GetPromedios(2)) + '"';
    escrituraH << salida;
    salida.clear();

    quicksort(E, 0, c-300, 3);

    for(int i=0; i<99; i++){
        salida = '"' + std::to_string(E[i].GetIndice())+ '"' +";" + '"' +E[i].GetIdent() + '"' + ";" + '"' + std::to_string(E[i].GetPromedios(3))+ '"';
        escrituraT << salida << std::endl;
    }

    salida = '"' + std::to_string(E[99].GetIndice())+ '"' +";" + '"' + E[99].GetIdent() + '"' + ";" + std::to_string(E[99].GetPromedios(3)) + '"';
    escrituraT << salida;
    salida.clear();
}
