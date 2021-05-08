#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Estudiante.h"

/**
 * Despliega los participantes del equipo de trabajo
 */
void Participantes(); //Función que muestra los participantes del grupo

/**
 * @param fila una línea del archivo
 * @return vector con los datos del archivo csv
 */
std::vector<std::string> ObtenerDatos(std::string fila);

/**
 * @param Estudiante recibe un objeto de clase Estudiante
 * Calcula el promedio entre todas las asignaturas
 * Modifica al estudiante con su promedio general
 */
void Maximos(Estudiante &);

/**
 * @param Estudiante recibe un objeto de clase Estudiante
 * Calcula el promedio entre Arte y Ed fisica
 * Modifica al estudiante con su promedio artistico
 */
void PromedioArte(Estudiante &);

/**
 * @param Estudiante recibe un objeto de clase Estudiante
 * Calcula el promedio entre Lenguaje e Historia
 * Modifica al estudiante con su promedio humanista
 */
void PromedioHumanidades(Estudiante &);

/**
 * @param Estudiante recibe un objeto de clase Estudiante
 * Calcula el promedio entre Tecnologia, Matematicas y Ciencias naturales
 * Modifica al estudiante con su promedio tecnico
 */
void PromedioTecnicos(Estudiante &);

/**
 * @param Estudiante recibe un objeto de clase Estudiante
 * Realiza el llamado de las funciones Promedio anteriores
 * Modifica al estudiante con todos sus promedios
 */
void llenarPromedios(Estudiante &);

/**
 * @param Estudiante recibe un vector de tipo clase Estudiante
 * @param inicio recibe el inicio del vector de tipo estudiante
 * @param fin recibe el final del vector de tipo estudiante
 * @param indice recibe el indice correspondiente al parametro para el cual ordenar (maximos, artisticos, humanismo o tecnicos)
 * Ordena el total de estudiantes del vector según el indice recibido
 * Modifica al vector Estudiante
 */
void quicksort(std::vector<Estudiante> &, int, int, int);

/**
 * @param Estudiante recibe un vector de tipo clase Estudiante
 * @param contador recibe la cantidad de estudiantes
 * Realiza el llamado de todas las funciones necesarias para el ordenamiento y escritura de archivos
 */
void Funciones(std::vector<Estudiante> , int );

#endif // FUNCIONES_H_INCLUDED
