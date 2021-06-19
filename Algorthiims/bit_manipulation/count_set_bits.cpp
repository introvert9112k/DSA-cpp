// problem statement 
// given an number we should count the number of set bits in number 

// Approach 
// This can be done in two ways 
// 1.binomial exponentation method 
// 2.kanehis Algorthim 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void binomial_set_count(int num)
{
    int count = 0;
    while(num > 0)
    {
        if(num & 1)
            count++;
        num = num >> 1;
    }
    cout << "set bits count is :  " << count << endl;
    // Time complexity is O(logN)
    // in this we are traversing throught the binary number,what if we jump to the position where the bit set
    // this can be appraoched using the kanhenis Algorthim 
} 
void kanehis_algorthim(int num)
{
    int count = 0;
    while(num!=0)
    {
        int rsbm = num & -num;
        num = num - rsbm;
        count++;
    }
    cout << "the set bit count is : " << count << endl;
} 
// Working /
// let us consider 19 
// 19 = 10011
// our aim is to jump to 1 one after one 
// so ,first find the rsbm(right set bit mass) of number ,make take the count variable for counting set bit
// rsbm of 19 is 00001
// let subtract this from number so 10011-00001=10010
// now update the num with num-rsbm 
// so num = 10010
// now again find rsbm so rsbm is 00010
// num = 10010-00010=10000 increment count after updation 
// This time rsbm is 10000
// num = 10000 - 10000 =0 
// so in this way repeat until the num becomes zero.the value of count will be set bit count 

// In this Algorthim we directly jumping to the set bits positions so it is better than traversing the whole binary 

int main() 

{

    int num;
    cin >> num;
    // binomial_set_count(num);
    kanehis_algorthim(num);

    return 0;

} 