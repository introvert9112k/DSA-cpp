#include <bits/stdc++.h>
using namespace std;

class BinaryHeap
{
public:
    int capacity; /*Maximum elements that can be stored in heap*/
    int size;     /*Current no of elements in heap*/
    int *arr;     /*array for storing the keys*/

    BinaryHeap(int cap)
    {
        capacity = cap;          /*Assigning the capacity*/
        size = 0;                /*Intailly size of hepa is zero*/
        arr = new int[capacity]; /*Creating a array*/
    }

    /*returns the parent of ith Node*/
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    /*returns the left child of ith Node*/
    int left(int i)
    {
        return 2 * i + 1;
    }
    /*Returns the right child of the ith Node*/
    int right(int i)
    {
        return 2 * i + 2;
    }

    /*Insert a new key x*/
    void Insert(int x)
    {
        if (size == capacity)
        {
            cout << "Binary Heap Overflwon" << endl;
            return;
        }
        arr[size] = x; /*Insert new element at end*/
        int k = size;  /*store the index ,for checking heap property*/
        size++;        /*Increase the size*/

        /*Fix the min heap property*/
        while (k != 0 && arr[parent(k)] > arr[k])
        {
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }
    
    void Decreasekey(int i, int val)
    {
        arr[i] = val;                             /*Updating the new_val*/
        while (i != 0 && arr[parent(i)] > arr[i]) /*Fixing the Min heap*/
        {
            swap(&arr[parent(i)], &arr[i]);
            i = parent(i);
        }
    }
    int getMin()
    {
        return arr[0];
    }
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}; 
int main()

{
    BinaryHeap h(20);
    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);
    cout << "Min value is " << h.getMin() << endl;
    h.Decreasekey(3, -1);
    cout << "Min value is " << h.getMin() << endl;
    return 0;
}  