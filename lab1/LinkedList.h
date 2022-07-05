#pragma once
#include"PlaneStruct.h"

struct Node
{
    Plane plane;
    Node* nextNode;
    Node(Plane newPlane, Node* nextNode_)
    {
        plane = newPlane;
        nextNode = nextNode_;
    }
};

struct LinkedList
{
private:

    Node* headptr = nullptr;
    int size;

public:

    Node* getLastNode();
    void pushFront(Plane newPlane);
    void pushBack(Plane newPlane);
    Plane get(int num);
    Plane popFront();
    Plane popBack();
    int getSize() {return size;}
    void print();
    ~LinkedList(){delete headptr;}
};