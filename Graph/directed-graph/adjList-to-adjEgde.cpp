// directed graph
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adjEdge(vector<vector<int>> adjList, int size) {
    vector<pair<int,int>> edge;
    for (int i = 1; i <= size; i++ ){
        for (int j : adjList[i]) {
            edge.push_back({i,j});
        }
    }
    return edge;
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
    vector<pair<int,int>> ans = adjEdge(adjList, n);
    for (pair<int,int> x : ans) {
        cout << x.first << " " << x.second << endl;
    } 

}