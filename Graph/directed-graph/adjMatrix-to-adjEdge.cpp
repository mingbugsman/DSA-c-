#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> convertToAdjEdge( vector<vector<int>> adjEdge, int n) {
    vector<pair<int,int>> edge;
        for (int i = 1; i <= n;i++) {
            for (int j = 1; j <= n; j++) {
                if (adjEdge[i][j] == 1) {
                    edge.push_back({i,j});
            }
        }
    }
    return edge;
}


int main() {
    int n; cin >> n;
    vector<vector<int>> adjMatrix(n+1,vector<int>(n+1));
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adjMatrix[i][j];
        }
    }
    vector<pair<int,int>> adjEdge = convertToAdjEdge(adjMatrix, n);
    for (auto x : adjEdge) {
        cout << x.first << " " << x.second << endl;
    }
}