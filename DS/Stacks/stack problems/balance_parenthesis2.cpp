// problem statement 
// given an string which  contains square brackets,flower brackets,circular brackets our task is to find whether the opening bracket of particular type has the closing bracket of the same type before encountering the closing bracket of another type 

// ex { [ ( a+ b)]} 
// in this example  first there is flower bracket and second is square and third is circular bracket,we can see that the for the last circular bracket we found the first circular closinb bracket and second opening square bracket we found second closing square bracket and third opening flower bracket we found third closing bracket of flower type 

// so we should say whether string is balanced likes this or not

// Ascii code of brackets 
// 40 (
// 41 ) 
// 91 [ 
// 93 ]
// 123 {
// 125 } 

#include<iostream>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;
void parenthesis_balance(string s)
{
    stack<char> k;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] =='{' or s[i]=='[' or s[i] =='(')
            k.push(s[i]);
        else if(s[i]=='}' or s[i] == ']' or s[i] ==')')
        {
            if(!k.empty())
            {
               char x = k.top();
               k.pop();
               if(s[i]<50)
               {
                  if(x+1 == s[i])
                      continue;
                  else 
                  {
                      cout << "not balanced" << endl;
                      return;
                  }    
               }
               else
               {
                    if(x+2 == s[i])
                        continue;
                    else 
                    {
                        cout << "not balanced" << endl;
                        return;
                    }
               }
            }
            else
            {
                cout << "not balanced" << endl;
                return;
            }
        }    
    }
    if(k.empty())
        return true;
    else
        return false;
} 
int main() 

{
    string s;
    cin >> s;
    parenthesis_balance(s);

    return 0;

} 