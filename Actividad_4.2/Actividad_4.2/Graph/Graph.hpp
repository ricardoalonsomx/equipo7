//
//  Graph.hpp
//  Graph
//
//  Created by Vicente Cubells on 10/11/20.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include "Vertex.hpp"

template <class V, class E>
class Graph {
    
    
    
public:
    std::vector < Vertex<V, E> * > nodes;
    Graph() {}
    ~Graph();
    
    void addVertex(V & );
    void addVertex(Vertex<V,E> * );
    void addEdge(Vertex<V,E> *, Vertex<V,E> *, const E & );
    void removeEdge(Vertex<V,E> *, Vertex<V,E> *, const E & );
    std::string getMasDestinos();
    Vertex<V, E> * findVertex(std::string);
    int findSiteConections(std::string );
    
    template <class Vn, class En>
    friend std::ostream & operator <<(std::ostream &, const Graph<Vn,En> &);
};

template <class V, class E>
Graph<V,E>::~Graph()
{
    for (auto v: nodes) {
        delete v;
    }
    
    nodes.clear();
}

template <class V, class E>
void Graph<V,E>::addVertex(V & value )
{
    auto vertex = new Vertex<V, E>(value);
    
    nodes.push_back(vertex);
}

template <class V, class E>
void Graph<V,E>::addVertex(Vertex<V,E> * vertex )
{
    nodes.push_back(vertex);
}

template <class V, class E>
void Graph<V,E>::addEdge(Vertex<V,E> * source, Vertex<V,E> * target, const E & value)
{
    /* Buscar vertex origen */
    auto node = find(nodes.begin(), nodes.end(), source);
    
    /* Crear un edge y adicionarlo al vertex */
    Edge<V, E> * edge = new Edge<V,E>(value, target);
    
    (*node)->addEdge(edge);
    (*node)->addConexion();
}

template <class V, class E>
void Graph<V,E>::removeEdge(Vertex<V,E> * source, Vertex<V,E> * target, const E & value )
{
    /* Buscar vertex origen */
    auto node = find(nodes.begin(), nodes.end(), source);
    
    Vertex<V,E> * vertex = (*node);
    
    auto * edges = vertex->getEdges();
    
    Edge<V,E> * to_remove = nullptr;
    
    for (auto e : *edges) {
        if (e->getInfo() == value && e->getTarget() == target) {
            to_remove = e;
            break;
        }
    }
    
    if (to_remove) {
        vertex->removeEdge(to_remove);
    }
    target->removeConexion();
    
}

template <class V, class E>
std::string Graph<V,E>::getMasDestinos()
{
    int temp = 0;
    std::string sitio = "";
    for (auto v :  nodes) {
        if(v->get_conexiones_salida()>temp){
            temp=0;
            sitio = v->getInfo();
        }
    }
    
    return sitio;
}

template <class V, class E>
Vertex<V, E> * Graph<V,E>::findVertex(std::string sitio)
{
    
    for (auto *v :  nodes) {
        if(v->getInfo() == sitio)
            return v;
    }
    
    return nullptr;
}

template <class V, class E>
int Graph<V,E>::findSiteConections(std::string sitio)
{
    
    for (auto v :  nodes) {
        if(v->getInfo() == sitio)
            return v->get_conexiones_entrada();
    }
    
    return -1;
}

template <class V, class E>
std::ostream & operator <<(std::ostream & os, const Graph<V,E> & graph)
{
    os << "     --------- Graph ---------" << std::endl;
    
    for (auto v :  graph.nodes) {
        os << *v;
    }
    
    return os;
}

#endif /* Graph_hpp */
