#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dfs(int vertex, vector<int> &vis, vector<int> adj[], vector<int> &length){
    if (vis[vertex]!=-1){
        return vis[vertex];
    }
    int ans=0;
    for (int child: adj[vertex]){
        ans = max(ans, 1+dfs(child, vis, adj, length));
    }
    return vis[vertex]=ans;
}
int main(){
    freopen("inputq1.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> length(n+1, 0);
    vector<int> vis (n+1, -1);
    bool possible=true;
    for (int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
    }
    for (int i=1; i<=n; i++){
        dfs(i, vis, adj, length);
    }
    int mx=-1;
    for (int i=1; i<=n;i++){
        mx = max(mx, vis[i]);
    }
    cout<<mx<<endl;
    
    return 0;
}