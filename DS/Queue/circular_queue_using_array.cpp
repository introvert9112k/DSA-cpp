#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class queue
{
    int size;
    int front;
    int rare;
    int *arr;

public:
    queue(int n)
    {
        size = n;
        front = rare = -1;
        arr = new int[n];
    }
    bool full()
    {
        return (rare + 1) % size == front;
    }
    bool empty()
    {
        return front == -1 and rare == -1;
    }
    void enqueue(int data)
    {
        if (full())
        {
            cout << "queue is full" << endl;
        }
        else
        {
            if (front == -1)
                front = 0;
            rare = (rare + 1) % size;
            arr[rare] = data;
        }
    }
    int dequeue()
    {
        int x = -1;
        if (empty())
        {
            cout << "queue is empty" << endl;
            return x;
        }
        else
        {
            x = arr[front];
            if (front == rare)
            {
                front = -1;
                rare = -1;
            }
            else
                front = (front + 1) % size;
            return x;
        }
    }
};
int main()

{
    queue q(4);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(8);
    // q.enqueue(10);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
} 