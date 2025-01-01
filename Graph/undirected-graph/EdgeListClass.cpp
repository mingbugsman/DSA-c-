#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

class Graph
{
private:
    int V; // so luong dinh
    vector<tuple<int, int, int>> edges;

public:
    Graph(int verticles) : V(verticles) {}
    void addEdge(int u, int v, int w)
    {
        edges.push_back({u, v, w});
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
        for (int i = 0; i < V; i++)
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

    g.bellmanFord(0);
    return 0;
}