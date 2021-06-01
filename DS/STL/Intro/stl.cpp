// in  this we will look at the STL class. stl stands for the standard template library in this there are pre defined  data structures,which can be used with ease. this helps a lot in competittive programming
// STL consists of
// 1.containers
// 2.iterators
// 3.algorthims

// container class consists of vectors,list ,forward list,stack,queue,dequeue,set,priority queue,map etc
// algorthims class cossists of common searching algorthims and sorting algorthims and many more
// itertaors are used to iterater through these data structures,for loop cannnot be used to itearate through these structures
// lets look at the vecotrs in this file
// vectors is nothing but the array,but vectors are dynamically typed that mean it can change it size automatically
// this is included in the vector header file
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()

{
    //  syntax for defining the vector
    vector<int> v = {1, 2, 3, 4, 5, 6};
    // int is the data type of the data in the vector,v is the object of the class vector
    // there are some methods defined in vector class
    //    here we defined a vector of which has the elements 1,2,3,4,5,6
    // let us traverse through the vector
    // we can traverse in two ways using for each loop and the iterator
    // in case of for each loop we can't change the values but in case of iterator we can change the values of vector
    // let us traverse using for each loop
    cout << "traversing through the for each loop" << endl;
    for (auto x : v)
        cout << x << endl;

    // now let us traverse using the iterator
    cout << "traverse through the iterator " << endl;
    vector<int>::iterator itr;
    for (itr = v.begin(); itr < v.end(); itr++)
    {
        cout << *itr << endl;
    }
    // iterator is nothing but like the pointer it points to the particular address
    // syntax is also similar like declaring the pointer
    // data type of the iterator,as the iterator is the class we should define the object
    // vector<int> :: iterator itr  ;
    // here vector<int> is the data type and iterator is the class and itr is the object
    // begin function return the first index and end will return the last index
    // as i said iterator is like pointer in order to get the value at that adress we should dereference it using *

    // let us change the values of vector using the iterator
    cout << "the data in the vector after incrementing the each element by 2 are : " << endl;
    vector<int>::iterator itr1;
    for (itr1 = v.begin(); itr1 < v.end(); itr1++)
    {
        // now let us increment each value in vector by 2 and print them
        *itr1 = *itr1 + 2;
        cout << *itr1 << endl;
    }
    //    let us add and delete the elements into the vector v
    //  push_back is used to add element at the end of the vector
    //  pop_back is used to remove the last element of the vector

    cout << "adding the number 56 to the vector v" << endl;
    v.push_back(56);
    cout << "the vector elements after adding the 56 is : " << endl;
    for (auto x : v)
        cout << x << endl;
    // let us delete the two elements from the vector
    cout << "deleting the last two elements from the vector " << endl;
    cout << "the elements of vector after deleting the two vectors is : " << endl;
    v.pop_back();
    v.pop_back();
    for (auto x : v)
        cout << x << endl;

    //   In the before vector we intialized it first,let us take the elements from the user for vector
    cout << "taking the elements of the vector from the user : " << endl;
    int num;
    cout << "enter the size of the vector : " << endl;
    cin >> num;
    vector<int> sai;
    for (int i = 0; i < num; i++)
    {
        int value;
        cin >> value;
        sai.push_back(value);
    }
    cout << "traversing the elements in the vector" << endl;
    vector<int>::iterator sri;
    for (sri = sai.begin(); sri < sai.end(); sri++)
    {
        cout << *sri << endl;
    }

    // declaring list ,forward list,set,stack,queue etc
    // the remaining data strucutures are defined as like the vectors are defined
    // in place of vector write the other dat structure name that's it ,the work is done,we succesfully created our desired data structure
    // if we want to use the list we should include the list header file
    // list is nothing but the double linkedlist
    // if we want to use the single linked list we should include the forward_list header file
    // forward_list is the single linked list
    // similarly for the queue and stack too. we should include the stack and queue header files

    // Map data structure is similar to the dictionary in python
    // set data strucuture is also in c++ it is similar to set in python

    return 0;
} 