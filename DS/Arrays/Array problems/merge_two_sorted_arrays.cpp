// problem statement
// given two sorted arrays ,merge the two arrays into one

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void merge_two_sort_arrays(int *array1, int *array2, int *merge_array, int length1, int length2)
{
    int i = 0, j = 0, p = 0;
    while (i < length1 && j < length2)
    {

        if (array1[i] < array2[j])
            merge_array[p++] = array1[i++];
        else if (array2[j] < array1[i]) 
            merge_array[p++] = array2[j++];
        else if (array1[i] == array2[j])
        {
            merge_array[p++] = array2[j];
            i++;
            j++; 
        }
    }  
    while (j < length2)
        merge_array[p++] = array2[j++];
    while (i < length1)
        merge_array[p++] = array1[i++];
} 
int main()

{
    int size1, size2;
    cin >> size1 >> size2;
    int array1[size1];
    int array2[size2];
    int merge_array[size1 + size2];
    for (int i = 0; i < size1; i++)
        cin >> array1[i];
    for (int i = 0; i < size2; i++)
        cin >> array2[i];
    merge_two_sort_arrays(array1, array2, merge_array, size1, size2);
    for (auto x : merge_array)
        cout << x << " ";
    return 0;
}