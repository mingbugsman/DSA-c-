#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(const vector<vector<int>>& adjList, int start, vector<bool>& visited) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            cout << current << " ";
        }

        for (int neighbour : adjList[current]) {
            if (!visited[neighbour]) {
                s.push(neighbour);
            }
        }
    }
}

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
}

int main() {
    int h = 5;

    vector<vector<int>> adjList(h);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    // Đánh dấu tất cả các đỉnh là chưa được thăm
    vector<bool> visited(h, false);

    cout << "Depth first traversal starting from vertex 0: ";

    dfs(adjList, 0, visited); 
    return 0;
}
