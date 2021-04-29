#include "Estudiante.h"
#include <iostream>

using namespace std;

Estudiante::Estudiante(){
}

int Estudiante::GetIndice(){
    return indice;
}

std::string Estudiante::GetIdent(){
    return ident;
}

float Estudiante::GetArtes(){
    return artisticos;
}

float Estudiante::GetHumanidades(){
    return humanistas;
}

float Estudiante::GetTecnicos(){
    return tecnicos;
}

std::vector<float> Estudiante::GetNotas(){
    return notas;
}

void Estudiante::SetIndice(int indice1){
    indice=indice1;
}

void Estudiante::SetIdent(std::string nombre){
    ident=nombre;
}

void Estudiante::SetArtes(float nota){
    artisticos=nota;
}

void Estudiante::SetHumanidades(float nota){
    humanistas=nota;
}

void Estudiante::SetTecnicos(float nota){
    tecnicos=nota;
}

void Estudiante::SetNotas(float nota){
    notas.push_back(nota);
}

