// problem statement 
// check whether the given array is sorted or not 

// Algorithm 
// we will compare the first element with the second element if it first is smaller than the second then we move on in this way we compare the element with its previous element , if we encounter the case where previous is not smaller than the present element then array is not sorted if we did not encounter any such case and reached the end of the array then array is in sorted order 

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string checking_sorted(int *array,int length)
{    
    if(length == 1)
        return "sorted";
    for (int i = 1; i <= length ; i++)
        if(array[i-1] > array[i]) 
            return "unsorted";
    return "sorted"; 
}  
int main() 

{
    int size;
    cout<< "enter the size of the array :" <<endl;
    cin >> size;
    int array[size];
    cout<< "enter the elements of the array :" <<endl;
    for (int i = 0; i < size; i++)
        cin >> array[i];
    cout << checking_sorted(array, size) << endl; 
    

    return 0;

} 