#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 3x3 blocks for each character ' ', '/', '\\'
const vector<vector<int>> emptyBlock = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
const vector<vector<int>> slashBlock = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}};
const vector<vector<int>> backslashBlock = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

vector<vector<int>> matrix;

// Depth-First Search (DFS)
void dfs(int i, int j) {
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 1)
        return;
    matrix[i][j] = 1;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

void fillMatrixWithBlock(const vector<vector<int>>& block, int index) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; ++j)
            matrix[index + i][j] = block[i][j];
}

int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    matrix.assign(n * 3, vector<int>(n * 3, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int index = i * 3;
            if (grid[i][j] == '/')
                fillMatrixWithBlock(slashBlock, index);
            else if (grid[i][j] == '\\')
                fillMatrixWithBlock(backslashBlock, index);
        }

    int count = 0;
    for (int i = 0; i < n * 3; ++i)
        for (int j = 0; j < n * 3; ++j)
            if (matrix[i][j] == 0) {
                dfs(i, j);
                count++;
            }

    return count;
}


int main(){
    vector<string> grid = {
        " /",
        "/ "
    };

    int result = regionsBySlashes(grid);
    cout << "Number of regions: " << result << endl;  // Output should be 2

    return 0;
}