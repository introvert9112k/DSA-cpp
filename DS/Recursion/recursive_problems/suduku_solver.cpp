#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
       source : strivers playlist
       Intution :
       Check all the possiblites. If any configuration is possible then return there itself.
    */

    /*This function returns whether it is safe place to locate the number in the current cell*/
    bool is_possible(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == c) /*checking whether number is already present in row*/
                return false;
            if (board[i][col] == c) /*checking whether number is already present in row*/
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) /*checking in 3x3 box*/
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        /*iterating over the board and checking for the empty cell*/
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int c = '1'; c <= '9'; c++) /*If cell is empty checking the possiblity of every number*/
                    {
                        if (is_possible(board, i, j, c))
                        {
                            board[i][j] = c;
                            if (solve(board)) /*If it returns true, we found a solution*/
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false; /*This implies that no number can fit in that cell,so return false*/
                }
            }
        }
        return true; /*This determines a possible solution*/
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
int main()

{

    return 0;
} 