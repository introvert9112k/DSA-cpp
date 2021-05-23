
// problem statement
// insert an element in the sorted array
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void insert_in_sorted_array(int *array, int value, int &length)
{
    int l = length - 1;
    while (array[l] > value)
    {
        array[l + 1] = array[l];
        l--;
    }
    array[l + 1] = value;
    length++;
    // best case O(1)
    // worst case O(N)
}
int main()

{
    //  ----------Algorthim---------
    // first start from the last index if the number at the last index is greater than the provided value then shift it to right and check for the before element of the last element and and do the same ,continue this process until you reach a element that is smaller than the provided value and insert the  provided value there
    cout << "enter the capacity of the array : " << endl;
    int capacity, size, value;
    cin >> capacity;
    cout << "enter the size of the array : " << endl;
    cin >> size;
    int array[capacity];
    cout << "enter the elements of the array: " << endl;
    for (int i = 0; i < size; i++)
        cin >> array[i];
    cout << "enter the value that you want to insert" << endl;
    cin >> value;
    insert_in_sorted_array(array, value, size);
    cout << "the array after inserting the value is :" << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";

    return 0;
}