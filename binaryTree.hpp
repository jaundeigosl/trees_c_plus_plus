#pragma once
#include "binNode.hpp"
#include <queue>
#include <list>
#include <iostream>

template <typename T>

class BinaryTree{
    private:
        int weight;
        BinNode<T>* root;
    public:
//###########################################################################################
    BinaryTree(){
        weight = 0;
        root = nullptr;
    }
//###########################################################################################
    BinaryTree(T info){
        weight = 1;
        root = new BinNode<T>(info);
    }
//###########################################################################################
    BinaryTree( BinNode<T> *newRoot){
        weight = 1; //debe de recorer el nuevo arbol y averiguar cuantos nodos existen, falta implimentar eso
        root = newRoot;
    }
//###########################################################################################
    void insertElement(T father, T newSon, BinNode<T> *aux , bool &flag){
        if(!flag){
            if(weight>0){
                if(aux != nullptr){
                    if(aux->getInfo()==father){ //verificando si se encontro el padre deseado

                        //viendo cual de los dos hijos esta libre
                        if(aux->getLeftSon()==nullptr){
                            aux->setLeftSon(new BinNode<T>(newSon));
                            flag = true;
                        }else{
                            if(aux->getRightSon()==nullptr){
                                aux->setRightSon(new BinNode<T>(newSon));
                                flag = true;
                            }else{
                                //no hay hijos libres
                                flag = true;
                                std::cout<< "No space in the sons";
                            }
                        }
                    }else{
                        //caso de que el nodo donde se esta parado no sea el padre

                        //recursividad con el hijo izquierdo
                        if(aux->getLeftSon()!=nullptr){
                            insertElement(father, newSon, aux->getLeftSon(),flag);
                        }
                        //recursividad con el hijo derecho
                        if(aux->getRightSon()!=nullptr){
                            insertElement(father,newSon, aux->getRightSon(),flag);
                        }
                    }
                }
                if(flag){
                    weight++;
                }
            }else{
                root = new BinNode(father);
            }
        }
    }
//###########################################################################################
void preOrden(BinNode<T> * inicio){     //recorrido PREORDEN
    if(inicio != nullptr){
        //procesar "raiz"
        std::cout<< inicio->getInfo()<<std::endl;
        BinNode<T> * aux;

        //llamada hijo izquierdo
        aux = inicio->getLeftSon();
        preOrden(aux);

        //llamada hijo derecho
        aux = inicio->getRightSon();
        preOrden(aux);
    }
}
//###########################################################################################
void postOrden(BinNode<T>* inicio){     //recorrido POSTORDEN
    if(inicio != nullptr){
        BinNode<T> * aux;

        //llamada hijo izquierdo
        aux = inicio->getLeftSon();
        postOrden(aux);

        //llamada hijo derecho
        aux = inicio->getRightSon();
        postOrden(aux);

        //procesar "raiz"
        std::cout << inicio->getInfo()<<std::endl;
    }
}

//###########################################################################################
void inOrden(BinNode<T>* inicio){     //recorrido INORDEN
    if(inicio != nullptr){
        BinNode<T> * aux;
        //llamada hijo izquierdo
        aux = inicio->getLeftSon();
        inOrden(aux);

        //procesar "raiz"
        std::cout << inicio->getInfo()<<std::endl;

        //llamada a hijo derecho
        aux = inicio->getRightSon();
        inOrden(aux);
    }
}

//###########################################################################################
void porNiveles(BinNode<T>* inicio){     //recorrido Por NIVELES
    if(inicio != nullptr){
    std::queue<BinNode<T>*> recorrido;
    recorrido.push(inicio);
    BinNode<T> * actual, *aux;

    while(recorrido.size()>0){
        actual = recorrido.front();

        //procesar "raiz"
        std::cout<< actual->getInfo()<<std::endl;

        //añadiendo los hijos a la cola
        aux = actual->getLeftSon();
        if(aux != nullptr){
            recorrido.push(aux);
        }
        aux = actual->getRightSon();
        if(aux != nullptr){
            recorrido.push(aux);
        }
        //eliminando el frente de la cola
        recorrido.pop();
        }
    }
}


//###########################################################################################
void construirPreorden(std::list<T> preordenLista, std::list<T> inordenLista , BinNode<T> *padre){
    
        std::list<T> hijosIzq, hijosDer, preordenHijosIzq, preordenHijosDer;
        BinNode<T> * auxCreador;
        T aux;

        //creando el nodo para el elemento actual
        padre->setInfo(preordenLista.front());

        aux = preordenLista.front();
        preordenLista.pop_front();
        
            //creando la lista de los hijos izquierdos del elemento actual
            while(inordenLista.front()!=aux){

                hijosIzq.push_back(inordenLista.front());
                inordenLista.pop_front();

                preordenHijosIzq.push_back(preordenLista.front());
                preordenLista.pop_front();
            }

            inordenLista.pop_front();

            //Hijos derechos del elemento actual
            preordenHijosDer = preordenLista;
            hijosDer = inordenLista;

            weight = weight + 1;

            if(hijosIzq.size()>=1){
                padre->setLeftSon(new BinNode<char>);
                construirPreorden(preordenHijosIzq, hijosIzq, padre->getLeftSon());
            }
            if(hijosDer.size()>=1){
                padre->setRightSon(new BinNode<char>);
                construirPreorden(preordenHijosDer, hijosDer,padre->getRightSon());
            }
    
}
//###########################################################################################
void construirPostorden(std::list<T> postordenLista, std::list<T> inordenLista , BinNode<T> *padre){
    
        std::list<T> hijosIzq, hijosDer, postordenHijosDer, postordenHijosIzq;
        BinNode<T> * auxCreador;
        T aux;

        //creando el nodo para el elemento actual
        padre->setInfo(postordenLista.back());

        aux = postordenLista.back();
        postordenLista.pop_back();
        
            //creando la lista de los hijos izquierdos del elemento actual
            while(inordenLista.front()!=aux){

                hijosIzq.push_back(inordenLista.front());
                inordenLista.pop_front();

                postordenHijosIzq.push_back(postordenLista.front());
                postordenLista.pop_front();
            }

            inordenLista.pop_front();

            //Hijos derechos del elemento actual
            postordenHijosDer = postordenLista;
            hijosDer = inordenLista;

            weight = weight + 1;

            if(hijosIzq.size()>=1){
                padre->setLeftSon(new BinNode<char>);
                construirPostorden(postordenHijosIzq, hijosIzq, padre->getLeftSon());
            }
            if(hijosDer.size()>=1){
                padre->setRightSon(new BinNode<char>);
                construirPostorden(postordenHijosDer, hijosDer,padre->getRightSon());
            }
    
}
//###########################################################################################

void insertarSubArbol(BinNode<T> *raiz, T padre, BinNode<T> * raizSubArbol, bool &encontrado){
    BinNode<T>*aux;
    if(!encontrado && raiz != nullptr){
        aux = raiz;
        if(aux->getInfo() != padre){
            insertarSubArbol(aux->getLeftSon(),padre,raizSubArbol,encontrado);
            insertarSubArbol(aux->getRightSon(),padre,raizSubArbol,encontrado);
        }else{
            encontrado = true;
            if(aux->getLeftSon()==nullptr){
                aux->setLeftSon(raizSubArbol);
            }else{
                if(aux->getRightSon()==nullptr){
                    aux->setRightSon(raizSubArbol);
                }else{
                    std::cout<<"No hay hijos libres"<<std::endl;
                }
            }
        }
    }
}
//###########################################################################################
void eliminarSubArbol(BinNode<T> *raiz , T elemento, bool &encontrado){ //ELIMINAR SUBARBOL
    if(raiz!=nullptr && !encontrado){
        if(root->getInfo()==elemento){
            encontrado=true;
            eliminarNodoSubArbol(root);
            delete root;
            root = nullptr;
            weight = weight - 1;
        }

        if(raiz->getLeftSon()!=nullptr){
            if(raiz->getLeftSon()->getInfo()==elemento){

                eliminarNodoSubArbol(raiz->getLeftSon());
                delete(raiz->getLeftSon());
                raiz->setLeftSon(nullptr);
                weight = weight - 1;
                encontrado = true;
            }
        }
        if(raiz->getRightSon()!=nullptr){
            if(raiz->getRightSon()->getInfo()==elemento){

                eliminarNodoSubArbol(raiz->getRightSon());
                delete (raiz->getRightSon());
                raiz->setRightSon(nullptr);
                weight = weight - 1;
                encontrado = true;

            }
        }

       eliminarSubArbol(raiz->getLeftSon(), elemento, encontrado);
       eliminarSubArbol(raiz->getRightSon(),elemento,encontrado);
    }

}

void eliminarNodoSubArbol(BinNode<T> *actual){
    BinNode<T> *aux;

    if(actual->getLeftSon()!=nullptr || actual->getRightSon()!=nullptr){
        
        if(actual->getLeftSon()!=nullptr){
            eliminarNodoSubArbol(actual->getLeftSon());
            aux = actual->getLeftSon();
            delete aux;
            actual->setLeftSon(nullptr);
            weight = weight - 1;
        }
    
        if(actual->getRightSon()!=nullptr){
            eliminarNodoSubArbol(actual->getRightSon());
            aux = actual->getRightSon();
            weight = weight - 1;
            delete aux;
            actual->setRightSon(nullptr);
        }

    }
}

//###########################################################################################
    T rootInfo(){   //INFO DE RAIZ
        return root->getInfo();
    }
//###########################################################################################
    BinNode<T>* rootNode(){     //DIRECCION DEL NODO RAIZ
        return root;
    }
//###########################################################################################
    void setRoot(T elemento){
        BinNode<T> * aux;
        aux = new BinNode(elemento);
        root = aux;
    }
//###########################################################################################
    ~BinaryTree(){//Destructor
        weight=0;
        bool aux = false;
        eliminarSubArbol(root, root->getInfo(),aux);
    }


};