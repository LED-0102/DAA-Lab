#include<bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<int>adj[],vector<int>&indeg,int n){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int>topoSort;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto it:adj[node]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
    return topoSort;
}

int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<int>adj[n+1];
    vector<int>indeg(n+1,0);
    for(int i =0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    vector<int>topoSort = topologicalSort(adj,indeg,n);
    vector<int>longestPath(n,0);
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        for(auto it:adj[topoSort[i]]){
           longestPath[topoSort[i]] = max(longestPath[topoSort[i]],1+longestPath[it]);
        }
        ans = max(ans,longestPath[topoSort[i]]);
    }
    cout<<ans<<endl;
    return 0;
}