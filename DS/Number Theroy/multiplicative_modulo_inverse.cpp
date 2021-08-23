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
// In this we will look at the multioplicate modulo inverse for a given number and modulo
// let (A*B)%m = 1
// here b is the multiplicative modulo inverse of the combination A and M
// mmi mean the number that should be multiped with the given number to get the modulo equal to 1,mmi may not be unique,many numbers of values are possible for mmi for given combination of a and m
// if A*B = 1 then we get 1 upon doing modulo
// so A*B -1 =0 we get 0 when number is multiple of modulo
// so A*B-1 = mQ upon rearranging A*B + m*Q = 1
// A*B + m*Q = 1 this equation looks like ax + by = gcd(a,b) upon comparing both equations we get x as multiplicative modulo inverse of a and m
// so let us find the mmi using the extended euclid algorthim

// **************NOTE*****************************
// mmi exists only when the A and m are coprimes ,i.e there gcd is 1

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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
struct triplet
{
    int x, y, gcd;
};
triplet extendedeuclid(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = 1;
        return ans;
    }
    triplet temp = extendedeuclid(b, a % b);
    triplet final_ans;
    final_ans.x = temp.y;
    final_ans.y = temp.x - (a / b) * temp.y;
    final_ans.gcd = temp.gcd;
    return final_ans;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    int a, m;
    cin >> a >> m;
    if (gcd(a, m) != 1)
    {
        cout << a << " and " << m << " are not coprimes " << endl;
        exit(0);
    }
    triplet ans = extendedeuclid(a, m);
    // make sure that the a and m are coprimes
    cout << "mulitplicative modulo inverse of " << a << " and " << m << " is " << ans.x << endl;
    return 0;
} 