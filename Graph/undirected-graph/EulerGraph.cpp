#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Graph {
    int V; // Số đỉnh
    vector<vector<int>> adj; // Danh sách kề

public:
    Graph(int V) : V(V) {
        adj.resize(V);

    }

    void addEdge(int u, int v) {
        if (u==v) return;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    bool isEulerian() {
        int odd = 0;
        for (int i = 1; i < V; i++) {
            if (adj[i].size() % 2 != 0) odd++;
        }
        return odd == 0; // Tất cả các đỉnh có bậc chẵn
    }
    void print () {
            for (int i = 1; i < V ; i++) {
                cout << i << " : ";
                for (int x : adj[i]) {
                    cout << x << " "; 
                }
                cout << endl;
            }
    }

    void findEulerCycle(int start) {
  
        stack<int> currPath; // Đường đi hiện tại
        vector<int> circuit; // Chu trình Euler
        currPath.push(start);


        while (!currPath.empty()) {
            int curr = currPath.top();
            if (!adj[curr].empty()) {
                int next = adj[curr].back();
                adj[curr].pop_back();
                
                auto it = find(adj[next].begin(), adj[next].end(), curr);
                if (it != adj[next].end()) {
                    adj[next].erase(it); // Xóa cạnh (curr, next)
                }
                currPath.push(next);
            } else {
                circuit.push_back(curr);
                currPath.pop();
            }
        }
        reverse(circuit.begin(), circuit.end());
        cout << "Chu trinh Euler: ";

        for (int v : circuit) cout << v << " ";
        cout << endl;
    }
};

int main() {
    Graph g(7); // 4 đỉnh

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(5,6);
    g.addEdge(4,3);
    g.print();
    g.findEulerCycle(1);

    return 0;
}
