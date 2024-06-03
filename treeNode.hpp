#pragma once
#include <list>

template <typename T>
class treeNode
{
private:
    T info;
    list<treeNode<T> sons;
public:
    tree_node(/* args */);
    ~tree_node();
    tree_node(T info);
    void setInfo(T newInfo);

//###########################################################################################
    treeNode(/* args */){ //CONSTRUCTOR
        weigth = 0;
    }
//###########################################################################################
    treeNode(T info){//CONSTRUCTOR with info
        info = info;
        weight = 1;
    }
//###########################################################################################
    void setInfo(T newInfo){    //INFO setter
        info = newInfo;
    }
//###########################################################################################
    void setLeftSon(treeNode<T>* newLeft){
        left = newLeft;
    }
//###########################################################################################
    void setLeftSon(treeNode<T>* newright){
        left = newRigth;
    }

//###########################################################################################
    treeNode::~treeNode(){//DESTRUCTOR
    }

};
