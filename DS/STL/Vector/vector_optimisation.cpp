// in this we will disuss about how can we can write the better vectors 
// let us first of all discuss about the size and the capacity of the vectors 
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
int main() 

{
         std::vector<int> v;
         for(int i=0; i<32; i++)
         {
           v.push_back(i);
           std::cout<< "size is : " << v.size() << "  " << "capacity is : " << v.capacity() <<std::endl;
         
         } 
        //  from the output it is clear that the whenever the size of the vector is not sufficent then it doubles it size 
        // let us discuss it breifly 
        // first size and capacity is 0
        // now size is 1 and capacity is 1
        // now we are adding the 2nd element and the vector size is not suffiecent to hold it,so it doubles it capacity so now capacity becomes 1*2 i.e 2
        // now size becomes 2 and capacity is also 2 
        // now we insert 3rd element as the vector is filled so it doubles it capacity now the capacity becomes 2*2 i.e 4
        // now we insert 4th element,as there is space in the vector the element can be easily fitted so capacity remains same 
        // now we will insert 5th element ,as the vector is fill now the capacity is doubled 4*2 i.e 8 so the size is 5 and capacity is 8
        // so until the vector size is filled the capacity remains same 

        // This is how the vector is implemented internally 

        // NOte that every time when the vector is filled we are doubling its capacity and copying the elements into new array, this is takes some time,which is not a good practise ,can we get rid of this copying 

        // we can use the reserve keyword this reserves the determined memory for the vector,so the array is not filled frequently,whenever the array size reached the determined length then it doubles automatically

        // first we should estimate that how many elements may fit in the vector and resereve that much memory allocation to the vector 
        // let us do that 

        std::vector<int> v2;
        v2.reserve(33);
        std::cout<< "the memory is reserved for the vector " <<std::endl;
        for(int i=0; i<32; i++)
        {
             v2.push_back(i);
             std::cout<< "the size is : " << v2.size() << " " << "the capacity is : " << v2.capacity() <<std::endl;
        }
         
    //    see the capacity is 33 in all cases,so the creating a new array and copying previous elements into it does not occurs , which saves significant amount of time in very large cases 
      //  there may be a situation that the extra space is reserved for the vector, we can delete the extra memory allocated to the vector using the function shrink to fit 
      // let us discuss it  

      std::vector<int> sai;
      sai.reserve(1000);
      // here we reserved the memory for the 1000 integers 
      for (int i = 0; i < 50; i++)
      {
        /* code */sai.push_back(i);
      }
      // here we inserted only 50 elements and remaining 950 memory allocations are still under the vector ,so we should free the memory 
      // let us do it  
      std::cout<< "the size of the vector is :  " << sai.size() <<" the capcity of vector is :  "<<sai.capacity() <<std::endl;
         
        //  let us shrink the vector 
        sai.shrink_to_fit();
        std::cout<< "the size and capacity of the vector after shrinking is :  " <<std::endl;
        std::cout<< "the size is :  "<<sai.size() << " the capacity is : " <<sai.capacity() <<std::endl;
        // before shrinking the size is 50 and the capcity is 1000 after shrinking the size and capacity is 50
        // shrink to fit function will reduce the vector capacity to its size 
        


          return 0;

} 