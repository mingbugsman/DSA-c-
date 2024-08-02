// convert an undirected Graph from an Adjacenty-matrix to Edge-List

/*
example : input
5
0 1 1 1 0
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
0 1 1 1 0
*/


#include <iostream>
#include <vector>
using namespace std;

// vertex là đỉnh, edge là cạnh

vector<pair<int,int>> edge;


int main() {
    
    int n; cin >> n;
    vector<vector<int>> adj(n+1,vector<int>(n + 1)); // adj[i] stores adjacency list of VERTEX(i)
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] == 1 && i < j) {
                edge.push_back({i,j});
            }
        }
    }
    for (auto it : edge) {
        cout << it.first << " " << it.second << endl;
    }

    
    return 0;
}



/*
output :
1 2
1 3
1 4
2 3
2 4
2 5
3 4
3 5
4 5
 */