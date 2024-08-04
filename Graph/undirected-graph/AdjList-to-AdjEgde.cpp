#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Function to convert adjacency list to edge list
vector<pair<int, int>> adjListToEdgeList(const vector<vector<int>>& adjList) {
    vector<pair<int, int>> edgeList;
    
    for (int u = 0; u < adjList.size(); ++u) {
        for (int v : adjList[u]) {
            // Ensure each edge is added only once
            if (u < v) {
                edgeList.emplace_back(u, v);
            }
        }
    }

    return edgeList;
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<int>> adjList = {
        {1, 4},      // Vertex 0 is connected to vertices 1 and 4
        {0, 2, 3, 4},// Vertex 1 is connected to vertices 0, 2, 3, and 4
        {1, 3},      // Vertex 2 is connected to vertices 1 and 3
        {1, 2, 4},   // Vertex 3 is connected to vertices 1, 2, and 4
        {0, 1, 3}    // Vertex 4 is connected to vertices 0, 1, and 3
    };

    vector<pair<int, int>> edgeList = adjListToEdgeList(adjList);

    for (const auto& edge : edgeList) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}
