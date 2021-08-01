// let us look at the navier search algorthim to find out the pattern 
// Problem statement 
// given a string A and string 
// we want to find string B is substring of string A or not /
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int navier_search(string &parent,string &child) 
{
    int count = 0;
    int c_len = child.length();
    int p_len = parent.length();
    if(c_len > p_len)
        return -1;
    for (int i = 0; i < (p_len - c_len + 1); i++) //traversing through the parent string
    {
        if(parent[i] == child[0]) //if first character matched
        {
            for (int j = 0; j < c_len; j++) //check for all the other characters
              {
                  if(parent[i+j] != child[j]) //if character does not match come out of the loop
                      break;
                  count++;
              }
            if(count == c_len) //checking if count is equal to length of the child string
                return i;
            count = 0;
        }
    }
    return -1;
}  

int main() 

{
    string parent, child;
    cin >> parent;
    cin >> child;
    int ans = navier_search(parent, child);
    ans >= 0 ? (cout << "string found at index " << ans << endl) : (cout << "string not found" << endl);
    return 0;
} 