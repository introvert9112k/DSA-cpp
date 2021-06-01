// in this we will implement the queue using array with the help of class
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class queue
{
private:
    int size;
    int front;
    int rare;
    int *arr;

public:
    queue(int length)
    {
        size = length;
        front = -1;
        rare = -1;
        arr = new int[size];
    } 
    void enqueue(int value);
    bool isempty();
    bool full();
    int dequeue();
    void traverse();
};
bool queue::full()
{
    return rare == size - 1 ? true : false;
}
bool queue::isempty()
{
    return front == rare ? true : false;
}

void queue::enqueue(int value)
{
    if (full())
        cout << "queue is empty" << endl;
    else
    {
        rare++;
        arr[rare] = value;
    }
}
int queue::dequeue()
{
    int x = -1;
    if (isempty())
        cout << "queue is empty";
    else
    {
        front++;
        x = arr[front];
    }
    return x;
}
void queue::traverse()
{
    for (int i = front + 1; i <= rare; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()

{
    queue q(10);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(13);
    cout << "the elements of the queue are : " << endl;
    q.traverse();
    q.dequeue();
   
    return 0;
} 