#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
#include <vector>

class Estudiante{
    private:
        int indice;                 //(0)
        std::string ident;          //(1)
        std::vector<float> notas;   //Lenguaje 0 ::  Ingles 1  :: Matematicas 2 :: Ciencias 3 :: Historia 4 :: Tecnologia 5 :: Arte 6 :: Ed fisica 7
        float promedio[4];            
        //PROMEDIO 0: total de notas de cada alumno
        //PROMEDIO 1: Arte(6) y Ed fisica(7)
        //PROMEDIO 2: Lenguaje(0) e historia(4)
        //PROMEDIO 3: Matematicas(2), Ciencias Naturales(3) y Tecnologia(5)
    public:
        Estudiante();
        ~Estudiante();
        
        int GetIndice();
        std::string GetIdent();
        float GetNotas(int);
        float GetPromedios(int);

        void SetIndice(int);
        void SetIdent(std::string);
        void SetNotas(float);
        void SetPromedios(float, int);
};

#endif
