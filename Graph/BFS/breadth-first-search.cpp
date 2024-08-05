#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& adjList,int start, vector<bool>& visited) {
    queue <int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()){
        int current = q.front();
        q.pop();
        cout << current << " ";

        // get all adjacent verticles of dequeued vertex
        // current if an adjacent has not been visited 
        // then mark it visited and enqueue it
        for (int neighbour : adjList[current]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
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
    addEdge(adjList,0,1);
    addEdge(adjList,0,2);
    addEdge(adjList,1,3);
    addEdge(adjList,1,4);
    addEdge(adjList,2,1);

    // mark all the vertices as not visited
    vector<bool> visited(h, false);

    cout << "Breadth first traversal staring from vertex 0 :";

    bfs( adjList, 0, visited); 
    return 0;


}