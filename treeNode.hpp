#pragma once
#include <list>

template <typename T>
class treeNode
{
private:
    T info;
    treeNode<T> * leftSon;
    treeNode<T> * rightBrother;

public:
//###########################################################################################
    treeNode(/* args */){ //CONSTRUCTOR
        leftSon = nullptr;
        rightBrother = nullptr;
    }
//###########################################################################################
    treeNode(T newInfo){//CONSTRUCTOR with info
        info = newInfo;
        leftSon = nullptr;
        rightBrother = nullptr;
    }
//###########################################################################################
    T getInfo(){
        return info;
    }
//###########################################################################################
    treeNode<T>* getLeftSon(){
        return leftSon;
    }
//###########################################################################################
    treeNode<T>* getRightBrother(){
        return rightBrother;
    }
//###########################################################################################
    void setInfo(T newInfo){    //INFO setter
        info = newInfo;
    }
//###########################################################################################
    void setRightBrother(treeNode<T>* newRightBrother){
        rightBrother = newRightBrother;
    }
//###########################################################################################
    void setLeftSon(treeNode<T>* newLeftSon){
        leftSon = newLeftSon;
    }

//###########################################################################################
    ~treeNode(){//DESTRUCTOR
        leftSon=nullptr;
        rightBrother=nullptr;
    }

};
