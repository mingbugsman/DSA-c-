#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
#include <queue>
using namespace std;


typedef pair<int,int> pairii;

class Graph
{
private:
    int V; // so luong dinh
    vector<tuple<int, int, int>> edges;
    vector<vector<pairii>> adjList; 

public:
    Graph(int verticles) : V(verticles) {
        adjList.resize(V); // Khởi tạo adjList với số lượng đỉnh
        edges.resize(V);
    }
    void addEdge(int u, int v, int w)
    {
        edges.push_back({u, v, w});
        adjList[u].push_back({w,v});
    }
    void printEdgeList()
    {
        cout << "Danh sách các cạnh :\n";
        for (tuple<int, int, int> edge : edges)
        {
            int u, v, w;
            tie(u, v, w) = edge;
            cout << u << "--" << v << "[weight : " << w << "]\n";
        }
    }
    void bellmanFord(int src)
    {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Thực hiện V-1 lần
        for (int i = 0; i < V - 1; i++)
        {
            for (auto edge : edges)
            {
                int u, v, weight;
                tie(u, v, weight) = edge;
                cout << u << " ";
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Kiểm tra chu trình âm
        for (auto edge : edges)
        {
            int u, v, weight;
            tie(u, v, weight) = edge;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                cout << "Do thi chua chu trinh am!\n";
                return;
            }
        }

        // In khoảng cách
        cout << "Khoang cach tu dinh den nguon :\n";
        for (int i = 0; i < V; i++)
        {
            cout << "Dinh " << i << ": " << dist[i] << "\n";
        }
    }
    void dijkstra(int src) {
        cout << "thu nghiem tim dg ngan nhat" << endl;
        // store distance from src to verticles
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;

        // min-heap, storing( distance, verticles)
        priority_queue<pairii,  vector<pairii>, greater<pairii>> pq;
        pq.push({0,src});
        while(!pq.empty()) {
            int currentDistance = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (currentDistance > dist[u]) {
                continue;
            }  

            // traversal all of adjacency verticels of u 
            for (auto edge : adjList[u]) {
                int weight = edge.first;
                int v = edge.second;

                // neu tim duoc khoang cach ngan hon den v, cap nhat va them vao hang doi
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        cout << "K/c tu dinh " << src << " den cac dinh:\n";
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
                cout << "Dinh : " << i << ": vo han\n";
            else
                cout << "Dinh " << i << ": " << dist[i] << "\n";
        }
    }
}

;

int main()
{
    Graph g(5);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.dijkstra(0);
    return 0;
}