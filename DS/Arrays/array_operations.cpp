// in this we will look at arrays briefly and operations that can be performed in array
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class array
{
private:
    int *a;
    int capacity;
    int length;

public:
    array(int cap, int size) //constructor
    {
        capacity = cap;
        length = size;
        a = new int[capacity];
    }
    void traverse()
    {
        // time complexity is O(N)
        if (length != 0)
        {
            for (int i = 0; i < length; i++)
                cout << a[i] << endl;
        }
        else
            cout << "the array is empty" << endl;
    }

    void insert(int position, int value)
    {
        // in best case the element is inserted at last which would take constant time and in worst case the element is inserted at zeroth position and time complexity is linear

        // best case is O(1)
        // worst case is O(N)

        if (length == capacity)
            cout << "the array capacity has reached ,element cannot be inserted" << endl;
        else if (position < 0 or position >= capacity)
        {
            cout << "the position is beyond the capcity of the array :" << endl;
        }
        else
        {
            for (int i = length - 1; i >= position; i--)
            {
                a[i + 1] = a[i];
            }
            a[position] = value;
            length++;
        }
    }

    void remove(int position)
    {
        // in best case the element is removed at last which would take constant time and in worst case the element is removed at zeroth position and time complexity is linear

        // best case is O(1)
        // worst case is O(N)

        if (length == 0)
            cout << "the array is empty there are no elements to delete" << endl;
        else if (position < 0 or position >= capacity)
            cout << "the position is beyond the capacity of the array :" << endl;
        else
        {
            for (int i = position + 1; i < length; i++)
                a[i - 1] = a[i];
            length--;
        }
    }
    void append(int value)
    {
        //  constant time
        if (length >= capacity)
            cout << "the array has reached it's capacity,value cannot be append" << endl;
        else
        {
            a[length] = value;
            length++;
        }
    }
    int linear_search(int key)
    {
        // best case O(1)
        // worst case O(N)

        for (int i = 0; i < length; i++)
            if (key == a[i])
                return i;
        return -1;
    }
    int binary_search(int key)
    {
        // before using the binary search make sure that the array is sorted
        // time complexity O(log2N)
        // space complexity O(1)

        int low = 0, high = length;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] == key)
                return mid;
            else if (a[mid] > key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    } 

    int recursive_binary_search(int key, int low, int high)
    {
        // time complexity is O(log2N)
        //  space complexity is O(log2N)
        // iterative approach is better than the recursive approach as its takes constant space complexity

        int mid = (low + high) / 2;
        if (low <= high)
        {
            if (a[mid] == key)
                return mid;
            else if (a[mid] > key)
                return recursive_binary_search(key, low, --mid);
            else
                return recursive_binary_search(key, ++mid, high);
        }
        return -1;
    }
    int get(int position)
    {
        //  this function returns the value at given index
        if (position < 0 or position >= length)
            cout << "position is invalid" << endl;

        return a[position];
        //   time complexity is constant
    }
    void set(int position, int value)
    {
        // this function will replace the value in given position with the value provided
        if (position < 0 or position >= length)
            cout << "the position is invalid" << endl;
        else
            a[position] = value;
    }
    int max()
    {
        int max = a[0];
        for (int i = 0; i < length; i++)
            if (a[i] > max)
                max = a[i];
        return max;

        // best case is O(1)
        // worst case is O(N)
    }
    int min()
    {
        int min = a[0];
        for (int i = 0; i < length; i++)
            if (a[i] < min)
                min = a[i];
        return min;
    }
    int sum()
    {
        int s = 0;
        for (int i = 0; i < length; i++)
            s = s + a[i];
        return s;
        // time complexity is O(N)
    }
    int recursive_sum()
    {
        static int i = 0;
        return i == length ? 0 : a[i++] + recursive_sum();
    }

    void reverse()
    {
        for (int i = 0; i < length / 2; i++)
        {
            int temp = a[length - i - 1];
            a[length - 1 - i] = a[i];
            a[i] = temp;
        }
        //    time complexity is O(N/2)  or O(N)
    }
};

int main()

{
    int capacity, ch, index;
    int value, sai;
    cout << "enter the capacity of the array : " << endl;
    cin >> capacity;
    array arr(capacity, 0); //object of the class
    while (true)
    {
        cout << endl;
        cout << "Menu" << endl;
        cout << "1.insert" << endl;
        cout << "2.remove" << endl;
        cout << "3.append" << endl;
        cout << "4.max" << endl;
        cout << "5.min" << endl;
        cout << "6.traverse" << endl;
        cout << "7.linear_search" << endl;
        cout << "8.sum" << endl;
        cout << "9.get" << endl;
        cout << "10.set" << endl;
        cout << "11.exit" << endl;
        cout << endl;

        cout << "enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter the index and value : " << endl;
            cin >> index >> value;
            arr.insert(index, value);
            break;
        case 2:
            cout << "enter the index : " << endl;
            cin >> index;
            arr.remove(index);
            break;
        case 3:
            cout << "enter the value : " << endl;
            cin >> value;
            arr.append(value);
            break;
        case 4:
            cout << "the max element of the array is : " << arr.max() << endl;
            break;
        case 5:
            cout << "the min element of the array is : " << arr.min() << endl;
            break;
        case 6:
            cout << "the elements of the array are : " << endl;
            arr.traverse();
            break;
        case 7:
            cout << "enter the value that you want to search : " << endl;
            cin >> value;
            sai = arr.linear_search(value);
            if (sai != -1)
                cout << "the element found at index : " << sai << endl;
            else
                cout << "the element not found" << endl;
            break;
        case 8:
            cout << "the sum of all elements is : " << arr.sum() << endl;
            break;
        case 9:
            cout << "enter the index : " << endl;
            cin >> index;
            cout << arr.get(index) << endl;
            break;
        case 10:
            cout << "enter the index and value to set : " << endl;
            cin >> index >> value;
            arr.set(index, value);
            break;
        case 11:
            exit(0);
        default:
            exit(0);
        }
    }

    return 0;
}