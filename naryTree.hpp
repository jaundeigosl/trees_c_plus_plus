#include "treeNode.hpp"
#include <iostream>
#include <queue>

template<typename T>
class NaryTree
{
    private:
        int weight;
        treeNode<T> * root;
    public:
//###########################################################################################
    NaryTree(){     //CONSTRUCTOR vacio
        weight=0;   
        root = nullptr;
    }
//###########################################################################################
    NaryTree(T info){       //CONSTRUCTOR con info
        root = new treeNode(info);
        weight=1;
    }
//###########################################################################################
void insertElement(treeNode<T>*raiz, T padre, T hijo, bool &encontrado){        //INSERTAR ELEMENTO
    treeNode<T> * aux1, *aux2;

    if(raiz != nullptr && !encontrado){
        if(raiz->getInfo()==padre){

            encontrado = true;
            weight = weight + 1;
            aux1 = raiz->getLeftSon();
            aux2 = new treeNode(hijo);

            if(aux1!=nullptr){//si el hijo izquierdo esta ocupado

                //recorremos los hermanos hasta llegar al ultimo
                while(aux1->getRightBrother()!=nullptr){
                    aux1 = aux1->getRightBrother();
                }

                //añadimos el nuevo hijo como ultimo
                aux1->setRightBrother(aux2);

            }else{//el hijo izquierdo es nulo
                
                //Entonces se añade el hijo como el hijo izquierdo
                raiz->setLeftSon(aux2);
            }
        }else{
            aux1 = raiz->getLeftSon();
            while(aux1!=nullptr){
                insertElement(aux1,padre,hijo,encontrado);
                aux1 = aux1->getRightBrother();
            }
        }
    }
    if(root == nullptr){
        root = new treeNode (padre);
        root->setLeftSon(new treeNode(hijo));
        encontrado = true;
    }

}
//###########################################################################################
void preOrden(treeNode<T>*raiz){        //RECORRIDO PREORDEN
    treeNode<T>*aux;
    if(raiz!=nullptr){
        std::cout<<raiz->getInfo()<<std::endl;
        aux = raiz->getLeftSon();
        while(aux!=nullptr){
            preOrden(aux);
            aux = aux->getRightBrother();
        }
    }
}
//###########################################################################################
void postOrden(treeNode<T>*raiz){       //RECORRIDO POSTORDEN
    treeNode<T>*aux;
    if(raiz!=nullptr){

        aux = raiz->getLeftSon();

        while(aux!=nullptr){
            postOrden(aux);
            aux = aux->getRightBrother();
        }

        std::cout<<raiz->getInfo()<<std::endl;
    }
}
//###########################################################################################
void porNiveles(treeNode<T>*raiz){      //RECORRIDO POR NIVELES
    treeNode<T>*actual,*aux;
    std::queue<treeNode<T>*> recorrido;

    if(raiz!=nullptr){
        recorrido.push(raiz);

        while(recorrido.size()>=1){
            actual = recorrido.front();

            std::cout << actual->getInfo()<<std::endl;

            aux = actual->getLeftSon();
            while(aux!=nullptr){
                recorrido.push(aux);
                aux = aux->getRightBrother();
            }

            recorrido.pop();

        }
    }
}
//###########################################################################################
void insertarSubArbol(treeNode<T>*raiz, T padre, treeNode<T>*hijo, bool &encontrado){   //INSERTAR SUBARBOL
    treeNode<T>*aux1,*aux2;

    if(raiz != nullptr){

        if(raiz->getInfo()==padre){

            encontrado = true;
            aux1 = raiz->getLeftSon();

            if(aux1!=nullptr){

                while(aux1->getRightBrother()!=nullptr){
                    aux1 = aux1->getRightBrother();
                }

                aux1->setRightBrother(hijo);
                
            }else{
                raiz->setLeftSon(hijo);
            }
        }else{
            aux1= raiz->getLeftSon();
            while(aux1!=nullptr){
                insertarSubArbol(aux1,padre,hijo,encontrado);
                aux1 = aux1->getRightBrother();
            }
        }
    }
}
//###########################################################################################
void eliminarSubArbol(treeNode<T>*raiz, T padre, bool &encontrado){     //ELIMINAR SUBARBOL
    treeNode<T>*aux1,*aux2;

    if(raiz != nullptr && !encontrado){

        //caso donde el arbol se va a eliminar
        if(root->getInfo()==padre){
            eliminarNodoSubArbol(root);
            root = nullptr;
        }else{

            //obteniendo hijo Izq
            aux1 = raiz->getLeftSon();

            //si el hijo izq es el subArbol a eliminar
            if(aux1!=nullptr){
                if(aux1->getInfo()==padre){

                    
                    //eliminando el actual y reacomodando los hermanos
                    encontrado = true;
                    aux2 = aux1->getRightBrother();
                    aux1->setRightBrother(nullptr);
                    eliminarNodoSubArbol(aux1);
                    raiz->setLeftSon(aux2);
                    
                }else{

                    //buscando entre los hermanos del hijo izq
                    aux2 = aux1->getRightBrother();

                    while(aux2!=nullptr && !encontrado){

                        if(aux2->getInfo()==padre){

                            
                            //eliminando el actual y reacomodando los hermanos
                            encontrado = true;
                            aux1->setRightBrother(aux2->getRightBrother());
                            aux2->setRightBrother(nullptr);
                            eliminarNodoSubArbol(aux2);

                            
                        }else{

                            //obteniendo el siguiente hermano
                            aux1 = aux2;
                            aux2 = aux2->getRightBrother();
                        }
                    }
                    //llamada recursiva en caso de no haberlo encontrado
                    aux1 = raiz->getLeftSon();
                    while(aux1!=nullptr && !encontrado){
                        eliminarSubArbol(aux1,padre,encontrado);
                        aux1 = aux1->getRightBrother();
                    } 

                }

            }
        }
      
    }

}

void eliminarNodoSubArbol(treeNode<T>*raiz){
    treeNode<T> *actual, *aux1,*aux2;
    actual = raiz->getLeftSon();

    //recorriendo todos los hijos izq
    if(raiz->getLeftSon()!=nullptr){
        eliminarNodoSubArbol(actual);
    }else{

        aux1 = raiz->getRightBrother();

        //cuando ya no haya hijos izq se recorre los hermanos derecho del actual
        while(aux1!=nullptr){
            eliminarNodoSubArbol(aux1);
            aux1 = aux1->getRightBrother();
        }
    }

    //cuando se hayan recorrido todos los hijos y hermanos se elimina el actual
    delete (raiz);
}

//###########################################################################################
void copiarSubArbol(treeNode<T>*raiz, T padre, NaryTree<T>&arbolCopia, bool &encontrado){
    treeNode<T>*aux;

    if(raiz!=nullptr && !encontrado){
        if(raiz->getInfo()==padre){
            encontrado = true;
            arbolCopia.setRootInfo(padre);
            copiarNodoSubArbol(raiz,arbolCopia);
        }else{
            aux=raiz->getLeftSon();
            while(aux!=nullptr){
                copiarSubArbol(aux,padre,arbolCopia,encontrado);
                aux = aux->getRightBrother();
            }
        }
        
    }

}


void copiarNodoSubArbol(treeNode<T>*raiz,NaryTree<T>&arbolCopia){
    treeNode<T> * aux;
    bool auxBool = false;;
    if(raiz!=nullptr){
        aux = raiz->getLeftSon();
        while(aux!=nullptr){
            arbolCopia.insertElement(arbolCopia.rootNode(),raiz->getInfo(),aux->getInfo(),auxBool);
            auxBool = false;
            copiarNodoSubArbol(aux,arbolCopia);
            aux = aux->getRightBrother();
        }
    }
}


//###########################################################################################
    treeNode<T>* rootNode(){
        return root;
    }
//###########################################################################################
    T rootInfo(){
        return root->getInfo();
    }
//###########################################################################################
    void setRootInfo(T newRoot){
        if(root == nullptr){
            root = new treeNode(newRoot);
        }else{
            root->setInfo(newRoot);
        }
    }

//###########################################################################################
    ~NaryTree(){
        bool aux = false;
        eliminarSubArbol(root,root->getInfo(),aux);
        root = nullptr;
    }


};
