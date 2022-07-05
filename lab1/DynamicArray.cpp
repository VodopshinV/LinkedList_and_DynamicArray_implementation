#include"DynamicArray.h"
#include<iostream>

void DynamicArr::pushBack(Plane newPlane)
{
    if (!size)
    {
        PlanesArray = new Plane[++obj_counter];
    }
    else if (size == obj_counter)
    {
       changeSize(2);
    }

    PlanesArray[size++] = newPlane;
}

Plane DynamicArr::popBack()
{
    if (!size)
    {
        std::cout << "ERROR!!! Array is empty!" << std::endl;
        return Plane{ "ERROR", -1, -1 };
    }
    
    if (size < 0.5 * obj_counter)
    {
        changeSize(0.5);
    }

    return PlanesArray[--size];
}

Plane DynamicArr::get(int number)
{
    if (number > size)
    {
        std::cout << "Error!!! Number is out of range!" << std::endl;
        return Plane{ "ERROR", -1 , -1 };
    }

    return PlanesArray[number - 1];
}

void DynamicArr::print()
{
    if (!size)
    {
        std::cout << "ERROR! Array is empty!" << std::endl;
        return;
    }
    std::cout << "DynamicArray data:" << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << "Plane airline: " << PlanesArray[i].airline << std::endl;
        std::cout << "Weight: " << PlanesArray[i].weight << std::endl;
        std::cout << "Max_speed: " << PlanesArray[i].max_speed << std::endl;
    }
}

void DynamicArr::changeSize(float value)
{
    obj_counter *= value;

    Plane* updatedArray = new Plane[obj_counter];
    memcpy(updatedArray, PlanesArray, sizeof(Plane) * size);

    delete[] PlanesArray;
    PlanesArray = updatedArray;
}

void DynamicArr::pushFront(Plane newPlane)
{
    if (!size)
    {
        PlanesArray = new Plane[++obj_counter];
        PlanesArray[size++] = newPlane;
        return;
    }

    if (size == obj_counter)
    {
        changeSize(2);
    }

    memmove(PlanesArray + 1, PlanesArray, sizeof(Plane) * size);
    PlanesArray[0] = newPlane;
    size++;
}

Plane DynamicArr::popFront()
{
    if (!size)
    {
        std::cout << "ERROR!!! Array is empty!" << std::endl;
        return Plane{ "ERROR", -1 , -1 };
    }

    if (size < 0.5 * obj_counter)
    {
        changeSize(0.5);
    } 

    Plane updatedArray = PlanesArray[0];
    memmove(PlanesArray, PlanesArray + 1, sizeof(Plane) * size);
    size--;

    return updatedArray;
}






