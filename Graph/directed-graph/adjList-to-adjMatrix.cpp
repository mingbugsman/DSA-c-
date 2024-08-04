// directed graph
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ajdMatrix(vector<vector<int>> adjList, int size) {
    vector<vector<int>> res(size+1, vector<int>(size+1,0));
    for (int i = 1; i <= size; i++) {
        for (int j : adjList[i]) {
            res[i][j] = 1;
        }
    } 
    return res;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> adjList = {
        {},
        {2},
        {5},
        {2,4,5},
        {1},
        {}
    };
    vector<vector<int>> ans = ajdMatrix(adjList, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j]<< " ";
        }
        cout << endl;
    } 

}