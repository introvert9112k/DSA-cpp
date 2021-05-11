// in this we will look at the selection sort algorthim
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int minimum_element(int start, int end, int *array)
{  
   int min_value = array[start];
   int index = start;
    for (int i = start; i < end; i++)
    {
        if(array[i] < min_value)
         {
              min_value = array[i];
              index = i; 
         } 
    } 
    return index;
    
} 


void selection_sort(int *array , int length)
{
          for (int i = 0; i < length-1; i++)
          {
              int index = minimum_element(i,length,array);
            //   cout<< "  " << index <<endl; 
              int temp = array[index];
              array[index] = array[i];
              array[i] = temp; 
          } 
          
}

int main() 

{
         int num;
         cout<< "enter the size of the aray"<<endl;
         cin>>num;
         int array[num];
         for(int i=0; i<num; i++)
             cin>>array[i];
         selection_sort(array,num);
         cout<< "the array after sorted is " <<endl;
         for(int x : array)
            cout<< x <<endl;
        // cout << "the minimum element is at index : " << minimum_element(0,num,array);
       return 0; 
  
}  