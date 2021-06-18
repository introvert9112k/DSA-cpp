
#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vii vector<pair<int, int>>
#define si stack<int>
#define li list<int>
#define endl "\n"
#define pi pair<int, int>
#define scan(h) scanf("%lld", &h)
#define st(g, h) scanf("%lld %lld", &g, &h)
#define print(g) printf("%lld", g)
#define deb(x) cout << #x << " = " << x << endl;
#define fo(i, n) for (int i = 0; i < n; i++)
#define fok(i, k, n) for (int i = k; i >= n; i--)

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}
int power(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = result * a;
        a = a * a;
        b = b >> 1;
    }
    return result;
}
string binary(int num)
{
    string ans = "";
    while (num != 0)
    {
        ans += to_string(num % 2);
        num = num / 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
void check_set_bit(int num, int position)
{
    //    Algorthim
    //    first left shift the 1 until the position  and with the number ,then if the bit is set we get non zero ,if the bit is unset then we will get zero
    binary(num);
    if (num & (1 << position))
        cout << "set bit" << endl;
    else
        cout << "unset bit" << endl;
}
void make_bit_to_set(int &num, int position)
{
    // Approach
    // for the given position make the bit to set
    // this can be done by performing or with the 1 left shifted that many  positions
    cout<<binary(num)<<endl;
    cout<< binary(num | (1 << position))<<endl;
    
} 
void make_bit_to_unset(int &num, int position)
{
    // Approach
    // first take the not of the 1<<position ,after that  and with the number
    cout<<binary(num)<<endl;
    cout<< binary(num &(~(1 << position))) <<endl;
    
}
void toggle_bit(int &num, int position)
{
    // problem statemtent
    // for the given bit if it is set convert into unset and vice versa
    // xor the number with the 1<<position , inorder to toggle the bit
    cout<<binary(num)<<endl;
   cout<< binary(num ^ (1 << position))<<endl;
   
} 
void count_bits(int num)
{  
    // count bits is nothing but the no of set bits in the binary 
    int count = 0;
    for (int i = 0; i<=31; i++)
      if(num & (1<<i))
          count++;
    print(count);
} 
int32_t main()
{

    // int num;
    // cin >> num;
    // int position;
    // cin >> position;
    // count_bits(num);
    cout << stoi("23") << endl;

    return 0;
} 