// problem statement
// find the middle node or middle element of the linked list

// there are three ways to find it lets see all of them
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;
int method1(list<int> &l)
{
    // / 1st way /
    // find the mid node of the list and scan through the list until the middle node is reached and return the middle node or middle element
    int mid = l.size() / 2;
    // cout << "middle value is : " <<
    list<int>::iterator itr = l.begin();
    while (mid--)
        itr++;
    return *itr;

    // Time Complexity
    // finding the  length takes O(N) time complexity and scan until the middle element takes O(N)
    // totally it is linear
}
int method2(list<int> &l)
{
    // first scan through the entire list and store the addressess of the node in the stack and pop the nodes until the mid element and return the value at address at the top of the stack
    list<int>::iterator itr;
    stack<list<int>::iterator> s;
    for (itr = l.begin(); itr != l.end(); itr++)
        s.push(itr);
    int mid = l.size() / 2;
    while (mid--)
        s.pop();
    return *(s.top());
    // time complexity is same as the method1 as we are finding the length and iterating mid times
    // but space complexity is O(N) as we are using stack
}
int method3(list<int> &l)
{
    // this is efficent method
    // this is done by using the slow and faster pointer technique
    // in slow and faster pointer technique one pointer move one step at a time and other moves two steps at a time
    list<int>::iterator itr1 = l.begin(), itr2 = l.begin();
    // itr1,and itr2 both points to the first node of the list,itr1 moves by one step and itr2 moves by two steps
    while (itr2 != l.end())
    {
        itr2++;
        if (itr2 != l.end())
            itr1++;
        if (itr2 != l.end())
            itr2++;
    }
    return *itr1;
    // the time complexity is O(N) as we are scannig only once through the list and constant space complexity 
}
int main()

{

    list<int> l;
    for (int i = 0; i < 9; i++)
        l.push_back(i);
    int mid_value1 = method1(l);
    int mid_value2 = method2(l);
    int mid_value3 = method3(l);
    cout << mid_value3 << endl;
    return 0;
}  