#pragma once
#include "binNode.hpp"
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
        }
    }

//###########################################################################################
    T rootInfo(){
        return root->getInfo();
    }
//###########################################################################################
    BinNode<T>* rootNode(){
        return root;
    }

//###########################################################################################
    ~BinaryTree(){
        weight=0;
        free(root);
    }


};