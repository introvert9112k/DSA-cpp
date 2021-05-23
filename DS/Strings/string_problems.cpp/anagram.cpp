// problem statement 
// given two strings find whether the two strings are anagram or not 

// two strings are said to be anagram if second string is obtained by 
// interchanging the characters of the first string /

// we define two functions to check the strings with duplicats and strings withouf duplicates 

// we use the hashing  to find whetehr the two strings are anagram are not 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string unique_anagram(string &sai,string &sri)
{    
   
    if(sai.length()!=sri.length())
        return "not anagram";
    int array[26] = {0};
    for (int i = 0; i < sai.length(); i++)
        array[sai[i] - 97]++;
    for (int j = 0; j < sri.length(); j++)
       {
           array[sri[j] - 97]--;
           if(array[sri[j]-97] < 0)
               return "not anagram";
       }
       return "anagram";
} 
// string duplicate_anagram() 
int main()  

{
    string sai, sri;
    cin >> sai >> sri;
   cout<< unique_anagram(sai, sri); 

    return 0;

}
