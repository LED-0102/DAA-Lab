#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<vector<int>> &v, int i, int j, int &count){
    int n = v.size();
    int m = v[0].size();
    if (i<0 || i>=n || j<0 || j>=m || v[i][j] == -1 || v[i][j] == 0){
        return;
    }
    v[i][j]=-1;
    count++;
    dfs(v, i-1, j-1, count);
    dfs(v, i-1, j, count);
    dfs(v, i-1, j+1, count);
    dfs(v, i, j+1, count);
    dfs(v, i+1, j+1, count);
    dfs(v, i+1, j, count);
    dfs(v, i+1, j-1, count);
    dfs(v, i, j-1, count);
}

int main(){
    freopen("inputq1.txt", "r", stdin);
    int n; cin>>n;
    int m; cin>>m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }
    int max_count=-1;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int count=0;
            dfs(v, i, j, count);
            max_count = max(max_count, count);
        }
    }
    cout<<max_count<<endl;
    return 0;
}