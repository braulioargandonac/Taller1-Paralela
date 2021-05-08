#include "Estudiante.h"
#include <iostream>

Estudiante::Estudiante(){
}

Estudiante::~Estudiante(){
}

int Estudiante::GetIndice(){
    return indice;
}

std::string Estudiante::GetIdent(){
    return ident;
}

float Estudiante::GetPromedios(int indice){
    return promedio[indice];
}

float Estudiante::GetNotas(int i){
    return notas.at(i);
}

void Estudiante::SetIndice(int indice1){
    indice=indice1;
}

void Estudiante::SetIdent(std::string nombre){
    ident=nombre;
}

void Estudiante::SetPromedios(float nota, int indice){
    promedio[indice] = nota;
}

void Estudiante::SetNotas(float nota){
    notas.push_back(nota);
}

