#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
#include <vector>

class Estudiante{
    private:
        int indice;                 //(0)
        std::string ident;               //(1)
        std::vector<float> notas;   //Lenguaje 0 ::  Ingles 1  :: Matematicas 2 :: Ciencias 3 :: Historia 4 :: Tecnologia 5 :: Arte 6 :: Ed fisica 7
        float artisticos;           //PROMEDIO: Arte(6) y Ed fisica(7)
        float humanistas;           //PROMEDIO: Lenguaje(0) e historia(4)
        float tecnicos;             //PROMEDIO: Matematicas(2), Ciencias Naturales(3) y Tecnologia(5)
    public:
        Estudiante();
        int GetIndice();
        std::string GetIdent();
        std::vector<float> GetNotas();
        float GetArtes();
        float GetHumanidades();
        float GetTecnicos();

        void SetIndice(int);
        void SetIdent(std::string);
        void SetNotas(float);
        void SetArtes(float);
        void SetHumanidades(float);
        void SetTecnicos(float);
};

#endif