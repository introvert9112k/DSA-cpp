// in this we will compare the two stirings and say wheteher they are equal or not if not equal which string comes first
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string compare(string &string1, string &string2)

{
    static int i;
    if (string1.length() != string2.length())
        return "not equal";
    for (i=0; i < string1.length(); i++)

        if (string1[i] != string2[i])
            break; 
    if(i == string1.length())
        return "equal";
    else if (string1[i] < string2[i])
        return "smaller";
    else
        return "greater";
} 
int main()

{
    string string1, string2;
    cin >> string1 >> string2;
    cout<<compare(string1, string2);

    return 0;
} 