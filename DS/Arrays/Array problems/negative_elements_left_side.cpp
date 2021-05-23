// problem statement
// given an arrray of integers arrange all the negative elements on left side and +ve elements on right side

#include <iostream>
#include <string>
#include <algorithm>
// Algorthim
// here we maintain a two pointers let i,j
// i intial points to first index of array,and j points to last index
// i is for finding the positive elements from left side and j is for finding the negative elements from the right side
// when we encounter the positive element from left side and negative element from right side we swap them and move on until i<=j

using namespace std;
void left_side(int *array, int length)
{
    int i = 0, j = length - 1;
    while (i <= j)
    {
    
        while (array[i] < 0)
        {  
            i++;
        } 
        while (array[j] > 0)
        {
            j--;
        } 
        if (i < j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }  
} 
int main()

{
    int size;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
        cin >> array[i];
    left_side(array, size);
    for (auto x : array)
        cout << x << endl;
    return 0;
} 
