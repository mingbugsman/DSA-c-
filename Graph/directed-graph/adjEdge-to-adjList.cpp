// directed graph
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m; cin >> m >> n;
    vector <int> adjList[1001];
    for (int i = 0; i < m; i++) {
        int x,y; cin >> x >> y;
        adjList[x].push_back(y);
    }
    for (int i = 1; i <= n ; i++) {
        cout << i << " : ";
        for (int x : adjList[i]) {
           if (x !=0) cout << x << " "; 
        }
        cout << endl;
    } 

}