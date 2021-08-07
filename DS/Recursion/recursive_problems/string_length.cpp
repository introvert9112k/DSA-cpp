// problem statement 
// find the length of the string recursively
#include<bits/stdc++.h>
using namespace std;
int length(string str,int i)
{
    int x;
    if(str[i] == '\0')
        return i;
    x = length(str, i + 1);
    return x;
} 
int main()
{
    string str;
    cin >> str;
    cout << "the length of the string is : " << length(str,0) << endl;
} 