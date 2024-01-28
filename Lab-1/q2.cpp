#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define file_open()                   \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
int solve(int w[], int v[], int maxWeight, int n, vector<vector<int>> &dp) {
    if (n < 0 || maxWeight<=0){
        return 0;
    }
    if (dp[maxWeight][n]!=-1){
        return dp[maxWeight][n];
    }
    if (w[n] > maxWeight){
        return dp[maxWeight][n] = solve(w, v, maxWeight, n-1, dp);
    } else {
        return dp[maxWeight][n] = max(v[n] + solve(w, v, maxWeight-w[n], n-1, dp), solve(w, v, maxWeight, n-1, dp));
    }

}

int main(){
    #ifndef ONLINE_JUDGE
        file_open()
    #endif
        fast;
     
    //Enter Number of items
    int items; cin>>items;
    //Enter maxWeight
    int maxWeight; cin>>maxWeight;
    //Enter weights
    int w[items]; int v[items];
    vector<vector<int>> dp(maxWeight+5, vector<int> (items+5, -1));
    for (int i=0; i<items; i++){
        cin>>w[i];
    }
    //Enter values
    for (int i=0; i<items; i++){
        cin>>v[i];
    }
    cout<<solve(w, v, maxWeight, items-1, dp)<<endl;
    return 0;
}