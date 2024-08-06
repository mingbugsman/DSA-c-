#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // Convert matrix to adjacency list representation
    vector<vector<int>> convert(const vector<vector<int>>& image) {
        vector<vector<int>> adjList(image.size());
        for (int i = 0; i < image.size(); i++) {
            for (int j = 0; j < image[i].size(); j++) {
                if (image[i][j]) {
                    adjList[i].push_back(j);
                }
            }
        }
        return adjList;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor == newColor) return image; 

        int rows = image.size();
        int cols = image[0].size();
        stack<pair<int, int>> toFill;
        toFill.push({sr, sc});

        while (!toFill.empty()) {
            pair<int, int> cell = toFill.top();
            toFill.pop();

            int r = cell.first;
            int c = cell.second;

            image[r][c] = newColor;

            // Check all 4 directions
            if (r + 1 < rows && image[r + 1][c] == originalColor) {
                toFill.push({r + 1, c});
            }
            if (r - 1 >= 0 && image[r - 1][c] == originalColor) {
                toFill.push({r - 1, c});
            }
            if (c + 1 < cols && image[r][c + 1] == originalColor) {
                toFill.push({r, c + 1});
            }
            if (c - 1 >= 0 && image[r][c - 1] == originalColor) {
                toFill.push({r, c - 1});
            }
        }

        return image;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
