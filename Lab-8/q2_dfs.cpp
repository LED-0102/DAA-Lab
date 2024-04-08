#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int sz=18;
int graph[sz+1][sz+1][2]={0};
void dfs (int source, vector<pair<int, int>> edges[], int n, int visMask, ll pathSum, int prevCol, ll& ans) {
    if (visMask == (1<<(n+1)) -2) {
        ans = min (ans, pathSum);
        return;
    }
    for (auto edge: edges[source]) {
        int wt = graph[source][edge.first][edge.second];
        int col = edge.second;
        int adj = edge.first;
        if (col == prevCol || (visMask & (1 << adj))) {
            continue;
        }

        dfs(adj, edges, n, visMask | (1 << adj), pathSum + wt, col, ans);

    }
}

int main(){
    int n, m; cin>>n>>m;
    vector<pair<int, int>> edges[n+1];
    for (int i=0; i<m; i++) {
        int u, v, wt, col;
        cin>>u>>v>>wt>>col;
        graph[u][v][col]=wt;
        graph[v][u][col]=wt;
        edges[u].push_back({v, col});
        edges[v].push_back({u, col});
    }
    ll cost = INT_MAX;
    ll ans = INT_MAX;
    for (int i=1; i<=n; i++) {
        dfs(i, edges, n, (1 << i), 0, 2, ans);
    }
    cout<<ans<<endl;
    return 0;
}