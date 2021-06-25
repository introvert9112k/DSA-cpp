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
vector<int> v; //global vector for storing the indexes for the first_occurence and last_occurence classes

vector<int> first_last_occurence(int *arr, int n, int k)
{
    vector<int> v1;
    int i = 0, j = n - 1;
    int flag1 = 1, flag2 = 1;
    while (i <= j)
    {
        if ((arr[i] == k) and flag1)
        {
            v1.push_back(i);
            flag1 = 0;
        }
        if ((arr[j] == k) and flag2)
        {
            v1.push_back(j);
            flag2 = 0;
        }
        i++;
        j--;
    }
    if (flag1 == 1)
    {
        v.push_back(-1);
        v.push_back(-1);
    }
    return v1;
    // Time complexity O(N)
    // Space O(1)
}

// class for finding the first occurence
class first_occurence_class
{
public:
    int *arr;
    int n;
    int target;
  

public:
    first_occurence_class(int *arr1, int n1, int target1)
    {
        arr = arr1;
        n = n1;
        target = target1;
       
    } 
    // function to check whether the found index is first position or not
    string first_occurence(int mid)
    {
        if (arr[mid] == target)
        {
            if ((mid == 0) or ((mid >= 1) and (arr[mid - 1] != arr[mid])))
                return "found";
            else if ((mid >= 1) and (arr[mid - 1] == arr[mid]))
                return "left";
        }
        else if (arr[mid] < target)
            return "right";

        return "left";
    }
    // binary search
    void binarysearch()
    {
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            string res = first_occurence(mid);
            if (res == "found")
            {
                v.push_back(mid);
                return;
            }
            else if (res == "left")
                high = mid - 1;
            else
                low = mid + 1;
        }
        v.push_back(-1);
    }
};

class last_occurence_class
{
public:
    int *arr;
    int n;
    int target;
    

public:
   last_occurence_class(int *arr1, int n1, int target1)
    {
        arr = arr1;
        n = n1;
        target = target1;
        
    }
//    fucntion to find the last occurence of the value 
    string last_occurence(int mid)
    {
        if (arr[mid] == target)
        {
            if ((mid == n-1) or ((mid <= n-2) and (arr[mid + 1] != arr[mid])))
                return "found";
            else if ((mid <= n-2) and (arr[mid + 1] == arr[mid]))
                return "right";
        } 
        else if (arr[mid] < target)
            return "right";

        return "left";
    } 
    // binary search
    void binarysearch()
    {
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            string res = last_occurence(mid);
            if (res == "found")
            {
                v.push_back(mid);
                return;
            }
            else if (res == "left")
                high = mid - 1;
            else
                low = mid + 1;
        }
        v.push_back(-1);
    }
}; 

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
    
    first_occurence_class first(arr, n, target);
    first.binarysearch();

    last_occurence_class last(arr, n, target);
    last.binarysearch();
    
    for (auto x : v)
        cout << x << " ";

    return 0;
} 