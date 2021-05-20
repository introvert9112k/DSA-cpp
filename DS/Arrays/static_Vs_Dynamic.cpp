// in this we will look at the static and dynamic array declaration and how can we acess the elements
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main()

{
    //  ------------static array-----------
    // static array is creatd in the stack
    // the size of the static array  cannot be changed in circumstances
    int static_array[10];
    // declaration of array
    for (int i = 0; i < 10; i++)
        static_array[i] = i;
    // acessing the static array elements
    cout << "the elements of the static array are : " << endl;
    for (auto x : static_array)
        cout << x << endl;

    // ---------dynamic array------------
    // in c++ dynamic memory is created using the new keyword
    // by using the new keyword the array is creatd in the heap
    // we cannot directly acess the heap memory we can acess them using the pointer only
    // so let us first declare a pointer /
    int *p;
    p = new int[10];
    // so now we created a array in heap and the pointer p is created in the stack,the pointer in the stack points to the heap array
    for (int i = 0; i < 10; i++) //intialising the array with elements
        p[i] = i;

    //  Acessing the heap array elements
    // in this case the pointer acts as the array name,so we can acess the elements as we acess elements of the static array
    cout << "the elements of the heap array are : " << endl;
    for (int i = 0; i < 10; i++)
        cout << p[i] << endl;

    // -------------Increasing the array size ----------------

    // In case of static array in any case we cannot increase the array size
    // but in the case of dynamic array we can create a another array in heap with our required size and  copy all the elements of before array into this new array and making the pointer to point to this new array we can increase the size
    // let us create a intial array of size 10 and increase it size by 20

    int *p1, *q1;
    p1 = new int[10]; //declaring the array
    for (int i = 0; i < 10; i++)
        p1[i] = i; //intializing the array elements

    // let us create a another array and copy this elements into the array
    q1 = new int[20];
    for (int i = 0; i < 10; i++)
        q1[i] = p1[i]; //copying the p1 array elements into q1 array

    // now as we do not need the p1 array any more let us delete the memory allocated to it
    // if we not do it there will be memory leak

    delete[] p1;

    // now let us point the p1 to the newly created array
    p1 = q1;   //making pointer p1 pointing to the newly created array
    q1 = NULL; //making q1 to null

    // let us acess the elemets in the new array
    // let us intialize the remaining elements in the newly created array
    for (int i = 10; i < 20; i++)
        p1[i] = i;
    cout << "the elements of the newly created array after increasing size is : " << endl;

    for (int i = 0; i < 20; i++)
        cout << p1[i] << endl;

    return 0;
} 