#include<iostream>
#include<vector>
using namespace std;
bool ifSafeToPlace(vector<vector<char>> &board,int row, int col, int n)
{
    int i = row;
    int j = col;
  while( j >= 0)
  {
    if(board[i][j] == 'Q')
    {
        return false;
    }
    j--;
  }
  i = row;
  j = col;
  while( i >= 0 and j >= 0)
  {
    if(board[i][j] == 'Q')
    {
        return false;
    }
    i--;
    j--;
  }

   i = row;
   j = col;
   while (i < n and j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i++;
        j--;
    }
  return true;
}
void printTheSolution(vector<vector<char>> &board,int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void placementOfQueen(vector<vector<char>> &board, int n, int col)
{
    if(col >= n)
    {
       printTheSolution(board,n);
       return;
    }
    for(int row=0; row<n; row++)
    {
        if(ifSafeToPlace(board,row,col,n))
        {
            board[row][col] = 'Q';
            placementOfQueen(board,n,col+1);
            board[row][col] = '-';
        }
    }

}
int main()
{
    int n = 4;
    int col = 0;
    
    vector<vector<char>> board(n, vector<char>(n, '-'));
    placementOfQueen(board,n,col);






    return 0;
}