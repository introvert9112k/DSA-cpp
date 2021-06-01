// in this we will look at the stl library 

// first of all we using the namespece std is not the good programming practice, by using them we forcefully pulling all the contents of it into the code,which we do not use normally,moreover the variable names or function names declared in the std namespace may colloide with the other variables in onther varibale ,so it is better programming practise to include the namespace as prefix to which the variable or function belongs to 

// let we rewrite the user code snippets too
#include<iostream>
#include<string>
// #include<algorithm>
#include<vector>

int main() 

{
         std::cout<< "this is the standarad template library intro file" << std::endl;
         std:: vector<int> v;

        
         
          return 0;

}