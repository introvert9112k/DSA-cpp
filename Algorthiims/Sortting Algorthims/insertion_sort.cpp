// in this we will look at the insertion sort algorthim 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void insertion_sort(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        int k = i;
        while (array[k-1] > array[k] && k > 0)

        {
            int temp = array[k-1]; 
            array[k-1] = array[k];
            array[k] = temp; 
            k--;
        }     
        
    }
    
} 

int main() 

{
         int num;
         cout<< "enter the size of the array"<<endl;
         cin>>num;
         int array[num];
         for(int i=0; i<num; i++)
             cin>>array[i];
         insertion_sort(array,num); 
         cout<< "the array elements after sorting is "<<endl; 
          for (int x : array) 
            cout<< x<<endl;
           return 0;

} 