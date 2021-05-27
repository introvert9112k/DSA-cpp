// there are three ways to find the duplicates in the string

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void duplicate_1(string sai)
{
    cout << "the duplicates are : " << endl;
    int flag = 1;
    for (int i = 0; i < sai.length() - 1; i++)
    {
        if (sai[i] != 0)
        {
            for (int j = i + 1; j < sai.length(); j++)
            {

                if (sai[i] == sai[j])
                {
                    if (flag == 1)
                        cout << sai[i] << " ";
                    sai[j] = 0;
                    flag++;
                }
            }
            flag = 1;
        }
    }
    // time complexity is O(N2)
}

void hashing(string sai)
{  
    cout<< "the duplicates are : " <<endl;
    int array[26] = {0};
    for (int i = 0; i < sai.length(); i++)
        array[sai[i] - 97]++;
    for (int j = 0; j < 26; j++)
        if (array[j] > 1)
            cout << char(j + 97) << " "; 
} 
void bit_masking_merging(string sai)
{
    int h = 0, x = 0;
    for (int i = 0; i < sai.length(); i++)
     {
         x = 1;
         x = x << (sai[i] - 97);
         if(h&x)
          {  
              cout << sai[i] << " ";

          }
          else
              h = h | x;
     }
} 
int main()

{
    string sai;
    cin >> sai;
    // duplicate_1(sai);
    // hashing(sai);
    bit_masking_merging(sai);

    return 0;
}  