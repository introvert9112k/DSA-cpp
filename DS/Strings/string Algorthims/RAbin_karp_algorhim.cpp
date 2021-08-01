#include<iostream>
#include<string>
#include<algorithm>
#define int long long
using namespace std;

int power(int a,int b)
{
    int res = 1;
    while(b>0)
    {
        if(b&1)
            res = res * a;
        a = a * a;
        b = b >> 1;
    }
    return res;
} 
int calculatehash(string temp,int len)
{
    int hash = 0;
    int constant = 3;
    for (int i = 0; i < len; i++)
        hash = hash + (temp[i] - 'a') * power(constant, i);
    return hash;
} 
int updatehash(string &parent,int p_hash,int len,int st)
{
    int constant = 3;
    return p_hash/constant + (parent[st + len - 1] - 'a') * power(constant, len - 1) - ((parent[st - 1] - 'a') * power(constant, 0))/constant;
} 
bool checking(string parent,string child,int len,int st)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if(parent[st+i] != child[i])
            return false;
        count++;
    }
    return count == len ? true : false;
}

int rabin_karp(string &parent, string &child)
{
    int p_len = parent.length();
    int c_len = child.length();
    if(c_len > p_len)
        return -1;
    int p_hash = calculatehash(parent, c_len);
    int c_hash = calculatehash(child, c_len);
    if(c_hash == p_hash)
        return 0;
    for (int i = 1; i < (p_len - c_len + 1); i++)
    {
        p_hash = updatehash(parent, p_hash, c_len, i);
        if(p_hash == c_hash && checking(parent,child,c_len,i))
             return i;
    } 
    return -1;
} 

int32_t main() 

{
    string parent, child;
    cin >> parent;
    cin >> child;
    int ans = rabin_karp(parent, child);
    ans >= 0 ? (cout << "string found at index: " << ans << endl) : (cout << "string not found" << endl);
    return 0;

}