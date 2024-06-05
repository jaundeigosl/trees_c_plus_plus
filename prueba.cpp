#include <iostream>
#include "binaryTree.hpp"
#include "binNode.hpp"

int main(){

    BinaryTree arbol(5);
    std::cout << arbol.rootInfo()<<std::endl;
    bool band = false;
    arbol.insertElement(5,2,arbol.rootNode(),band);
    band = false;
    arbol.insertElement(2,-4,arbol.rootNode(),band);
    BinNode<int>* aux = arbol.rootNode();
    aux = aux->getLeftSon();
    std::cout<<aux->getInfo()<<std::endl;
    aux = aux->getLeftSon();
    std::cout<<aux->getInfo()<<std::endl;
    band = false;
    arbol.insertElement(5,3,arbol.rootNode(),band);
    aux = arbol.rootNode();
    aux = aux->getRightSon();
    std::cout<<aux->getInfo()<<std::endl;
    band = false;
    arbol.insertElement(5,3,arbol.rootNode(),band);


    return 0;
}