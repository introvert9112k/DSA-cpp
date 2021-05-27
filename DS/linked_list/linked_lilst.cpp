// in this we will implement the linked list
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *last = NULL;

void append(int value)
{
    struct node *temp, *current = head;
    temp = new node;
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
    {
        // temp = new node;
        // temp->data = value;
        // temp->next = NULL;
        head = temp;
        last = temp;
    }
    else
    {
        // while (current)
        // {
        //     last = current;
        //     current = current->next;
        // // }
        // temp = new node;
        // temp->data = value;
        // temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void traverse(struct node *temp = head)
{

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void recursive_traverse(struct node *temp = head)
{
    if (temp)
    { //printing in calling time,space complexity O(N)
        cout << temp->data << " ";
        recursive_traverse(temp->next);
    }
}
void reverse_traverse(struct node *temp = head)
{
    if (temp)
    {
        reverse_traverse(temp->next);
        //printing in returining time so it is printed reverse
        // space complexity is O(N)
        cout << temp->data << " ";
    }
}
int size()
{
    struct node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int recursive_size(struct node *temp = head)
{
    static int count = 0;
    if (temp)
        recursive_size(temp->next);
    return count++;
}

int sum(struct node *temp = head)
{
    int s = 0;
    while (temp)
    {
        s += temp->data;
        temp = temp->next;
    }
    return s;
}

int max(struct node *temp = head)
{
    int max_value = INT_MIN;
    if (!temp)
        cout << "the linked list is empty" << endl;
    else
    {

        while (temp)
        {
            if (temp->data > max_value)
                max_value = temp->data;
            temp = temp->next;
        }
    }
    return max_value;
}
struct node *linear_search(int key, struct node *temp = head)
{
    while (temp)
    {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
    // if element found it returns the pointer to the node if not returns the null
    // binary search cannot be appllied on the linked list because the binary search needs direct acessing of the elements which is not possible in the linked list
}
void move_to_front(int key)
{
    // in order to make the node as front we should have two pointers pointing to the current node and node pointing to previous node
    // move points to the current node and follow points to the previous node
    struct node *move = head;
    struct node *follow = NULL;
    int length = size();
    while (move)
    {
        if (move->data == key && move != head)
        {
            follow->next = move->next;
            move->next = head;
            head = move;
            break;
        }
        follow = move;
        move = move->next;
    }
}
void insert(int position, int value)
{
    struct node *current = head;
    int length = size();
    struct node *temp;
    temp = new node;
    temp->data = value;
    if (position <= length)
    { 
        if (position == 0)
        {
            // struct node *temp;
            // temp = new node;
            // temp->data = value;
            // temp->next = current;
            // head = temp;
            // last = temp;
            // temp->next = NULL;
            if(size() ==0)
                last = temp;
            temp->next = current;
            head = temp;
        }  
        else
        {
            if (position == length)
                last = temp;
            while (--position)
            {
                current = current->next;
            }
            // struct node *temp;
            // temp = new node;
            // temp->data = value;

            temp->next = current->next;
            current->next = temp;
        }
    }
    else
        cout << "invalid position" << endl;
} 
void insert_in_sorted_order(int value)
{
    // this is applicable only when the linked list is already sorted
    struct node *previous = NULL, *temp = NULL, *current = head;
    int flag = 1;
    temp = new node;
    temp->data = value;
    while (current)
    {
        if (current->data > value)
        {
            if (current == head)
            {
                temp->next = current;
                head = temp;
                flag = 0;
                break;
            }
            else
            {

                temp->next = current;
                previous->next = temp;
                flag = 0;
                break;
            } 
        } 
        previous = current;
        current = current->next;
    } 
    if (flag)
        append(value);
}  
void erase(int position)
{
    struct node *previous = NULL, *current = head;
    if (position < size() && size() != 0)
    {

        if (position == 0)
        {
            head = current->next;
            delete current;
        }
        else
        {

            while (position--)
            {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            if (position == size())
                last = previous;
            delete current;
        }
    }
} 
bool sorted()
{
    struct node *current = head;
    int x = INT_MIN;
    while (current)
    {

        if (x > current->data)
            return false;
        x = current->data;
        current = current->next;
    }
    return true;
}
void remove_sorted_duplicates()
{
    struct node *previous = NULL, *current = head;
    while (current)
    {

        if (previous->data == current->data)
        {
            previous->next = current->next;
            if (current == last)
                last = previous;
            delete current;
            current = previous->next;
        }
        previous = current;
        current = current->next;
    }
    // this also works when the linked list is sorted only 
}
void reverse1()
{
    // there are 2 ways to reverse the linked list
    // 1.first copy all the elements of the linked list into array and then reverse copy the array elements into the linked list
    // 2.reverse the links
    vector<int> arr;
    struct node *temp = head;
    while (temp)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    int i = arr.size() - 1;
    while (temp)
    {
        temp->data = arr[i--];
        temp = temp->next;
    }
    // time complexity is O(2N) or linear
    // space complexity is O(N)
}
void reverse2()
{
    // for this we use the three pointers which are followed by each other
    // i.e first is followed by second and second is followed by third
    // these pointers are known as sliding pointers as in each step they move further ,in each step apart from moving they reverse a link
    struct node *third = NULL, *second = NULL, *first = head;
    while (first)
    {
        third = second; //first three lines is for sliding
        second = first;
        first = first->next;
        second->next = third; //this for reversing the link that mean connecting the second link to third link
    }
    // at last the first pointer becomes the null and the second pointer points to the last node so it should be the head now
    last = head;
    head = second;

    // ----------comparision-------------
    // Among these two methods the second method is best,because there may be situation that the node consists of huge data i.e node ccan be a structure so copying these much data takes lot of amount of space but in the second case we are using only the pointers which takes less amount of memory
}
int main()

{
    

    return 0;
} 
