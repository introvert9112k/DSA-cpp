// in this we will look into commonly used algothims in the algothims header file
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main()

{
    vector<int> v(10);
    for (int i = 0; i < 10; i++)
        cin >> v[i];
    int min = *min_element(v.begin(), v.end());
    // min_element returns the pointer to the location where min element is present ,in order to get the min element value we have to dereference it 
    // the time complexity is O(N)
    cout << "the minimum value in the vector is: " << min << endl;
    int max = *max_element(v.begin(), v.end());
    cout << "the maximum element in the vector is : " << max << endl;
    // max_element function is also similar to the min_element
    int ct = count(v.begin(), v.end(), 2);
    // count function returns the frequency of the element in array 
    // if count is zero then element is not present in vector and if count is 1 then element is unique
    auto num = find(v.begin(), v.end(), 23);
    // find function will return the iterator pointing to the given values location,if the element is not present then it returns the iterator to the virtual end that is the v.end()
    if(num!=v.end())
        cout << "the element is present in the container" << endl;
    else
        cout << "the element is absent in the container : " << endl;

    reverse(v.begin(), v.end());
    // reverse function reverses the container,it reverses in place,we can pass the custom iterators of the postiions in which we want to reverse
    sort(v.begn(), v.end());
    // sort function sorts the array,by default it sorts in increasing order,if we want to sort in decreasing order we should provide a comparator function 

    return 0;
}    