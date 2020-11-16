//
//  main.cpp
//  Actividad_4.1
//
//  Created by Arturo Sosa on 13/11/20.
//


#include <iostream>
#include "Graph/Graph.hpp"
#include "Stack/Stack.hpp"

void loadGraph2(int v, int e, Graph<int, int> & graph)
{
    /* Implementar */
}

void loadGraph(int v, int e, std::vector < std::vector<int> > & graph)
{
    /* Implementar */
}

void DFS(std::vector < std::vector<int> > & graph, int u)
{
    /* Implementar */
}

void BFS(Graph<int, int> & graph, int u)
{
    Stack<bool> * visitados = new Stack<bool>();
    Stack<int> * cola = new Stack<int>();
    Stack<std::string> * padre = new Stack<std::string>();
    
    cola -> push(u);
    visitados -> push(true);
    padre -> push(nullptr);
    while(! (cola->empty()) ){
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    /* Definir número de vértices y aristas */
    const int vertices = 10;
    const int aristas = 15;
    
    /* Declaración del grafo como matriz de adyacencia */
    std::vector < std::vector<int> > matriz_adyacencia;

    /* Generar el grafo como matriz de adyacencia */
    loadGraph(vertices, aristas, matriz_adyacencia);
    
    /* Recorrido con DFS */
    std::cout << "------ Matriz de adyacencia con DFS ------" << std::endl;
    int nodo_u = 1;
    DFS(matriz_adyacencia, nodo_u);
    
    /* Declaración del grafo como multilista */
    Graph<int, int> * multilista = new Graph<int, int>();

    /* Generar el grafo como multilista */
    loadGraph2(vertices, aristas, multilista);
    
    /* Recorrido con BFS */
    std::cout << "------ Multilista con BFS ------" << std::endl;
    nodo_u = 1;
    BFS(multilista, nodo_u);
    
    delete multilista;
    
    return 0;
}
