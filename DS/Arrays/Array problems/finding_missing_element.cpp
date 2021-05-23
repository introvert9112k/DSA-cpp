// problem statement 
// given an sorted array we should find the misiing elements in the array 

// Algorthim 
// first find the first and last element of the array,their difference would be the length of the array,now start from the first index and find the  difference between the value at that index and index i.e array[index] - index 

// if this is equal to the value at first index then the element is not missing if not the element is missing , the missing element value is equal to index+ first_value . there may be multiple elements misiing between the two numbers so we run a while loop for the difference between two number of times and find the missing element and update the first_value of array 

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void missing_elements(int *array,int size)
{
   
    int diff = array[0];
    bool flag = true;
    cout<< "the missing elements are : " <<endl;
    for (int i = 0; i < size; i++) 
    {
        if((array[i]-i)!=diff)
        {
            int diff1 = array[i] - array[i - 1];
            while(--diff1)
            {
                cout<< i+diff <<"  ";
                diff++;
                flag = false;
            } 
        }
    } 
    if(flag)
        cout << "no elements are missing"; 
} 
// time complexity is linear 
// this works for single missing elements and the multiple missing elements 
int main() 

{
    int size;
    cin >> size;
    int array[size];
    cout<< "enter the sorted array with missing elements :" <<endl;
    for (int i = 0; i < size; i++)
        cin >> array[i];
    missing_elements(array,size);
    return 0;

} 