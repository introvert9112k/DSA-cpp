#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string brute_force(int a)
{
  if (a % 2 == 0)
    return "even";
  else
    return "odd";
}

string optimised_way(int a)
{
  if (a & 1) 
    return "odd";
  else
    return "even";  
}

int main()

{
  //  in this we will find the optimised way for finding the given number is odd or even
  // let us implement the brute force way for finding the odd and even
  int a;
  cin >> a;
  // string res1 = brute_force(a);
  // cout << res1 << endl;

  // in brute force way the modulo takes some time for calculating the remainder in case of large numbers
  // this can be overcome by using the bits technique to find whether the number is odd or even

  // the binary of a every odd number ends with 1
  // and the binary of a every even number ends with 0

  // suppose if we perform bitwise and operation on number with 1 then we will get the last digit in binary,so if we check the last digit if it is 1 then it is odd if it is 0 then it is even

  // let us implement that
  string res2 = optimised_way(a);
  cout<< res2 <<endl;

  return 0;
}