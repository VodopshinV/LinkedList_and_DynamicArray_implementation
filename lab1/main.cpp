#include <iostream>
#include<string>
#include <ctime>
 
#include"PlaneStruct.h"
#include "DynamicArray.h"
#include "LinkedList.h"

using namespace std;

void ArrayTest();
void ListTest();


int main()
{
    ArrayTest();
    ListTest();
    return 0;
}


void ArrayTest()
{
    srand(time(NULL));

    DynamicArr array;
    Plane obj = {"Qatar Airways", 215000 , 946};

    clock_t test_start = clock();

    cout << "Dynamic Array Test:" << endl;

    clock_t start = clock();
    for (int i = 0; i < 50000; i++)
    {
        array.pushBack(obj);
    }
    clock_t end = clock();
    float time = (float(end - start)) / CLOCKS_PER_SEC;

    cout << "pushBack() time: \t" << time << " seconds" << endl;

    start = clock();
    for (int i = 0; i < 10000; i++)
    {
        array.pushFront(obj);
    }
    end = clock();
    time = (float(end - start)) / CLOCKS_PER_SEC;

    cout << "pushFront() time: \t" << time << " seconds" << endl;
    
    start = clock();
    for (int i = 0; i < 20000; i++)
    {
        array.get(rand() % 60000);
    }
    end = clock();
    time = (float(end - start)) / CLOCKS_PER_SEC;

    cout << "get() time: \t\t" << time << " seconds" << endl;

    start = clock();
    for (int i = 0; i < 5000; i++)
    {
        array.popFront();
    }   
    end = clock();
    time = (float(end - start)) / CLOCKS_PER_SEC;

    cout << "popFront() time: \t" << time << " seconds" << endl;

    start = clock();
    for (int i = 0; i < 5000; i++)
    {
        array.popBack();
    }   
    end = clock();
    time = (float(end - start)) / CLOCKS_PER_SEC;

    cout << "popBack() time: \t" << time << " seconds" << endl;

    clock_t test_end = clock();
    time = (float(test_end - test_start)) / CLOCKS_PER_SEC;
    cout << "-------------------------------------" << endl;
    cout << "Total time: \t\t" << time << " seconds" << endl<<endl;
}

void ListTest()
{
    srand(time(NULL));

    LinkedList list;
    Plane obj = { "Qatar Airways", 215000 , 946 };

    clock_t test_start = clock();

    cout << "Linked List Test:" << endl;
  
    clock_t start = clock();
    for (int i = 0; i < 50000; i++)
    {
        list.pushBack(obj);
    }
    clock_t end = clock();
    float time = (float(end - start)) / CLOCKS_PER_SEC;

    cout << "pushBack() time: \t" << time << " seconds" << endl;

    start = clock();
    for (int i = 0; i < 10000; i++)
    {
        list.pushFront(obj);
    }
    end = clock();
    time = (float(end - start)) / CLOCKS_PER_SEC;
    cout << "pushFront() time: \t" << time << " seconds" << endl;

    start = clock();
    for (int i = 0; i < 20000; i++)
    {
        list.get(rand() % 60000 + 1);
    }   
    end = clock();
    time = (float(end - start)) / CLOCKS_PER_SEC;

    cout << "get() time: \t\t" << time << " seconds" << endl;

    start = clock();
    for (int i = 0; i < 5000; i++)
    {
        list.popFront();
    }
    end = clock();
    time = (float(end - start)) / CLOCKS_PER_SEC;

    cout << "popFront() time: \t" << time << " seconds" << endl;

    start = clock();
    for (int i = 0; i < 5000; i++)
    {
        list.popBack();
    }   
    end = clock();
    time = (float(end - start)) / CLOCKS_PER_SEC;

    cout << "popBack() time: \t" << time << " seconds" << endl;

    clock_t test_end = clock();
    time = (float(test_end - test_start)) / CLOCKS_PER_SEC;

    cout << "-------------------------------------" << endl;
    cout << "Total time: \t\t" << time << " seconds" << endl<<endl;
}
