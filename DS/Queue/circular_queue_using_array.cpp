#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct queue
{
    int size;
    int front;
    int rare;
    int *arr;
};
bool full(struct queue &q)
{
    return (q.rare + 1) % q.size == q.front ? true : false;
}
bool empty(struct queue &q)
{
    return q.rare == q.front ? true : false;
}
void enqueue(struct queue &q, int value)
{
    if (full(q))
    {
        cout << "queue is full" << endl;
    }
    else
    {
        q.rare = (q.rare + 1) % q.size;
        q.arr[q.rare] = value;
    }
} 
int dequeue(struct queue &q)
{ 
    int x = -1;
    if (empty(q))
        cout << "the queue is empty" << endl;
    else
    {
        q.front = (q.front + 1) % q.size;
        x = q.arr[q.front];
    }
    return x;
}
void traverse(struct queue &q)
{
    for (int i = q.front; i <q.rare; i++) 
        cout << q.arr[i]<<endl;
} 
int main()

{
    struct queue q;
    cout << "enter the size of the queue : " << endl;
    cin >> q.size;
    q.front = 0;
    q.rare = 0;
    enqueue(q, 3);
    enqueue(q, 9);
    enqueue(q, 6);
    enqueue(q, 4);
    cout << "the elements of the queue are : " << endl;
    traverse(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    cout << "the elements after removing three operations are : " << endl;
    traverse(q); 
    return 0;
}     