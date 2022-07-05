#pragma once
#include"PlaneStruct.h"

struct DynamicArr
{
private:
    Plane* PlanesArray;
    int size = 0;
    int obj_counter = 0;

public:
    void pushBack(Plane newPlane);
    Plane popBack();
    Plane get(int number);
    int getSize() { return size; };
    void changeSize(float value);
    void print();
    void pushFront(Plane newPlane);
    Plane popFront();
    ~DynamicArr(){delete[] PlanesArray;}
};
