// in this we will implement upper_bound and lower_bound using binary search
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
int lower_bound1(int *arr, int n, int target)
{
    int low = 0, high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low <= high ? mid : -1;
}
int upper_bound1(int *arr, int n, int target)
{
    int low = 0, high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (arr[mid] == target)
            return mid != n - 1 ? mid + 1 : -1;
        else if (arr[mid] < target)
        {
            if (mid != (n - 1))
                low = mid + 1;
            else
                return -1;
        }
        else
            high = mid - 1;
    } 
    return high + 1;
} 
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

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
            cin >>
        arr[i];
    int target;
    cin >> target;

    // ------lower_bound code-----------

    int res = lower_bound1(arr,n,target);
    if(arr[res] == target)
        cout << "the target is present in array" << endl;
    else if(res == -1)
        cout << "there is no elemet that is greater than the target in the array : " << endl;
    else
        cout << "target is not present ,and next greater element than target is : " << arr[res] << endl;

    // ------------upper_bound code-----------
    
    int res2 = upper_bound1(arr, n, target);
    if (res2 == -1)
        cout << "there is no upper bound for target" << endl;
    else
        cout << "the upper bound of the target is : " << arr[res2] << endl;

    return 0;
} 