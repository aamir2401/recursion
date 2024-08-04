#include <iostream>
#include <vector>
using namespace std;
bool isSafeToGo(int ratMaze[3][3], int srcx, int srcy, int row, int col, vector<vector<bool>> &visited, vector<string> &paths, string &output)
{
    // we have to make sure three conditions are fullfilled
    // 1--> arrray or maze is valid;
    // 2--> the movement we are just to make in that cell visited is marked as false;
    // 3--> the given maze carries 1 in that cell;
    if (((srcx >= 0 and srcx < row) and (srcy >= 0 and srcy < col)) and (visited[srcx][srcy] == false) and (ratMaze[srcx][srcy] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void findingPathforMouse(int ratMaze[3][3], int srcx, int srcy, int row, int col,
                         vector<vector<bool>> &visited, vector<string> &paths, string &output)
{
    // base case would be the rat reached to its destination;
    if ((srcx == row - 1) && (srcy == col - 1))
    {
        paths.push_back(output);
        return;
    }
    // now rat k pass 4 options hain movement k liye like--> left, right, down, up; we will solve all these possible movement;
    //  left;--> i, j-1
    if (isSafeToGo(ratMaze, srcx, srcy - 1, row, col, visited, paths, output))
    {
        visited[srcx][srcy - 1] = true;
        // make recursive call for next movement;
        findingPathforMouse(ratMaze, srcx, srcy + 1, row, col, visited, paths, output = output + 'L');
        // now backtrack and make true cell as false;
        visited[srcx][srcy - 1] = false;
    }


//      if (isSafeToGo(ratMaze, srcx, srcy - 1, row, col, visited, paths, output))
// {
//     visited[srcx][srcy - 1] = true;
//     // make recursive call for next movement;
//     findingPathforMouse(ratMaze, srcx, srcy - 1, row, col, visited, paths, output = output + 'L');
//     // now backtrack and make true cell as false;
//     visited[srcx][srcy - 1] = false;
// }





    // right--> i, j+1;
    if (isSafeToGo(ratMaze, srcx, srcy + 1, row, col, visited, paths, output))
    {
        visited[srcx][srcy + 1] = true;
        // make recursive call for next movement;
        findingPathforMouse(ratMaze, srcx, srcy + 1, row, col, visited, paths, output = output + 'R');
        // now backtrack and make true cell as false;
        visited[srcx][srcy + 1] = false;
    }
    // down --> i+1,j;
    if (isSafeToGo(ratMaze, srcx + 1, srcy, row, col, visited, paths, output))
    {
        visited[srcx + 1][srcy] = true;
        // make recursive call for next movement;
        findingPathforMouse(ratMaze, srcx + 1, srcy, row, col, visited, paths, output = output + 'D');
        // now backtrack and make true cell as false;
        visited[srcx + 1][srcy] = false;
    }
    // up--> i-1,j;
    if (isSafeToGo(ratMaze, srcx - 1, srcy, row, col, visited, paths, output))
    {
        visited[srcx - 1][srcy] = true;
        // make recursive call for next movement;
        findingPathforMouse(ratMaze, srcx - 1, srcy, row, col, visited, paths, output = output + 'U');
        // now backtrack and make true cell as false;
        visited[srcx - 1][srcy] = false;
    }
    


//     if (isSafeToGo(ratMaze, srcx - 1, srcy, row, col, visited, paths, output))
// {
//     visited[srcx - 1][srcy] = true;
//     // make recursive call for next movement;
//     findingPathforMouse(ratMaze, srcx - 1, srcy, row, col, visited, paths, output = output + 'U');
//     // now backtrack and make true cell as false;
//     visited[srcx - 1][srcy] = false;
// }
 
}
int main()
{
    int ratMaze[3][3] = {{1, 0, 0},
                         {0, 1, 1},
                         {0, 1, 1}
                         };
    if(ratMaze[0][0] == 0)
    {
        cout<<"No path found!";
        return 0;
    }
    int row = 3;
    int col = 3;
    vector<vector<bool>> visited(row, vector<bool> (col, false));
    vector<string> paths;
    string output = "";
    // visited[0][0] = true;
    findingPathforMouse(ratMaze, 0, 0, row, col, visited, paths, output);
    cout<<"Printig the path for rat to go destination :"<<endl;
    for (auto i : paths)
  {
    cout << i << " ";
  }
  cout << endl;
  if (paths.size() == 0)
  {
    cout << "No Path Exists " << endl;
  }

    return 0;
}