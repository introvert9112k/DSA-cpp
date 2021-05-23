// problem staement 
// check whether the string is palindrome or not 
// we approach this problem by two pointer approach 

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string palindrome(string &sai)
{
    for (int i = 0, j = sai.length() - 1; i < j; i++,j--)
       if(sai[i]!=sai[j])
           return "not palindrome";
    return "palindrome";
} 
// time complexity is O(N/2) or linear 
int main() 

{
    string sai;
    cin >> sai;
     cout<< palindrome(sai) <<endl;
    return 0;

}