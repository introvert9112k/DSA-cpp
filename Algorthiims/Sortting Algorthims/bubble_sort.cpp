// in this we will look at the bubble sort algorthim 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void bubble_sort(int *array, int length)
{
    for (int i = 0; i < length-1; i++)
    {
        for (int j = 0; j < length-1-i; j++)
        {
            if(array[j] > array[j+1])
          {
                 int temp = array[j];
                 array[j] =  array[j+1];
                 array[j+1] = temp;
           }
        }
        
    }
    
}
int main() 


{
         int num;
         cout<< "enter the size of the array" <<endl;
         cin>>num;
         int array[num];
         for(int i=0; i<num; i++)
             cin>>array[i];
        bubble_sort(array,num) ;
        cout<< "the array after sorting is : "<<endl;
        for(int x : array)
              cout<< x <<endl;

          return 0;

} 