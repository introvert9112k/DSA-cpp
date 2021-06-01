// iterators are nothing but thr pointer objects 
// depending on the data type their working can be different 
// in vector there working would be different because it is sequential container whereas the list has its elements at the random memory locations 

// so depending upon the data type there are used the iterator working would be different 
// let us look into them 
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
int main() 

{
         std::vector<int> v = {1,3,4,4,5,6,67,9};
        //  let us declare the protype or  signature of the iterator 
        std::vector<int> ::iterator itr;
        //   here std::vector<int> ::iterator is the data type and itr is the object 
        // so this object iterates over the vector having the data type of elements as int  
        // let us acess the elements using the iterator  
        std::cout<< "acessing the elements using the iterator " <<std::endl;
        for(itr=v.begin(); itr < v.end(); itr++) 
                   std::cout<< *itr <<std::endl; 

        // we can also declare the protype of the iterator without saying the data type 
        // we use the auto keyword,while using the auto the object must be intialized first then only it understand which iterator to be used 

        auto sai = v.begin();
        // here sai will recognize the v,here v is of type vector<int> so it takes it as data type of the iterator 
        std::cout<< "acessing the elements using the auto keyword" <<std::endl;
        for(; sai < v.end(); sai++)
              std::cout<< *sai <<std::endl;     

        // here we did not mention of the first parameter of the for loop because we already assingned  sai to  the begin iteration of the vector v              
          return 0;

}