#include"LinkedList.h"
#include<iostream>


Node* LinkedList::getLastNode()
{
    if (headptr == nullptr)
    {
        return nullptr;
    }    
    else
    {
        Node* node = headptr;
        while (node->nextNode)
        {
            node = node->nextNode;
        }     
        return node;
    }
}

void LinkedList::pushFront(Plane newPlane)
{
    Node* newNode = new Node(newPlane, headptr);
    headptr = newNode;
    size++;
}

void LinkedList::pushBack(Plane newPlane)
{
    if (!headptr)
    {
        headptr = new Node(newPlane, nullptr);
        size++;
    }
    else
    {
        Node* lastNode = getLastNode();
        if (!lastNode)
        {
            std::cout << "pushBack ERROR!!!" << std::endl;
            return;
        }
        Node* newNode = new Node(newPlane, nullptr);
        lastNode->nextNode = newNode;
        size++;
    }
}

Plane LinkedList::popFront()
{
    if (headptr)
    {
        Plane updatedList = headptr->plane;
        Node* node = headptr->nextNode;

        delete headptr;
        headptr = node;

        size--;
        return updatedList;
    }
    else
    {
        return Plane{"ERROR", -1 , -1};
    }  
}

Plane LinkedList::popBack()
{
    if (!headptr)
    {
        return Plane{ "ERROR", -1 , -1 };
    }  
    else if (!headptr->nextNode)
    {
        Plane updatedList = headptr->plane;
        delete headptr;
        headptr = nullptr;

        size--;
        return updatedList;
    }
    else
    {
        Node* node = headptr;

        while (node->nextNode->nextNode)
        {
            node = node->nextNode;
        }
            
        Plane updatedList = node->nextNode->plane;

        delete node->nextNode;
        node->nextNode = nullptr;

        size--;
        return updatedList;
    }
}

Plane LinkedList::get(int num)
{
    if (num > size)
        return Plane{ "ERROR", -1 , -1 };
    else
    {
        int obj_counter = 0;
        Node* node = headptr;

        while (obj_counter < num - 1)
        {
            node = node->nextNode;
            obj_counter++;
        }

        return node->plane;
    }
}

void LinkedList::print()
{
    if (!headptr)
    {
        std::cout << "ERROR! List is empty!" << std::endl;
        return;
    }

    Node* node = headptr;

    std::cout << "LinkedList data:" << std::endl;
    while (node)
    {
        std::cout << "Plane airline: " << node->plane.airline << std::endl;
        std::cout << "Weight: " << node->plane.weight << std::endl;
        std::cout << "Max_speed: " << node->plane.max_speed << std::endl;

        node = node->nextNode;
    }
}


