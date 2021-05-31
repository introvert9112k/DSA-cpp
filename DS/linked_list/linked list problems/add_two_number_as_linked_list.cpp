// problem statement 
// You have been given two singly Linked Lists, where each of them represents a positive number without any leading zeros.
// Your task is to add these two numbers and print the summation in the form of a linked list.
// Example:
// If the first linked list is 1 -> 2 -> 3 -> 4 -> 5 -> NULL and the second linked list is 4 -> 5 -> NULL.

// The two numbers represented by these two lists are 12345 and 45, respectively. So, adding these two numbers gives 12390. 

// So, the linked list representation of this number is 1 -> 2 -> 3 -> 9 -> 0 -> NULL.

#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;
void add(list<int> &l1, list<int> &l2)
{
    list<int> l3;
    string s1 = "";
    string s2 = "";
    list<int>::iterator itr;
    for (itr = l1.begin(); itr != l1.end(); itr++)
        s1 += to_string(*itr);
    for (itr = l2.begin(); itr != l2.end(); itr++)
        s2 += to_string(*itr);
    int num = stoi(s1) + stoi(s2);
    while (num != 0)
    {
        int rem = num % 10;
        num = num / 10;
        l3.push_back(rem);
    }
    reverse(l3.begin(), l3.end());
    for (auto x : l3)
        cout << x << " ";
    cout << endl;
}  
int main()

{
    int t;
    cin >> t;
    while (t--)
    {
        list<int> l1;
        list<int> l2;
        int y, x;
        cin >> x;
        while (x != -1)
        {
            l1.push_back(x);
            cin >> x;
        }
        cin >> y;
        while (y != -1)
        {
            l2.push_back(y);
            cin >> y;
        }
        add(l1, l2); 
    } 
    return 0;
} 