
#include <bits/stdc++.h>
using namespace std;

void is_sorted()
{
   //    **2.is_sorted function**
   // this is used to check whether the container is sorted or not.
   // this is used to check whether the elements in the given range is sorted in ascending order or not
   // It takes two parmeters start and end indexes of the range.
   // Returns true if elements in range is sorted else return false.
   // we can also pass the compartor for uncoventional comparing
   vector<int> arr = {1, 2, 3, 4};
   cout << is_sorted(arr.begin(), arr.end());

   // Time complexity is linear
}
void arrayprinting()
{
   // *printing array element and after end of line **

   vector<int> arr = {1, 2, 3};
   for (int i = 0; i < arr.size(); i++)
      cout << arr[i] << "\n"[i + 1 == arr.size()];

   // here by conventially we don't write the cout<<endl after the for loop,when i+1 == arr.size() is true then "\n" is printed,in remaining cases it is not printed/
}
int main()

{

   // 1.Ternary operator with cout
   cout << ("this can be any expression" ? 0 : 1) << endl;
   arrayprinting();
   return 0;
}
