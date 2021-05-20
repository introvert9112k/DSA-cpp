// in this we will discuss  about the decalring the 2D arrays and how can we acess the elements of the array 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main() 

{
        // -------------Declaring 2D arrays----------
        // There are 3 ways to declare the 2D arrays 
        // let us discuss one by one

        int array[3][4] = {{1,2,3,4}, {5,6,7,8},{9,10,11,12}};
        // here a matrix is created with 3 rows and 4 columns,actually the memory is linearly allocated in the stack but supports the syntax for acess the matrix elements 
        // let us intialize the elements of the matrix

        // Acessing the elements 
        // elements can be accessed using the two for loops 
        // let us access the elements of the 2D array
        cout<< "the elements of the static 2D array are : " <<endl; 
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
              cout<< array[i][j] <<endl;
        } 
        // In the first method the whole memory is creatd in stack 

        // 2.-------------


        // using the array of pointer 
        // in this method we will create a array of pointer and each element in the pointer array points to the rows of the matrix which are created in the heap 

        // let us declare the array of pointer 
        // the size of the array is equal to the number of rows in matrix
        int *pointer_array[3];
        // this will create an pointer array that mean all the elements of the array are pointers 
        // this pointer array is creatd in the stack

        pointer_array[0] = new int[4];
        pointer_array[1] = new int[4];
        pointer_array[2] = new int[4];

        // so each pointer in the pointer array points to the array of size 4 which is created in the heap

    //   let us intialize the matrix elements
        for (int i = 0; i <= 3; i++)
           { pointer_array[0][i] = i+1;
             pointer_array[1][i] = i+5;
             pointer_array[2][i] = i+9;   
           }      
        // let us acess the elements 
        // these elements can also be acessed in the similar way we accessed in first case
        cout<< "the elements of the matrix of 2nd type are : " <<endl;
        for (int i = 0; i < 3;i++)
        {
            for (int j = 0; j < 4; j++)
             cout<< pointer_array[i][j] <<endl;
        } 

        // here the pointer array is creatd in the stack and corresponding row vectors are created in the heap 


        // 3.
        // let us create every thing in heap 
        // for this we use the double pointer
        int **a;
        a = new int*[3];

        a[0] = new int[4];
        a[1] = new int[4];
        a[2] = new int[4];
        for (int i = 0; i < 4; i++)
        {
            a[0][i] = i + 1;
            a[1][i] = i + 5;
            a[2][i] = i + 9;
        } 
        cout<< "the elements of the matrix of 3rd type are : " <<endl;
        for (int i = 0; i < 3;i++)
        {
            for (int j = 0; j < 4; j++)
              cout<< a[i][j] <<endl;
        } 
        // here the pointer array and row arrays are created in the heap itself 
        // double pointer a is pointing to the pointer array 
}   