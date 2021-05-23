// problem statement 
// find the duplicates in the sorted array 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void duplicates(int *array,int size)
{
    int i = 0,flag=1;
    while(i<size)
    {
        while(array[i]==array[i+1])
        {   
            if(flag==1)
                cout << array[i]<< " ";
            i++;
            flag++;
        } 
        i++;
        flag = 1;
    } 
    // time complexity is linear O(N)  
}    
int main() 

{
    int size;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
        cin >> array[i];
    duplicates(array, size);

    return 0;
  
} 