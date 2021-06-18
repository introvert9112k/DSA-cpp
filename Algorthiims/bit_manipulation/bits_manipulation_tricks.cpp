// in this we will look at 6 binary manipulatin tricks
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
void trick1(int num)
{
    // checking even or odd
    num & 1 ? (cout << "odd" << endl) : (cout << "even" << endl);
}
void trick2(int num)
{
    // dividing the num by 2 and multiplying the number by 2
    // if we want multipy the number by 2 then right shift the number 1 time
    // if you want to divide the number by 2,then left shift the number 1 time
    cout << "the number obtained after dividing the number by 2 is : " << (num >> 1) << endl;
    cout << "the number obtained after multiplying the number by 2 is : " << (num << 1) << endl;
}
void trick3(char ch='A')
{
    // if we want to convert the Captial to small then or the capital with the white space i.e Capital | ' '
    // ex: a = 'A' | ' '
    // if you want to convert Small letter to capitla then and with the underscore 
    // ex: A = 'a' & '_'
    cout << "the Capital letter of the alaphbet is : " << char((ch | ' ')) << endl;

} 
void trick4(int num)
{
    // checking whether number is power of 2 or not
    num and !(num & (num - 1)) ? (cout << "YEs" << endl) : (cout << "NO" << endl);
} 
void trick5(int num,int i)
{
//   make all the bits from to i unset
//    suppose the number is 101101 
//    let i be 3,so we want make the bits from 1 to 3 unset,if we make it then num becomes 100000 
//    to make that we want to and the number with 111000 so 100101 & 111000 = 100000
//    so 111000 can be obtained by ~(000111) 000111 can be obtained by (10000-1) 
//    so 110000 can be obtained by ~((1<<(i+1))-1) 

//    so the final expression is num & ~((1<<(i+1))-1)
    cout << (num & ~((1 << (i + 1)) - 1)) << endl;
}  
void trick6(int num,int i)
{
    // make bits after the i to unset
}
int32_t main()
{
    int num;
    cin >> num;
    // trick2(num);
    // trick3();
    trick4(num);

    return 0;
} 