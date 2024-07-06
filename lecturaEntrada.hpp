#include <iostream>
#include "binaryTree.hpp"
#include "binNode.hpp"
#include <string>
#include <list>
#include <algorithm>

//leyendo los elementos y llenando la lista
void leerLista(std::list<char> &lista){
    char aux;
    std::cin.get(aux);
    while(aux !='\n'&& !std::cin.eof()){
        if(aux!=' '){
            lista.push_back(aux);
        }
        std::cin.get(aux);
    }
}

int main(){
    //prueba de lectura de entrada arbol binario
    int n;
    char aux;
    std::list<char> inorden,preorden,postorden;
    std::string tipo, tipoPreorden, tipoPostorden, tipoInorden;
    tipoPreorden = "PREORDEN";
    tipoPostorden = "POSTORDEN";
    tipoInorden = "INORDEN";
    //leyendo los n casos
    std::cin>>n;

    //leyendo el primer orden de los nodos
    for(int i = 0; i < n; i++){//Para N casos
        for(int j = 0; j < 2; j++){
            std::cin>>tipo;
            if(tipo == tipoPreorden){
                leerLista(preorden);
            }
            if(tipo == tipoPostorden){
                leerLista(postorden);
            }

            if(tipo == tipoInorden){
                leerLista(inorden);
            }

        }

    }
    /*
    std::list<char>::iterator it = preorden.begin();
    std::cout<<"preorden"<<std::endl;
    while(it != preorden.end()){
        std::cout<<(*it)<<std::endl;
        it++;
    }

    it = inorden.begin();
    std::cout <<"inorden"<<std::endl;
    while(it != inorden.end()){
        std::cout<<(*it)<<std::endl;
        it++;
    }
    
     it = postorden.begin();
    std::cout <<"postorden"<<std::endl;
    while(it != postorden.end()){
        std::cout<<(*it)<<std::endl;
        it++;
    }
    */

    //std::cout<<"\n";
    //Creando el arbol con la entrada

    BinaryTree<char> arbol(' ');  

    arbol.construirPostorden(postorden,inorden,arbol.rootNode());  

    
    return 0;   
}    