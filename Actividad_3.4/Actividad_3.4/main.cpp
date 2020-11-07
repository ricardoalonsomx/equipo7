//
//  main.cpp
//  Actividad_3.4
//
//  Created by Arturo Sosa on 05/11/20.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <map>
#include "Registro.hpp"
#include "ConexionesComputadora.hpp"
#include "BST.hpp"

auto read_csv_strings(std::string filename){
    
    /* Crear un vector de vector de strings */
    std::vector< std::vector<std::string> > lineas;

    /* Crear un input filestream para leer el archivo CSV */
    std::ifstream file(filename);

    /* Verificar si no hubo error al abrir el archivo */
    if(!file.is_open()) throw std::runtime_error("No se puede abrir el archivo");

    /* Definir variable que almacena cada línea */
    std::string linea;
    
    /* Leer datos línea a línea */
    while(std::getline(file, linea))
    {
        /* Crear un steam de la línea */
        std::stringstream ss(linea);
    
        /* Variable que almacena cada campo leído */
        std::string campo;
        
        /* Definir un vector para almacenar cada campo */
        std::vector<std::string> fila;
        
        /* Iterar sobre la línea para extraer cada campo */
        while(std::getline(ss, campo, ','))
        {
            fila.push_back(campo);
        }
        
        /* Insertar la fila con los campos separados en un vector */
        lineas.push_back(fila);
    }

    /* Cerrar el archivo */
    file.close();

    /* Regresar el vector de líneas leídas */
    return lineas;
}
                
auto read_csv_registro(std::string filename)
{
    /* Crear un vector de vector de strings */
    std::vector< Registro > lineas;

    /* Crear un input filestream para leer el archivo CSV */
    std::ifstream file(filename);

    /* Verificar si no hubo error al abrir el archivo */
    if(!file.is_open()) throw std::runtime_error("No se puede abrir el archivo");

    /* Definir variable que almacena cada línea */
    std::string linea;
    
    /* Leer datos línea a línea */
    while(std::getline(file, linea))
    {
        /* Crear un steam de la línea */
        std::stringstream ss(linea);
    
        /* Variables que almacenan cada campo leído */
        std::string fecha;
        std::string hora;
        std::string origen;
        std::string destino;
        std::string puertoOrigen;
        std::string nombreOringen;
        std::string puertoDestino;
        std::string nombreDestino;
        
        /* Iterar sobre la línea para extraer cada campo */
        getline(ss, fecha, ',');
        getline(ss, hora, ',');
        getline(ss, origen, ',');
        getline(ss, destino, ',');
        getline(ss, puertoOrigen, ',');
        getline(ss, nombreOringen, ',');
        getline(ss, puertoDestino, ',');
        getline(ss, nombreDestino, ',');
        
        /* Insertar la fila con los campos separados en un vector */
        lineas.push_back(Registro(fecha, hora, origen, destino, puertoOrigen, nombreOringen, puertoDestino, nombreDestino));
    }

    /* Cerrar el archivo */
    file.close();

    /* Regresar el vector de líneas leídas */
    return lineas;
}


bool checkReto(string sitio){
    int length = (int) sitio.length();
    
    if(length >= 8){
        int start = length-8;
        int j = 0;
        string reto = "reto.com";
        
        
        for(int i = start; i<length; i++){
            
            if(sitio.at(i) != reto.at(j))
                return true;
            j++;
        }
    }
    return false;
}

map <string, int> conexionesPorDia(string fecha, std::vector< Registro > registros){
    
    map <string, int>  mapaDelDia = map <string, int>();
    
    
    
    return mapaDelDia;
}

void top(int n, string fecha, map <string, int>){
    BST< map <string, int> > arbol;
    
    
    arbol.insert(conexionesPorDia(registros, fecha));

    cout << arbol.inOrden(i);
    
    arbol.clear();
}


int main(int argc, const char * argv[]){
    std::map <string, int> mapaDelDia;
    string value = "192.168.57.";
    
    std::cout << std::endl << std::endl;
    
    /* Lectura de los datos como un objeto Registros */
    std::vector< Registro > registros = read_csv_registro("equipo7.csv");
    int sizeOfRegistros = (int)registros.size();
    string fechaTemp1;
    string fechaTemp2;
    
    
    for(int i = 0; i<sizeOfRegistros; i++){
        fechaTemp1 = registros.at(0).Fecha();
        fechaTemp2 = fechaTemp1;
        top(5, fechaTemp1, conexionesPorDia(fechaTemp1, registros));
    
        
        if(i+1 <= sizeOfRegistros){
    
                fechaTemp2 = fechaTemp1;
    
                while(fechaTemp2 == fechaTemp1){
                    i++;
                    fechaTemp1 = registros.at(i).Fecha();
                }
            }
        }
    
    registros.clear();
    return 0;
}
