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


void PromedioArte(Estudiante);
void PromedioHumanidades(Estudiante);
void PromedioTecnicos(Estudiante);
void llenarPromedios(Estudiante);
void Maximos(Estudiante);

#endif // FUNCIONES_H_INCLUDED
