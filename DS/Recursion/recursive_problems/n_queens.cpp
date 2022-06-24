#include <bits/stdc++.h>
using namespace std;
// solution : strivers playlist

/*This is the optimised solution
Time Complexity : O(N^2)
Space Complexity : O(N^2 + 3*N) [Excluding the ans]
N^2 for the board,and each N for vectors lefrow, upper_diagonal and lower_diagonal
*/
class Solution2
{
public:
    typedef vector<int> vi;
    typedef vector<string> vs;
    typedef vector<vector<string>> vvs;

    void n_queens(int col, int n, vs &board, vvs &ans, vi &leftrow, vi &upper_diagonal, vi &lower_diagonal)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (!leftrow[row] && !lower_diagonal[row + col] && !upper_diagonal[n - 1 + col - row])
            {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lower_diagonal[row + col] = 1;
                upper_diagonal[n - 1 + col - row] = 1;
                n_queens(col + 1, n, board, ans, leftrow, upper_diagonal, lower_diagonal);
                board[row][col] = '.';
                leftrow[row] = 0;
                lower_diagonal[row + col] = 0;
                upper_diagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        vector<int> lefrow(n, 0), upper_diagonal(2 * n - 1, 0), lower_diagonal(2 * n - 1, 0);
        n_queens(0, n, board, ans, lefrow, upper_diagonal, lower_diagonal);
        for (auto &vect : ans)
        {
            for (auto &str : vect)
                cout << str << " ";
            cout << endl;
        }
    }
};

/*
Time complexity : O(N^3)
Space Complexity : O(N^2) [Excluding the ans]
*/
class Solution1
{
public:
    /*
      source : strivers playlist.
      Intution :
      check all the combinations of the placement of queens and see which is valid.
    */

    // function to check whether the current cell is under attack by any placed queens till now
    bool is_safe(vector<string> &board, int row, int col, int n)
    {
        int duprow = row, dupcol = col;

        /*-------------Upper Diagonal---------------*/
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        /*------------Lower Diagonal---------------*/
        row = duprow;
        col = dupcol;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        /*-------------Left Side---------------*/
        row = duprow;
        col = dupcol;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }
        return true;
    }
    // recursive code for trying out all combinations possible
    void n_queens(int col, int n, vector<string> &board, vector<vector<string>> &ans)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (is_safe(board, row, col, n))
            {
                board[row][col] = 'Q';
                n_queens(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        n_queens(0, n, board, ans);
        return ans;
    }
}; 
int main()
{

    return 0;
}