// convert an undirected graph from an adjacency list to an adjacency matrix

#include<bits/stdc++.h>
using namespace std;
int n;

/*
2 3 4
1 3 4 5
1 2 4 5
1 2 3 5
2 3 4
*/

int a[1001][10001]; // ma tran ke

/*
vector<vector<int>> adjListToAdjMatrix(int n, const vector<vector<int>>& adjList) {
    // Initialize an n x n adjacency matrix with 0s
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    // Populate the adjacency matrix
    for (int u = 0; u < n; ++u) {
        for (int v : adjList[u]) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; // Since the graph is undirected
        }
    }

    return adjMatrix;
}
*/


int main() {
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n ; i++) {
        string s, num;
        getline(cin,s);
        stringstream ss(s);
        while (ss >> num) {
            a[i][stoi(num)]=1;
        } 
    }
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n ; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    /*
    vector<vector<int>> adjList = {
        {1, 4},    // Vertex 0 is connected to vertices 1 and 4
        {0, 2, 3, 4}, // Vertex 1 is connected to vertices 0, 2, 3, and 4
        {1, 3},    // Vertex 2 is connected to vertices 1 and 3
        {1, 2, 4}, // Vertex 3 is connected to vertices 1, 2, and 4
        {0, 1, 3}  // Vertex 4 is connected to vertices 0, 1, and 3
    };

    // Convert adjacency list to adjacency matrix
    vector<vector<int>> adjMatrix = adjListToAdjMatrix(n, adjList);

    // Print the adjacency matrix
    for (const auto& row : adjMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    */
}