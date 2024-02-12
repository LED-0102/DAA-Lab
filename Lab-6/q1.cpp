#include<bits/stdc++.h>
using namespace std;

#define frin for (int i=0; i<n; i++)
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define ull unsigned long long
#define nl "\n"
#define rep(i, a, b) for (int i=a; i<b; i++)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pd = pair<double, double>;
using vpi = vector<pi>;
using vpll = vector<pll>;
using vpd = vector<pd>;

template <typename datatype>
void ct(vector<datatype> v, string sep = " ", string endline = "\n")
{
    for (auto i : v)
        cout << i << sep;
    cout << endline;
}
template <typename datatype>
void ct(set<datatype> k, string sep = " ", string endline = "\n")
{
    for (auto i : k)
        cout << i << sep;
    cout << endline;
}
void ct(bool k) { cout << (k ? "YES" : "NO") << "\n"; }
#define file_open()                   \
    freopen("/home/darshil/LED/C++/CodeForces/input.txt", "r", stdin); \
    freopen("/home/darshil/LED/C++/CodeForces/output.txt", "w", stdout);
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
 
ll powmod(ll base,ll exponent,ll mod){
    ll ans=1;
    if(base<0) base+=mod;
    while(exponent){
        if(exponent&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        exponent/=2;
    }
    return ans;
}
 
ll fast_pow(ll base,ll exponent){
    ll ans=1;
    while(exponent){
        if(exponent&1)ans=(ans*base);
        base=(base*base);
        exponent/=2;
    }
    return ans;
}

const int inf = 2e9;
const int N = 2e5+10;
const int mod = 1e9+7;
void dfs(int vertex, int vis[], stack<int> &st, vector<int> g[], int path_vis[], bool &possible){
    vis[vertex]=1;
    path_vis[vertex]=1;
    for (int child: g[vertex]){
        if (vis[child] && path_vis[child]){
            possible=false;
            return;
        } else if (!vis[child]){
            dfs(child, vis, st, g, path_vis, possible);
        }
    }
    path_vis[vertex]=0;
    st.push(vertex);
}

int main() {
    freopen("inputq1.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    bool possible=true;
    rep(i, 0, m){
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
    }
    int vis[n+1] ={0};
    int path_vis[n+1]={0};
    stack<int> st;
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            dfs(i, vis, st, adj, path_vis, possible);
        }
    }
    if (!possible){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;
    return 0;
}