// convert an undirected graph from an edge list to an adjacency list

#include <iostream>
#include <vector>
using namespace std;
int n, m; // n = vertex, m = edge
// vertex là đỉnh, edge là cạnh

vector<int> adj[1001]; // adj[i] stores adjacency list of VERTEX(i)



int main() {
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int x, y;   cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }   
    for (int i = 1; i <= n ; i++) {
        cout << i << " : ";
        for (int x : adj[i]) {
            cout << x << " "; 
        }
        cout << endl;
    }
    

    
    return 0;
}