// problem statemtent
// given an array print the all subsequences of the array
#include<bits/stdc++.h>
#define int long long
using namespace std;
// for finding the subsequence ,for every element we have two options whether including it or excluding it
// so no of subsequences formed are 2*N
// so time complexity is also 2*N and auxilary space is O(N)

void subsequence(int *arr,int n, vector<int> &ans,int ind)
{  
    // base case,whenever ind reached to n,there are no more elements to include or exclude 
    if(ind == n )
    {
       for(auto it: ans)
           cout << it << " ";
       cout << endl;
       return;
    }
    // this is the case where we include the number
    ans.push_back(arr[ind]);
    // taking the number into considertaion,and adding it to our data structure,and increasing the index
    subsequence(arr, n, ans, ind + 1);
    // here we are not including the number,and increasing the index
    ans.pop_back();
    subsequence(arr, n, ans, ind+1);
    // tc - O(2*n)
    // sc o(n)
}  
int power(int a, int b)
{
    int result = 1;
    while(b >0)
    {
        if(b&1)
            result = result * a;
        a = a * a;
        b = b >> 1;
    }
    return result;
} 
// finding subsequences using the bit masking
vector<int> subsequencebit(int *arr, int value)
{
    vector<int> ans;
    int cnt = 0;
    while(value > 0)
    {
        if(value & 1)
            ans.push_back(arr[cnt]);
        cnt++;
        value = value >> 1;
    }
    return ans;
    // tc = O((2^n)*length of array)
} 
// better version of bit masking using the kahane's algorthim
vector<int> subsequencebit2(int *arr, int value)
{
    vector<int> ans;
    int rsbm, pos;
    while(value > 0)
    {
        rsbm = value & -value; //finding the right most significant bit mask
        pos = log2(rsbm); //finding the position of the msb in the rsbm
        ans.push_back(arr[pos]); //pushing correponding value from array into vector
        value = value - rsbm; // unsetting the right most set bit,for finding the other set bits
    } 
    return ans;
} 

int32_t main() 
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
   
    // --------for recursive subsequence--------------
    // vector<int> ans;
    // subsequence(arr, n, ans,0);
  
    // ------------------for bit masking subsequences----------------
    int len = power(2, n);
    vector<int> ans;
    for (int i = 0; i < len; i++)
    {
        ans = subsequencebit2(arr, i);
        for(auto it : ans)
            cout << it << " ";
        cout << endl;
    } 

        return 0;

}  