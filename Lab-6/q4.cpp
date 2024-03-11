#include<bits/stdc++.h>
using namespace std;
bool isCycle(int i,vector<int>adj[],int vis[],int pathVis[]){
        if(vis[i]==1){
            if(pathVis[i]==1){return true;}
            return false;
        }
        vis[i] =1;
        pathVis[i] =1;
        for(auto it:adj[i]){
            if(isCycle(it,adj,vis,pathVis)){
              return true;
            }
        }
        pathVis[i] =0;
        return false;
}

int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<int>adj[n+1];
    for(int i =0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    int vis[n+1] = {0};
    int pathVis[n+1] = {0};
    bool f = false;
    for(int i=1;i<=n;i++){
        if(isCycle(i,adj,vis,pathVis)){
           f = true;
           break;
        }
    }
    if(f){
        cout<<"CYCLE IS PRESENT"<<endl;
    }
    else{
        cout<<"CYCLE IS NOT PRESENT"<<endl;
    }
    return 0;
}