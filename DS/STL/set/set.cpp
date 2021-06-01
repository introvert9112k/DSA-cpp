// in this we will look at set in standard template library 

//1. syntax std::set<data type> object name 
// 2.std::set is an Associative container that contains a sorted set of unique objects of type keyy 
// 3.it is usually implementted using red black tree 
// 4.insertion removal search have logirathmic complexity 
//5. if we want to store user defineddat type in set then we will  have to probide compare function so that set can store them in sorted order
// 6.we can pass the order of sorting while constructing the set object 


// set stores unique elements and they are stored in sorted order 

#include<iostream>
#include<string>
#include<set>
// #include<functional>
#include<algorithm>

using namespace std;
int main() 

{
    // it is included in the set header file 
    set<int> sai = {1,2,3,4,5,2,5,3,2};
    cout << "the elements of the set sai is : " << endl;
    for(auto x : sai)
        cout<<x<<endl;
        // notice that it printed only unique elements
    set<int> sri = {3, 4, 21, 1, 3, 5, 2, 1};
    // see these elements are not in sorted order and there are duplicates set takes onlly the unique elements and arrange them in sorted order 

    // ascending order is the default sort we can chage the sorting order to descending too
    cout << "the elements of the sri which are intially unsorted is : " << endl;
    for(auto &x : sri)
        cout << x << endl;
    
    // insert function is used for inserting elements into set
    sri.insert(56);
    // insert will insert the element in the sorted position 
    // when ever we try to insert the element into the set first it will check whethet the value provided is in the set or not if not then it will insert the value in sorted position 
    cout << "sri set after inserting the 56 is : " << endl;
    for(auto x : sri) 
        cout<<x<<endl;

        // ----------let we change the order of sort ------------
    set<int,greater<>> karna;

    // if we want to insert in the descending order we should include the greater inside the data type of set 

    // the syntax is set<int,greater<int>> or set<int,greater<>> 

    // by default it would be set<int,less<>> so the set is in ascending sort

    // in greater<> or less<> the data type is automaticallly detected no need to pass them explictly as greater<int> less<int> if we pass also there is no problem

    NOTE : 
    // int ,floats,doubles,strings and char are easily compared using the comparision operator like > < = but user defined data types like classes and structs cannot be compared using the comparision operators because they have collection data types in that scenario we should define the comparator that which states on which bases we should compare in order to arrange them in sorted order '
    karna.insert(56);
    karna.insert(2232);
    karna.insert(567);
    cout << "the elements of the set karna are : " << endl;
    for(auto x : karna)
        cout<<x<<endl;
    return 0;
}  
