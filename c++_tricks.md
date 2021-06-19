**fastest way to find even or add**
given an number if(num&1) is true then it is odd else it is even
if(num&1)
cout<<"odd" <<endl;
else
cout<<"even" <<endl;

**power of 2**
given an num fastest way to check whether it is power of 2 or not is
**!(num & (num - 1))** if this holds true then num is power of 2 else not.
this does not works for 0,so for expression **num & !(num & (num-1))** holds true for all cases

**fastest way to calculate the 2 power**
let us calculate the 2 power i, ex: 2 power 5
fastest way to calculate right shift the 1 ,i number of times i.e **1<<i**

**find negative among numbers**
supppose there are two numbers we want to find whether any one of the number among them is negative
this can be done by using expression **(num1 < 0 ) ^ (num2 < 0)**
if both conditons are true or false ,then xor becomes zero,if anyone of the conditon is true then xor becomes true,hence we can check whether any of the number is negative.

**string of length n**
No of subsequences are **2^n**
No of substrings are **(n\*(n+1))/2**
No of subsets(order does not matter) **2^n**

**xor properties**
xor of any number with itself is zero (x^x = 0)
xor with zero is number itself (x^0=x)
x^y^z = x^z^y= y^x^z xor is associative and commutative,xor can be appllied in any order
any order gives same ansewer.

**rsbm(right set bit mass)**
right set bit mean the position of the last set bit in binary or(first set bit postion from right)
ex: 19 = 10011 in this rsb is the last bit i.e position 0
right set bit mass of 19 is 00001,i.e except the rsb position all the bits are unset
rsbm can be calculated by performing and operation on num and its 2's complement
2's complement can be obtaine by (~num + 1) i.e 1's complement + 1
rsbm = num & (~num + 1)
~num + 1 = -num
so
rsbm = num & -num

**return an array**
if a function returns an array then array must be declared as static because the c++ does not allow to return the address of the local variable

**Segmentation errors / abnormal program termination**
possible reasons for segmentation errors
1.not declaring array as static in function which returns an array
2.Acessing the outof index in array
3.Accessing the memory that is already freed or has no reference to it (i.e Null pointers)
4.improper use of scanf ,like not specifying address to store (ex: scanf("%d",n))
5.stackoverflow (using all the stack memory) this occurs when there is no base condition to recursive call
6.dereferencing the pointer which is not intialised
