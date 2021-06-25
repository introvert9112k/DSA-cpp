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
void approach1(int *arr, int n, int k)
{
    unordered_set<pair<int, int>> set;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] + arr[j]) == k)
            {
                if (set.find({arr[j], arr[i]}) == set.end())
                    set.insert({arr[i], arr[j]});
            }
        }
    }
    unordered_set<pair<int, int>>::iterator it;
    for (it = set.begin(); it != set.end(); it++)
        cout << (*it).first << " "(*it).second << endl;
}
void approach2(int *arr, int n, int k)
{
    unordered_set<pair<int, int>> set;
    int num = n << 1;
    int left = 0, right = 0;
    while (num--)
    {
        if ((arr[right] + arr[left] == k))
        {
            if (abs(right - left) == 1)
            {

                if (set.find({arr[right], arr[left]}) == set.end())
                {
                    set.insert({arr[left], arr[right]});
                    right++;
                }
            }
            else
                left++;
        }
        else if (sum < k)
            sum = sum + arr[++right];
        else
            sum = sum - arr[left++];
    }
}
void unique_pair(int *arr,int n,int k)
{
    vector<pair<int, int>> v;
    sort(arr, arr + n);
    int left = 0, right = n - 1;
    while(left < right)
    {
        if( left >=1 and (arr[left-1] == arr[left]))
        {
            left++;
            continue;
        }
        else if( (arr[left] + arr[right]) == k)
       {
           v.push_back({arr[left], arr[right]});
           left++;
           right--;
       }
       else if( (arr[left] + arr[right]) > k)
           right--;
       else
           left++;
    }
} 
int32_t main()
{

    int n, k;
    cin >> n;
    int arr[n];
    fo(i, n)
            cin >>
        arr[i];
    cin >> k;
    approach1(arr, n, k);

    return 0;
}