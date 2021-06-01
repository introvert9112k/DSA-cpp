// in this we will look at the stl library 

// first of all we using the namespece std is not the good programming practice, by using them we forcefully pulling all the contents of it into the code,which we do not use normally,moreover the variable names or function names declared in the std namespace may colloide with the other variables in onther varibale ,so it is better programming practise to include the namespace as prefix to which the variable or function belongs to 

// let we rewrite the user code snippets too
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

int main() 

{  
         std::cout<< "this is the standarad template library intro file" << std::endl;
        //  in this we will breifly discuss about teh vectors 

        // --------------vector-------------

        // vector is also known as the sequential container,Dynamic array, and array list 
        // vector has the sequential memory allocation,so it is called as sequential container ,and it supports the insertion and deletion of elements without any size constraints so it has features of list also ,as the vector has the properties of both the array and list it is called the arraylist ,as it expand the size it is also called dynamic array 

        // ---------------types of declaring the vectors ----------------

        // -------creating the empty vector---------
         std:: vector<int> v;
        //  this is how we create the empty vector 
        // we can add the elements to the vector using the push_back methods 
        for (int i = 0; i < 6; i++)
        {
            int value;
            std::cin>>value;
            v.push_back(value); 
        }
        
        // ------------creating the vector with the some definite size-----------

        std::vector <int> v1(10);
        // this will create the vector with the size 10
        // but the capacity of the vector will be greater than the size,the capacity depends upon the complier,as it is dynamic it can increases it's size, intially it allocates the sequential memory that is somewhat greater than the size of the array to allocate the extra elements whenever the allocated space is fully filled it creates a another array of some bigger size copies these elements into it and starts pointing to the new created memory,previously created memory is deleted 
        std::cout<< "all the elements are intially set to zero" <<std::endl;
        for(auto x : v1)
            std::cout<<x<<std::endl;
        // like the array it also intialises all the values to the zero intially 


        // creating a vector with some size and intialising all elements with one value 
        std::vector<int> v3(10,4);
        std::cout<< "all the elements are intialized to 4 " <<std::endl;
        for(auto x : v3)
            std::cout<<x<<std::endl;
 
        // --------------declaring like the array----------

        std::vector<int> v4 = {1,23,4,5,6};
        std::cout<< "declaring elements like the aray: " <<std::endl;
        std::cout<< "" <<std::endl;
        for(auto x : v4) 
            std::cout<<x<<std::endl;
         
        // --------these are the some ways of declaring the vectors ------------

        // -----------acessing the vector elements---------------
        // elements can be acessed using the at(),[],front(),back(),dat()
        // let us see one by one 


         std::cout<< "acessing the vector elements using the at method" <<std::endl;
         for (int i = 0; i < v4.size(); i++)
         {
             /* code */
             std::cout<< v4.at(i) <<std::endl;
         }

        //   ---------acessing elements using the [] operator ---------
        for (int i = 0; i < v4.size(); i++)
        {
            /* code */
            std::cout<< v4[i] <<std::endl;
        }

        // ------front----------
        // front method will return the iterator pointing to the first position of vector 
        // this will give the first element of the vector 
        std::cout << "the first element of the vector v4 is : "<< std::endl;
        std::cout<< v4.front() <<std::endl;
               
            //    --------------------back------------
            // back will return the last element of the array 
            std::cout<< "the last element of the vector v4 is : " <<std::endl;
            std::cout<< v4.back() <<std::endl; 
     
    //    ------using the iterator --------------
        std::cout<< "acessing the elements using the iterator" <<std::endl;
        std::vector<int>:: iterator itr;
        for ( itr = v4.begin(); itr < v4.end(); itr++)
        {
            /* code */
            std::cout<< *itr <<std::endl;
        }  
        
        
        

          return 0;

}