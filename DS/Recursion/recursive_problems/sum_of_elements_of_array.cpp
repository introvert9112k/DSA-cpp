// in this we will find the sum of elements of the array using recursion

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int elements_sum(int *array,int n)
{
    static int i = 0;
    return i >= n ? 0 : array[++i - 1] + elements_sum(array,n);  
} 
int main()

{

    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    cout<< "the sum of elements of array is : " << elements_sum(array,n)<<endl;
    return 0; 
}  