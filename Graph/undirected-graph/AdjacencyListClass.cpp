#include <iostream>
#include <vector>
#include <queue>


using namespace std;

class Graph
{
private:
    int V; // so luong dinh
    vector<vector<int>> adj;

    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";

        for (int u : adj[v])
        {
            if (!visited[u])
            {
                DFSUtil(u, visited);
            }
        }
    }

public:
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFS(int start)
    {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
    void printAdjList () {
        for (int i = 0; i < V; i++) {
            cout << i << " : ";
            for (int u : adj[i]) {
                cout << u << " ";
            }
            cout <<endl;
        }
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";
            for (int u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "DFS tu dinh khong 0: ";

    g.DFS(0);
    cout << endl;
    g.BFS(0);
}