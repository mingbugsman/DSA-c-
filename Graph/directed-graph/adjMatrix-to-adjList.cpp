// convert an undirected graph from an adjacency matrix to an adjacency list

#include<bits/stdc++.h>
using namespace std;
int n, m;

int a[1001][10001]; // ma tran ke
vector<int> adj[1001];

int main() {
    cin >> n;
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) {
                adj[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (auto x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}