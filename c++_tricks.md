**fastest way to find even or add** 
given an number if(num&1) is true then it is odd else it is even 
if(num&1) 
 cout<<"odd" <<endl;
else 
 cout<<"even" <<endl;

 **power of 2** 
 given an num fastest way to check whether it is power of  2 or not is 
 **!(num & (num - 1))**  if this holds true then num is power of 2 else not. 
 this does not works for 0,so for expression **num & !(num & (num-1))** holds true for all cases  

 **fastest way to calculate the 2 power** 
 let us calculate the 2 power i, ex: 2 power 5 
 fastest way to calculate right shift the 1 ,i number of times i.e **1<<i**

 **find negative among numbers**
 supppose there are two numbers we want to find whether any one of the number among them is negative 
 this can be done by using expression **(num1 < 0 ) ^ (num2 < 0)** 
 if both conditons are true or false ,then xor becomes zero,if anyone of the conditon is true then xor becomes true,hence we can check whether any of the number is negative.
