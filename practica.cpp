#include <iostream>
#include <list>
#include "treeNode.hpp"
#include "naryTree.hpp"

int main(){


    NaryTree arbol(2);
    bool aux = false;
    arbol.insertElement(arbol.rootNode(),2,4,aux);
    aux = false;
    arbol.insertElement(arbol.rootNode(),4,3,aux);
    aux = false;
    arbol.insertElement(arbol.rootNode(),2,5,aux);
    aux = false;
    arbol.insertElement(arbol.rootNode(),2,9,aux);
    aux = false;
    arbol.insertElement(arbol.rootNode(),4,8,aux);
    aux = false;
    arbol.insertElement(arbol.rootNode(),5,6,aux);
    aux = false;
    arbol.insertElement(arbol.rootNode(),5,16,aux);
    aux = false;
    

    NaryTree arbol2(20);
    arbol2.insertElement(arbol2.rootNode(),20,18,aux);
    aux = false;
    arbol2.insertElement(arbol2.rootNode(),20,19,aux);
    aux = false;
    arbol2.insertElement(arbol2.rootNode(),18,12,aux);
    aux = false;
    
    arbol.insertarSubArbol(arbol.rootNode(),9,arbol2.rootNode(),aux);
    arbol.porNiveles(arbol.rootNode());
    aux = false;
    arbol.eliminarSubArbol(arbol.rootNode(),19,aux);  
    std::cout<<"\n";           
    arbol.porNiveles(arbol.rootNode()); 
    std::cout<<"\n";   
    std::cout<<"\n";   


     aux = false;
    NaryTree<int>treeAux;
    arbol.copiarSubArbol(arbol.rootNode(),20,treeAux,aux);
    treeAux.porNiveles(treeAux.rootNode());

  

    //std::cout << arbol.rootInfo()<<std::endl;
    return 0;   
}