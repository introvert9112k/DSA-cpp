// in this we will  convert decimal to any base system
// decimal is the number which has base 10.the numbers like 12,23,345 are decimal numbers,that mean the numbers that we use generally is decimal number 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string decimal_to_any_base(int decimal, int base) 
{
    int reminder;
    string binary="";
    while (decimal!=0)
    {
      reminder = decimal%base;
      decimal = decimal/base;
      if(reminder < 10)
      binary = binary + to_string(reminder);  
      else 
      binary = binary + char(int('A') + reminder-10);
    } 

    reverse(binary.begin(), binary.end());
    return binary;
} 
int main() 

{       
        int decimal,base;
         cout<< "enter the decimal number "<<endl;
         cin >> decimal;
         cout<< "enter the base: "<<endl;
         cin>>base;
         string result = decimal_to_any_base(decimal,base);
         cout<< result <<endl;

          return 0;

} 

// this is the code for conversion of decimal to any base,if the base is 2 then we are converting the decimal to binary, if base is 8 we are converting to octal, if base is 16 we are converting to hexa decimal 