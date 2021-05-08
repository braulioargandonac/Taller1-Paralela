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

void Maximos(Estudiante &A){
    float promedios = A.GetNotas(0) + A.GetNotas(1) + A.GetNotas(2) + A.GetNotas(3) + A.GetNotas(4) + A.GetNotas(5) + A.GetNotas(6) + A.GetNotas(7);
    promedios /= 8;
    //std::cout << A.GetIdent() << ";" << "Promedios: " << promedios << std::endl;
    A.SetPromedios(promedios);
}

void PromedioArte(Estudiante &A){
    float suma = A.GetNotas(6)+ A.GetNotas(7);
    suma = suma / 2;
    //std::cout << A.GetIndice() << ";" << A.GetIdent() << ";"  << "Promedio de Arte: " << suma << std::endl;
    A.SetArtes(suma);
}

void PromedioHumanidades(Estudiante &A){
    float suma = A.GetNotas(0)+ A.GetNotas(4);
    suma = suma / 2;
    //std::cout << A.GetIndice() << ";" << A.GetIdent() << ";" << "Promedio de Humanidades: " << suma << std::endl;
    A.SetHumanidades(suma);
} 

void PromedioTecnicos(Estudiante &A){
    //std::cout << A.GetNotas(2) <<" - "<< A.GetNotas(3) <<" - "<< A.GetNotas(5) << std::endl;
    float suma = A.GetNotas(2) + A.GetNotas(3) + A.GetNotas(5);
    suma = suma / 3;
    //std::cout << A.GetIndice() << ";" << A.GetIdent() << ";" << "Promedio de Tecnicos: " << suma << std::endl;
    A.SetTecnicos(suma);
} 


//En esta función pasa algo raro, pueden verificar descomentando el comentario
void llenarPromedios(Estudiante &A){
    PromedioArte(A);
    PromedioHumanidades(A);
    PromedioTecnicos(A);
    Maximos(A);
    //std::cout << A.GetArtes() <<" ; "<< A.GetHumanidades() <<" ; "<<  A.GetTecnicos() << std::endl;
}

void quicksort(std::vector<Estudiante> &E,int prim,int ult){
    int j,i,pivot; 
    if(prim<ult){
        pivot=prim;
        i=prim;
        j=ult;
        while(i<j){
            while(E[i].GetPromedios() >= E[pivot].GetPromedios() && i < ult){
                i++;
            }
            while(E[j].GetPromedios() < E[pivot].GetPromedios()){
                j--;}
            if(i<j){
                std::swap(E[j], E[i]);
            }
        }
        std::swap(E[pivot], E[j]);
        quicksort(E, prim, j-1);
        quicksort(E, j+1, ult);
    }
}

void quicksortA(std::vector<Estudiante> &E,int prim,int ult){
    int j,i,pivot; 
    if(prim<ult){
        pivot=prim;
        i=prim;
        j=ult;
        while(i<j){
            while(E[i].GetArtes() >= E[pivot].GetArtes() && i < ult){
                i++;
            }
            while(E[j].GetArtes() < E[pivot].GetArtes()){
                j--;}
            if(i<j){
                std::swap(E[j], E[i]);
            }
        }
        std::swap(E[pivot], E[j]);
        quicksortA(E, prim, j-1);
        quicksortA(E, j+1, ult);
    }
}

void quicksortH(std::vector<Estudiante> &E,int prim,int ult){
    int j,i,pivot; 
    if(prim<ult){
        pivot=prim;
        i=prim;
        j=ult;
        while(i<j){
            while(E[i].GetHumanidades() >= E[pivot].GetHumanidades() && i < ult){
                i++;
            }
            while(E[j].GetHumanidades() < E[pivot].GetHumanidades()){
                j--;}
            if(i<j){
                std::swap(E[j], E[i]);
            }
        }
        std::swap(E[pivot], E[j]);
        quicksortH(E, prim, j-1);
        quicksortH(E, j+1, ult);
    }
}

void quicksortT(std::vector<Estudiante> &E,int prim,int ult){
    int j,i,pivot; 
    if(prim<ult){
        pivot=prim;
        i=prim;
        j=ult;
        while(i<j){
            while(E[i].GetTecnicos() >= E[pivot].GetTecnicos() && i < ult){
                i++;
            }
            while(E[j].GetTecnicos() < E[pivot].GetTecnicos()){
                j--;}
            if(i<j){
                std::swap(E[j], E[i]);
            }
        }
        std::swap(E[pivot], E[j]);
        quicksortT(E, prim, j-1);
        quicksortT(E, j+1, ult);
    }
}


/*
bool Busqueda(std::string r, std::string arch){ //Recibe el rut y el nombre del archivo
    std::ifstream lec(arch);
    int cont=0; //variable para la linea
    if (lec) {
        for (std::string linea; getline(lec,linea) ; ){ //Lee la linea hasta el punto y coma
            cont = cont + 1; //Contador para la linea
            std::stringstream ss(linea); //La linea que esta leyendo 17424518;639.66667 -> ss
            std::string rut; //Variable para guardar el rut que estoy leyendo
            std::getline(ss, rut, ';'); //Lo que quiero separar, donde lo guardo, que lo separa
            if(r==rut){
                //Mostrar linea donde se encuentra, y el nombre del archivo donde se encontro
                std::cout<<"Se encontro el rut en: " << arch << std::endl;
                std::cout<<"Rut: "<<rut<<std::endl;
                std::cout<<"Posicion: "<<cont<<std::endl;//Linea donde esta el archivo
                return true;
            }
        }
    }
    return false;
}
*/

