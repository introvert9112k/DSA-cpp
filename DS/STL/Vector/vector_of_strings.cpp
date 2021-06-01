// let us create the vector with all the elements as strings 
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
int main() 

{
         
           std::vector<std::string> v;
           for(int i=0; i<5; i++)
           {
             std::string sai;
             std::cin>>sai;
             v.push_back(sai);
           
           } 
         std::cout<< "the elements of the vector are :  " <<std::endl;
           for(auto x : v)
               std::cout<<x<<std::endl;


           std::cout<< "this is example of array of strings " <<std::endl;
           std::string array[5];
           for (int i = 0; i < 5; i++)
           {
              std::cin>> array[i];
           }
      
      std::cout<< "the array of string elements are : " <<std::endl;
           for(auto x : array)
               std::cout<<x<<std::endl;  
               

          return 0;

}