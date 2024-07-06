#pragma once

template<typename T>
class BinNode{
    private:
        T info;
        BinNode<T>* left;
        BinNode<T>* right;
    public:
//###########################################################################################
    BinNode(){      //Empty Constructor
        left = nullptr;
        right = nullptr;
    }
//###########################################################################################
    BinNode(T newInfo){    //Constructor with info
        info = newInfo;
        left = nullptr;
        right = nullptr;
    }
//###########################################################################################
    void setLeftSon(BinNode<T>* newLeft){   //Setter for the lefth son
        left = newLeft;
    }
//###########################################################################################
    void setRightSon(BinNode<T>* newRight){     //Setter for he rigth son
        right = newRight;
    }
//###########################################################################################
    void setInfo(T newInfo){    //Setter for info
        info = newInfo;
    }
//###########################################################################################
    T getInfo(){        //Getter for Info
        return info;
    }
//###########################################################################################
    BinNode* getRightSon(){        //Getter for the right Son
        return right;
    }
//###########################################################################################
    BinNode* getLeftSon(){         //Getter for the left son
        return left;
    }
//###########################################################################################
    ~BinNode(){     //Destructor
        left = nullptr;
        right = nullptr;
    }


};