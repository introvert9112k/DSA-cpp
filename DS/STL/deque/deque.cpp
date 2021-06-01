// deque is similar to the vector but their are some changes in deque
// we can randomly access the elements of deque like the vector
// unlike vector we can push front and pop front,in deque we can push and pop from front and end
// like the vector deque can automatically expand and shrink

// acessing elements is of O(1) time complexity
// insertion and deletion from begining and end is of O(1) time complexity
// inserting and erase takes the O(n) time complexity ,but insertion and deletion takes less time in deque compared to vector because in deque there is no copying of elements unlike in vector
// in deque memory is not allocated continously, some memory is allocated continously and it is connected with another continous memory like linked list, but in deque arrays are linked together

// deque are used when insertion and deletion is done from either front or back

// --------methods of deque-------------
// size()
// = []
// front() back()
// empty()
// begin() end() rbegin() rend()
// insert() erase()
// clear()
// push_back() push_front() pop_back() pop_front()

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
int main()

{
    deque<int> sai = {1, 2, 3, 4, 5, 6};
    deque<int> angajala;
    // --------size method---------------
    cout << "the size of the deque is : " << sai.size() << endl;

    // copying the elements of the sai into angajala
    angajala = sai;
    cout << "the elements of the angajala deque are : " << endl;
    for(auto x : angajala)
        cout<<x<<endl;

    // ---let us access the elements using random access----------
    for (int i = 0; i < sai.size(); i++)
        cout << sai[i] << endl;

    // ------------front---------
    // front will return the first element of the deque
    cout << "the first element of the deque is : " << sai.front() << endl;

    // -----------back-----------
    // back will return the last element of the deque
    cout << "the last element of the deque is :  " << sai.back() << endl;

    // ----------rbegin--------------
    // rbegin will return the iterator to the  last element of the deque
    cout << "the last element of the deque is :  " << *sai.rbegin() << endl;

    // ------------begin-----------
    // begin will return the iterator to the first element of the deque
    cout << "the first element of the deque is :  " << *sai.begin() << endl;

    // ----empty---------
    // empty will return true if deque is empty else  return false
    if (sai.empty())
        cout << "the deque is empty" << endl;
    else
        cout << "the deque is not empty " << endl;

    // ----push_front-------------
    // push_front will push the element to the start of the deque
    sai.push_front(9);
    cout << "the first element of the deque is : " << sai.front() << endl;

    // ---------pop_front-----------
    // pop front will pop out the first element of the deque
    cout << "now the first element is  : " << sai.front() << endl;

    // -----push_back-----------
    // push_back will add the element at the last of the deque
    sai.push_back(9999);
    cout << "the last element of the deque is : " << sai.back() << endl;

    // -------------pop_back() --------
    // pop_back will pop the last element of the deque
    sai.pop_back();
    cout << "now the last element is :  " << sai.back() << endl;
   
   //    ---------insert---------
   //   let us insert at the 4th positon 
    sai.insert(sai.begin() + 3, 8999);
    cout << "the fourth element of the deque is : " << sai[3] << endl; 

    // ------------erase----------
    // now let us remove the 4th element of the deque
    sai.erase(sai.begin() + 3);
    cout << "fourth element of the deque after delting 8999 is : " << sai[3] << endl;


    // sorting and reversing the deque 
    // there is no class methods available for deque ,sort and reverse defined is algorthim header file is used for sorting and reversing the deque 
    // for list sort and reverse methods are available
    deque<int> sri = {3, 2, 1, 99, 232, 114, 434};
    cout << "the deque sri after sorting is: " << endl;
    sort(sri.begin(), sri.end());
    for(auto x : sri)
        cout<<x<<endl; 

    // -------------reverse method--------
    reverse(sri.begin(), sri.end());
    cout << "the deque sri after reversing is : " << endl;
    for(auto x : sri)
        cout<<x<<endl; 

    return 0;
}
