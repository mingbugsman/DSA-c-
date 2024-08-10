
#include <iostream>
#include <vector>

using namespace std;



    void numIslands(vector<vector<char>>& grid, int x, int y) {
        if (x < grid.size() && x >= 0 && y >= 0 && y < grid[x].size() && grid[x][y] == '1') {
            grid[x][y] = '0';
            numIslands(grid, x+1, y);
            numIslands(grid,  x-1, y);
            numIslands(grid, x, y+1);
            numIslands(grid, x, y-1);
        }        
        else {
            return;
        }
    }
int main()
{

    cout<<"Hello World" << endl;
    vector<vector<char>> island = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}  
    };
    int count = 0;
    
    for (int i = 0; i < island.size(); i++) {
        for (int j = 0; j < island[i].size(); j++) {
            if (island[i][j] == '1') {
                numIslands(island, i, j);
                count++;
            }
        }
    }
    cout << count << " ";
    return 0;
}