// in this we will look at the vector of vectors
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
void print_vector_of_vector(vector<vector<int>> &v)

{
    cout << "the elements in the vector of vector are:" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        fo(j,v[i].size())
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
} 
int32_t main() 
{

    // syntax for declaring the vector of vectors
    vector<vector<int>> v;
    // we know that the intially there would be no memory allocated for the vector unlike the array
    // so without intilaising the vector we could not acess it using the indexing like v[i] etc
    // let us consider intially the size of the vector be n
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // as we do not intailaised the vector ,so vector is nothing now,we want to push back the vectors into v as elements so first we should create a vector and push it into the vector v
        vector<int> temp;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int value;
            cin >> value;
            temp.push_back(value);
        }
        v.push_back(temp);
    }
    print_vector_of_vector(v);

    // -----------Difference between the vector array and vector of vectors----------------
    //  In vector array the rows are fixed as the array is static,and each row can have different columns as the elements of array vectors ,which can expand dynamically

    // In vector of vectors both the rows an columns are dynamic.so we can insert a new vector into the mother vector or we can increase elements in any other child vectors.
    return 0;
} 