// in this we will implement the queue data structure using the array
// in queue elements are inserted at the rare end and deletion is done from the front end
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
bool isempty(struct queue &q)
{
    return q.rare == q.front ? true : false;
}
bool full(struct queue &q)
{
    return q.rare == q.size - 1 ? true : false;
}
void enqueue(struct queue &q, int value)
{
    if (full(q))
        cout << "queue is full";
    else
    {
        q.rare++;
        q.arr[q.rare] = value;
    }
}
void traverse(struct queue &q)
{
    for (int i = q.front + 1; i <= q.rare; i++)
    {
        cout << q.arr[i] << " ";
    }
    cout << endl;
} 
int dequeue(struct queue &q)
{
    int x = -1;
    if(isempty(q))
        cout << "the queue is empty" << endl;
    else
    {
        q.front++;
        x = q.arr[q.front];
       
    } 
    return x;
} 
int main()

{
    struct queue q;
    cout << "enter the size of the queue : " << endl;
    cin >> q.size;
    q.rare = -1;
    q.front = -1;
    q.arr = new int[q.size];
    enqueue(q, 3);
    enqueue(q, 5);
    enqueue(q, 19);
    enqueue(q, 39);
    cout << "the elements of the deque before popping is : " << endl;
    traverse(q);
    dequeue(q);
    dequeue(q);
    cout << "the elements after popping is : " << endl;
    traverse(q);

    return 0;
} 