// in this we will look into the methods that can be used on vector
// 1.push_back
// 2.pop_back
// 3.insert
// 4.erase
// 5.front
// 6.back
// 7.begin,rbegin
// 8.end ,rend
// 9.empty,clear

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()

{
    std::vector<int> v;
    //  declaring the empty vector

    // -------------push_back---------------

    // in the size and capacity cpp file we clearly discussed how the push back effects on the memory allocation
    for (int i = 0; i < 10; i++)
    {
        /* code */ v.push_back(i);
    }
    // push_back will push the element at the end of the vector
    std::cout << "the elements of the vector are : " << std::endl;
    for (auto x : v)
        std::cout << x << std::endl;

    // -------------pop_back----------

    // let us check how the pop_back will effect the memory allocation
    v.pop_back(); // the return type of pop back is void
    // let us check the size and capaccity of the vector
    std::cout << "the size : " << v.size() << " "
              << "the capacity is : " << v.capacity() << std::endl;
    v.pop_back();
    std::cout << "the size : " << v.size() << " "
              << "the capacity is : " << v.capacity() << std::endl;
    v.pop_back();
    std::cout << "the size : " << v.size() << " "
              << "the capacity is : " << v.capacity() << std::endl;

    // we can see that the even though there is no element in the location the memory is stil under the
    // vector ,so pop_back will not delete the memory allocation of the element that it deleted

    //    ----------insert--------------

    // insert method will insert the specified value at the specified location
    // it takes two arguments,iterator of the positon where we want to insert and the value that we want to insert
    // let us inset the value 9999 in the 3rd position
    v.insert(v.begin() + 2, 999);
    // v.begin() points to zeroth element and v.begin()+1 points to the first element and v.begin()+2 point to second element
    std::cout << "the elements of the vector after popping three elements and inserting 999 at 3 position is: " << std::endl;
    for (auto x : v)
        std::cout << x << std::endl;

    //    ----Memory Allocation------------
    //  in the insert method the new array is created and the elements that are before the insert position is copied into new array and at the insert position the specified elememt is copied and the reaming elements after the insert position are also copied into the new array and the old array is deleted

    // this is how the insert operation occurs in the vector,it costs much time in case of larger size of vector, in that scenario using list will consume much time

    // --------------------erase-------------
    // erase also will work  like  the insert function ,here the specifies position is eliminated and remaining elements are copied
    // it is also time ineffective
    // let us erase the 999 from the vector
    v.erase(v.begin() + 2);
    std::cout << "the vector elements after deleting the 999 is : " << std::endl;
    for (auto x : v)
        std::cout << x << std::endl;

    // -------------empty------------
    // empty method will return the bool if vector is empty it returns 1 else returns 0
    // let us create a empty vector and check it
    std::vector<int> sai;
    if (sai.empty())
        std::cout << "the vector is empty : " << std::endl;
    else
        std::cout << "the vector is not empty" << std::endl;

    // --------------front-------------
    // front method will return the first element of the vector
    std::cout << "the first element of the vector is :  " << v.front() << std::endl;

    // -----------back------------
    std::cout << "the last element of the vector is :  " << v.back() << std::endl;

    // ---------------rbegin()------------
    // rbegin will return the iterator to the last element of the vector
    // we can dereference it , if we derefernce the iterator we will get the first element

    // -------------rend()----------
    // rend will return the iterator to the imaginary element that is front of the first element
    //  we cannot dereference it

    // let us print the vector in reverse order using the rbegin and rend
    std::cout << "the reverse order of the vector using the rbegin and rend " << std::endl;
    for (auto itr = v.rbegin(); itr != v.rend(); itr++)
    {
        /* code */ std::cout << *itr << std::endl;
    }

    std::cout << "the reverse order of the vector using the begin and end : " << std::endl;
    for (auto it = v.end() + 1; it >= v.begin(); it--)
    {
        std::cout << *it << std::endl;
    }

    // ----------clear-----------
    // clear function will clear the memory allocated to the vector ,so the vector becomes empty
    // let us check it
    v.clear();
    if (v.empty())
        std::cout << "the vector is emptied by the clear function " << std::endl;
    else
        std::cout << "the vector is not empty " << std::endl;

   

    return 0;
}