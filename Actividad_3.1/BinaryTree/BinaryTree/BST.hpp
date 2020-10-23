//
//  BST.hpp
//  BinaryTree
//
//  Created by Vicente Cubells on 20/10/20.
//

#ifndef BST_hpp
#define BST_hpp

#include "BinaryTree.hpp"

template <class T>
class BST : public BinaryTree<T>
{
    
public:
    BST() {};
    virtual ~BST() { };
    
    TreeNode<T> * search(const T &) const;
    bool insert(T &);
    bool insert(TreeNode<T> * );
    
    //O(n)
    void visit(const int);
    
    //O(2n)
    void ancestors(const T &) const;
    
    //O(n)
    void ancestors(TreeNode<T> * node) const;
    
    //O(n logn) en el peor caso, O(c) en el mejor caso
    int whatLevelAmI(const T &) const;
    
    //O(n) en el peor caso, O(c) en el mejor caso
    int whatLevelAmI(TreeNode<T> * node) const;
    
    
private:
    /* Ocultar algunos métodos heredados */
    using BinaryTree<T>::insert; // TESTING
};
template <class T>
TreeNode<T> * BST<T>::search(const T & value) const
{
    TreeNode<T> * aux = this->root;
    
    while (aux != nullptr) {
        if (aux->getInfo() == value) {
            return aux;
        }
        else {
            aux = aux->getInfo() > value ? aux->getLeft() : aux->getRight();
        }
    }
    
    return nullptr;
}

template <class T>
bool BST<T>::insert(T & value)
{
    return this->insert(new TreeNode<T>(value));
}

template <class T>
bool BST<T>::insert(TreeNode<T> * node )
{
    /* No se puede insertar un nodo NULL */
    if (node == nullptr) return false;
    
    /* Obtener la info del nodo a insertar */
    T value = node->getInfo();
    
    /* Establecer un apuntador auxiliar */
    TreeNode<T> * aux = this->root;
    
    /* Estalecer una variable para el padre */
    TreeNode<T> * parent = nullptr;
    
    /* Buscar la posición que le corresponde */
    while (aux != nullptr) {
        if (aux->getInfo() == value) {
            /* Liberar la memoria del nodo porque ya existe */
            delete node;
            
            return false;
        }
        else {
            parent = aux;
            aux = aux->getInfo() > value ? aux->getLeft() : aux->getRight();
        }
    }
    
    /* Establecer el parent del nodo a insertar */
    node->setParent(parent);
    
    /* Si el árbol está vacío, se inserta la raiz */
    if (parent == nullptr) {
        this->root = node;
    }
    else {
        /* Si el value a insertar es menor, se inserta a la izquierda */
        if ( parent->getInfo() > value ) {
            parent->setLeft(node);
        }
        /* Si el value a insertar es mayor, se inserta a la derecha */
        else {
            parent->setRight(node);
        }
    }
    
    return true;
}

template <class T>
void BST<T>::visit(const int param)
{
    if (param == 1) { // Postorder
        this->preOrden();
        
    } else if (param == 2) { // Inorder
        this->inOrden();
        
    } else if (param == 3) { // Postorder
        this->postOrden();
    } else if (param == 4) {
        this->level_by_level();
        
    }
    
    
}

template <class T>
void BST<T>::ancestors(const T & value) const {
    this->ancestors(this->search(value));
}

template <class T>
void BST<T>::ancestors(TreeNode<T> * node) const {
    TreeNode<T> * parent = node->getParent();
    
    if (node->getParent() != nullptr) {
        std::cout << *parent << " ";
        ancestors(parent->getInfo());
    }
}

template <class T>
int BST<T>::whatLevelAmI(const T & value) const {
    return this->whatLevelAmI(this->search(value));
}

template <class T>
int BST<T>::whatLevelAmI(TreeNode<T> * node) const {
    int level = 0;
    
    while (node->getParent() != nullptr) {
        ++level;
        node = node->getParent();
    }
    
    return level;
}

#endif /* BST_hpp */
