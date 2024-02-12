#include<bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(int vertex, vector<int> &vis){
    if (vis[vertex]){
        return;
    } else {
        cout<<vertex<<" ";
    }
    for (int child: g[vertex]){
        if (child == par) continue;
        dfs(child, vertex);
    }
}
int main(){
    freopen("inputq1.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> vis (n+1, 0);
    bool possible=true;
    vector<vector<int>> cc;
    for (int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
    }
    for (int i=1; i<n; i++){
        dfs()
    }
    return 0;
}