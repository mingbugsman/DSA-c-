#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor == newColor) return image; // Avoid infinite loop if newColor is same as originalColor

        int rows = image.size();
        int cols = image[0].size();
        queue<pair<int, int>> toFill;
        toFill.push({sr, sc});

        while (!toFill.empty()) {
            pair<int, int> cell = toFill.front();
            toFill.pop();

            int r = cell.first;
            int c = cell.second;

            // Fill the cell with the new color
            image[r][c] = newColor;

            // Check all 4 directions and add to the queue if they have the original color
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
