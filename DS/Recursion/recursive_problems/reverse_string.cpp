#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void reverse(string &s,int i, int mid, int len)
{
    if(i == mid)
        return;
    swap(s[i], s[len - i - 1]);
    return reverse(s, i + 1, mid, len);
}
int main() 

{
    string s;
    cin >> s;
    int mid = s.length() >> 1;
    reverse(s, 0, mid, s.length());
    cout << s << endl;
    return 0;

} 