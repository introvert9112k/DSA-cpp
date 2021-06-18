// in this we will look into vector of vectors and array of vectors
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
void print_array(vector<int> *array, int n)
{
    cout << "the elements of the vector array are :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < array[i].size(); j++)
        {
            cout << array[i][j] <<" ";
        }
        cout << endl;
    }
} 
int main()

{

    //   syntax for declaring the array of vectors
    int n;
    cin >> n;
    vector<int> arr[n]; //this is vector array,as the data type is vector
                        //    so every element in the array is the vector
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int temp;
            cin >> temp;
            arr[i].push_back(temp);
        }
    }
    print_array(arr,n); 
    return 0; 
}  