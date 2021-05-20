// #array are continous memory blocks
// syntax for declaring the array is data type array_name[array_size] 
// array contain the same data type values 

#include<iostream>

using namespace std;

int main() 

{
       int array[] ={1,2,3,4,5,5,'s'}; 
       for (int i = 0; i < 8; i++)
       {  
          cout<<array[i]<<endl; 
       } 

    //    array is nothing to pointers 
    // acessing the array elements using the pointers 
    cout<<"acessing the array values using the pointers" << endl;
    for (int i = 0; i < 6; i++)
    {
        /* code */
        cout << *(array+i) <<endl;
    } 

    // flaoting arrray
    // as the array is of float type is so for the 's' it will print asciii value of 's'
    //floating array may also contain the integers.but integer array should not contain the floating values
    float array1[] = {1.9,2.3,4.5,6.7,'s'};
    for (int i = 0; i < 5; i++)
    {
        /* code */
        cout<<array1[i]<<endl;

    }
    //char array should not contain the any integers and floats
    char array2[] ={'a','c','s','e',4};
    for (int i = 0; i < 5; i++)
    {
         cout<<array2[i]<<endl;
                /* code */
    }
    
    // if we declare an array with more than its size then it gives an run time error 
    // int sai[3] = {1,3,4,5,5,6};
    // if we do not intialize the all the elements of the array,the elements which are not intialized are automatically set zero 

    int saisri[4] = {1,3};
    for (int i = 0; i < 4; i++)
     {
               cout<<saisri[i] <<endl;      /* code */
    }
    
    // we can access the array elements even if we do not know the size of the array like we do in python 
    // this can be done using the syntax "data type variable : array_name " 

    int angajala[4] = {1,3,4,5};
    for(int x : angajala)
       cout<< x << endl;
    //  notice that here we do not define the size of the arrray, even though we can acess all the elements of the array 
    // this is very useful when we do not know the size of the array 
   
    float yamuna[8] = {1,2,3,4,5};
    for(float y : yamuna) 
       cout<<y << endl;
    // note here data type is float 

    char anuradha[] = {'s','d','d'};
    for(char a:anuradha)
       cout << a << endl;
       // here data type is char

    // we do n't even want to specify the data type ,this can be done by  using the keyword "auto" 
    for(auto a : anuradha )
       cout << a  << endl;
    // here anuradha is of char type,notice that we did not specified any data type here 

    for (auto  x : saisri)
      cout << x << endl;
    //   here saisri is of int type
    return 0;

}  