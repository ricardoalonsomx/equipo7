//
//  ConexionesComputadora.hpp
//  Actividad 2.2
//
//  Created by Arturo Sosa on 13/10/20.
//  Copyright © 2020 Arturo Sosa. All rights reserved.
//

#ifndef ConexionesComputadora_hpp
#define ConexionesComputadora_hpp
#include <stdio.h>
#include "Registro.hpp"
#include "Queue/Queue.hpp"
#include "Stack/Stack.hpp"
using namespace std;


template <class T>
class ConexionesComputadora {
private:
    int ip;
    string nombre;
    string fecha;
    Stack<T> ConexionesEntrantes;
    Queue<T> ConexionesSalientes;
    
public:
    ConexionesComputadora() {};
    ConexionesComputadora(int Ip, string Nombre, string Fecha,
                          Stack<string> Entrantes, Queue<string> Salientes) {
        ip = Ip;
        nombre = Nombre;
        fecha = Fecha;
        ConexionesEntrantes = Entrantes;
        ConexionesSalientes = Salientes;
    }
    
    /* Setters */
    void setIp(int Ip){
        ip =Ip;
    }
    void setNombre(string Nombre) {
        nombre = Nombre;
    }
    void setFecha(string Fecha) {
        fecha = Fecha;
    }
    
    
    /* Getters */
    int getIp(){
        return ip;
    }
    string getNombre() {
        return nombre;
    }
    string getFecha() {
        return fecha;
    }
    
    
    
    void insertConexionesEntrantes(const T & value) {
        ConexionesEntrantes.push(value);
    }
    void insertConexionesSalientes(const T & value) {
        ConexionesSalientes.enqueue(value);
    }
    void insertConexionesSaientesFront(const T & value) {
        ConexionesSalientes.reverse();
        ConexionesSalientes.enqueue(value);
        ConexionesSalientes.reverse();
    }
    
    int sizeOfConexionesEntrantes(){
            return ConexionesEntrantes.size();
        }
        
    int sizeOfConexionesSalientes(){
        return ConexionesSalientes.size();
        }
    
    T getConexionesEntrantes() {
        T value;
        //value = *ConexionesEntrantes.top() -> getInfo();
        ConexionesEntrantes.pop();
        
        return value;
    }
    T getConexionesSalientes() {
        return ConexionesSalientes.dequeue() -> getInfo();
    }
    
    void clear(){
        ConexionesEntrantes.clear();
        ConexionesSalientes.clear();
    }

    
    
};


#endif /* ConexionesComputadora_hpp */
