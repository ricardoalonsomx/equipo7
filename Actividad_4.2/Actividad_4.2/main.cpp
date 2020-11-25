//
//  main.cpp
//  Actividad_4.2
//
//  Created by Arturo Sosa on 22/11/20.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Graph/Graph.hpp"
#include "Registro/Registro.hpp"

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

bool duplicated(std::string tempString, std::vector< std::string > aux){
    int length = (int)aux.size();
    for(int i = 0; i<length; i++){
        if(tempString == aux.at(i))
            return true;
    }
    return false;
}

void wait(){
    char rest = 'x';
    while (rest!='C') {
        std::cout<< "Introduzca C para continuar: ";
        std::cin>>rest;
    }
}


int main(int argc, const char * argv[]) {
    std::vector< Registro > registros = read_csv_registro("equipo7.csv");
    std::vector< std::string > auxiliar_ips;
    std::vector< std::string > auxiliar_nombres;
    std::string nombre;
    std::string ip;
    Graph< std::string, std::string > * ips = new Graph< std::string, std::string >();
    Graph< std::string, std::string > * nombres = new Graph< std::string, std::string >();
    int length = (int)registros.size();
    Registro registro_temp;
    wait();
//    std::cout<<"Origen: "<<registros.at(3).getOrigen()<<std::endl;
//    std::cout<<"NombreOrigen: "<<registros.at(3).getNombreOrigen()<<std::endl;
//    std::cout<<"Fecha: "<<registros.at(3).Fecha()<<std::endl;
//    std::cout<<"Destino: "<<registros.at(3).getDestino()<<std::endl;
//    std::cout<<"NombreDestino:"<<registros.at(3).getNombreDestino()<<std::endl;
    for(int i=0; i<length; i++){
        registro_temp = registros.at(i);
        nombre = registro_temp.getNombreOrigen();
        ip = registro_temp.getOrigen();
        auxiliar_ips.push_back(ip);
        auxiliar_nombres.push_back(nombre);
        
        Vertex<std::string, std::string> * edgeVertexOrigen = new Vertex<std::string, std::string>(ip);
        Vertex<std::string, std::string> * edgeVertexDestino = new Vertex<std::string, std::string>(registro_temp.getDestino());
        
        Vertex<std::string, std::string> * edgeVertexNombreOrigen = new Vertex<std::string, std::string>(nombre);
        Vertex<std::string, std::string> * edgeVertexNombreDestino = new Vertex<std::string, std::string>(registro_temp.getNombreDestino());

        if(duplicated(ip, auxiliar_ips) || duplicated(nombre, auxiliar_nombres)){
            ips->addVertex(edgeVertexOrigen);
            nombres->addVertex(edgeVertexNombreOrigen);

        }
        
        ips->addVertex(edgeVertexDestino);
        nombres->addVertex(edgeVertexNombreDestino);
        
        ips->addEdge(
                     edgeVertexOrigen,
                     edgeVertexDestino, "");

        nombres->addEdge(
                         edgeVertexNombreOrigen,
                         edgeVertexNombreDestino, "");
        
        std::cout << "Datos añadidos: " << (float)100*i/length <<"%" << std::endl;
    }
    auxiliar_ips.empty();
    auxiliar_nombres.empty();
    
    
//    for(int i=0; i<length; i++){
//        registro_temp = registros.at(i);
//
//        Vertex<std::string, std::string> * edgeVertexOrigen = new Vertex<std::string, std::string>(registro_temp.getOrigen());
//        Vertex<std::string, std::string> * edgeVertexDestino = new Vertex<std::string, std::string>(registro_temp.getDestino());
//
//        Vertex<std::string, std::string> * edgeVertexNombreOrigen = new Vertex<std::string, std::string>(registro_temp.getNombreOrigen());
//        Vertex<std::string, std::string> * edgeVertexNombreDestino = new Vertex<std::string, std::string>(registro_temp.getNombreDestino());
//
//        ips->addVertex(edgeVertexOrigen);
//        ips->addVertex(edgeVertexDestino);
//
//        nombres->addVertex(edgeVertexNombreOrigen);
//        nombres->addVertex(edgeVertexNombreDestino);
//
//        ips->addEdge(
//                     edgeVertexOrigen,
//                     edgeVertexDestino, "");
//
//        nombres->addEdge(
//                         edgeVertexNombreOrigen,
//                         edgeVertexNombreDestino, "");
//    }
//
    
    std::cout<<nombres->getMasDestinos()<<std::endl;
    
//    wait();
//    std::cout<< *ips <<std::endl;
//    wait();
//    std::cout<< *nombres <<std::endl;
    
    delete ips;
    delete nombres;
    return 0;
}
