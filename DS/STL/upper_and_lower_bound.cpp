// in this we will look at the lower bound and uppper bound 
// lower and upper bound functions are defined in the stl and are applied only on the sorted containers 
// they can be applied on the arrays,vectors,sets,maps etc
//   -----------lower bound------------
#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vii vector<pair<int,int>>
#define si stack<int> 
#define li list<int> 
#define endl  "\n"  
#define pi pair<int,int> 
#define scan(h) scanf("%lld",&h)
#define st(g,h) scanf("%lld %lld",&g,&h) 
#define print(g) printf("%lld",g) 
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


int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
            cin >>
        arr[i];
    sort(arr, arr + n);
    int target;
    cin >> target;
    int* lower = lower_bound(arr, arr + n, target);
    // lower bound takes 3 argumetns ,first starting iterator,ending iterator,and the value we want to search 

    // if the target value is present in the container then lower bound will return the iterator pointing to it,in case of array it returns the pointer to the location of target 

    // if target is not present in contaier then it will return the iterator of the first elemenet that is greater than the target,if there are no elements that are greater than the target then it will return the end() iterator ,in case of array it returns pointer to address arr +n
    if(lower == arr +n )
        cout << "there is no element greater than the target element"<<endl;
    else if (*(lower) == target)
        cout << "the target element is present in the array" << endl;
    else
        cout << "the target element is not present and next greater element after target is : " << *(lower) << endl;
     
    //  Time complexity 
    // Time complexity of the lower_bound and upper_bound is logN as they internally use the binary search.In case of vectors and arrays it is logN in case of sets and maps it is O(N) 
    // because sets and map internallys uses trees on which binary search cannnot be applied 

    // ------------Upper bound-----------
    // If target element present or not upper bound will return the iterator of the first greatest element than target 
    // If any other value is not greater than the target it returns end()
    int *upper = upper_bound(arr, arr + n, target);
    if(upper == arr +n)
        cout << "there is no element greater than the target element in array " << endl;
    else
        cout << "the next greater element than the target is : " << *upper << endl;
    
    // Similar for the vectors ,sets,maps
    // in case of sets and maps use map_object.lower_bound or set_object.upper_bound
    // they would work fine compared to lower_bound(map.begin(),map.end(),target)
    return 0;
}  