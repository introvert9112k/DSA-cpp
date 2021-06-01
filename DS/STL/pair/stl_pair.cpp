// in this we will look at the stl pair 
// pair is nothing but combination of two data types these data types can be of any type 
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int main() 

{
    pair<string,int> sai =  {"saisri angajala",30} ;
    // this is the syntax for intializing the pair 
    // here sai is the object of the pair
    // in this example first data type in pair is string and second is int 
    // we can acess the elements in pair using the first and second attributes 
    cout<< "the first element of pair is : " <<sai.first <<endl;
    cout << "the second element of the pair is : " << sai.second << endl; 
     
    //  -----------make_pair method--------------
    // there is a built in method called make pair that makes pair for the given vales
    pair<int,string> sri = make_pair(34, "angajala");
    // this is useful when we are passing the pair as the data type in any containers
    // let us define the vector of pairs

    vector<pair<int, int>> arr;
    arr.reserve(5);
    // the elements of the vector arr are pairs 
    // intilaizing the elements of the vector 

    // for (int i = 0; i < 5; i++)
    // {
    //     pair<int, int> temp;
    //     cin >> temp.first;
    //     cin >> temp.second;
    //     arr.push_back(temp);
    //     // in this we explictly defined data type pair and intialised the elements of pair and we pushed into the vector 
    //     // this is time consuming /
    //     // make pair makes this simple,we did not require the data type to be declares it automaticallly declares the pair and intialises the value passed into it 
    // }

    for (int i = 0; i < 5; i++)
        arr.push_back(make_pair(i, i + 2));
      
    //   ------------for each loop----------
    // if we use the auto x then the values will be copied into x and we cannot change the values 
      for(auto x : arr)
          cout<<x.first <<" " << x.second <<endl;
        
    // if we use the auto &x then the values are passed by reference so no copying occurs and if we change the x then this change will apperar in the original one too  
    for(auto &x : arr)
        cout << x.first << " " << x.second << endl;

    // if we use const auto &x then the values are  passed by rreference and wer cannot change the values 
    for(const auto &x : arr)
        cout << x.first << " " << x.second << endl;

    // --------------IN SHORT-------------

    // auto x is used when we require copying and no modification 
    // auto &x is used when we do not require copying and want the modifications of original values 
    // const auto &x is used when we do not require to copy and do not need any modification 
    return 0;
} 