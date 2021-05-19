// in this we will look at the fibonanci series calculation 

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
int iterative_fibonanaci(int n)
{   
    if(n<=1 )
        return n;
    int temp1 = 1, temp2 = 1, sum = 0;
    for (int i = 2; i < n; i++)
     {
         sum = temp1 + temp2;
         temp1 = temp2;
         temp2 = sum;
     }
     return sum;
} 
// the time complexity of this iterative approach is O(N) 

int re_fibonanci(int n)
{

return n<=1 ? n : re_fibonanci(n - 2) + re_fibonanci(n - 1);

}  
// Approximate time complexity of this recursive approach is O(2^n) 
// which is worst 
// if we observe the recursive tree of the function we will notice that we are calculating the same value multiple times ,what if we can calculate that value single time and use it in  futher calls 

// this is example of memotization or dynamic programming 
// let us optimise the recursive approach and make its time complexity to linear 

int optimised_fibonanci(vector<int> &array,int n)

{
       if(n<=1)
          {  array[n] = n;
              return n;
          } 
       else{

                if(array[n-2]==-1)
                    array[n - 2] = optimised_fibonanci(array, n - 2);
                if(array[n-1] == -1)
                    array[n - 1] = optimised_fibonanci(array, n - 1);
                array[n] = array[n - 2] + array[n - 1];
                
       } 
                return array[n];  
} 
// time complexity of this optimised_recursion is linear 

int main() 

{
    int n;
   cin >> n;
   cout<<"recursive approach result is :  " << re_fibonanci(n)<< endl;
   cout << "iterative approach result is :  "<< iterative_fibonanaci(n) << endl;
   vector<int> array;
   array.reserve(n);
   for (int i = 0; i < array.capacity(); i++) 
   {
       array.push_back(-1);
   } 
 
   cout<<"optimised recursion approach result is :   " << optimised_fibonanci(array, n)<<endl;
   cout<< "the fibonanci sequence is : " <<endl;
   for (int i = 1; i < array.size(); i++)
       cout<< array[i] <<endl;
       return 0; 
   
}  