// Matrix Representation of the Graph
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;
    int matrix[v][v] = {0};
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        /*Undirected graph*/
        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;
    } 
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
} 