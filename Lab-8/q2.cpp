#include<bits/stdc++.h>
using namespace std;
#define ll long long

class DisjointSetUnion {
    private:
        static const int dsu_N = 1e5 + 10;
        int parent[dsu_N];  //Stores parent node of the connected components
        int sz[dsu_N];      //Stores size of connected components
        int max_size;       //Shows the maximum component size
        int conn_comp;      //Shows the number of connected components

    public:
        int find(int v) {
            if (v == parent[v]) return v;
            return parent[v] = find(parent[v]);
        }
        DisjointSetUnion() {
            max_size=0;
            conn_comp=0;
        }

        void make(int v) {
            parent[v] = v;
            sz[v] = 1;
            conn_comp++;
            max_size = max(max_size, 1);
        }

        void Union(int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                if (sz[a] < sz[b]) {
                    std::swap(a, b);
                }
                parent[b] = a;
                sz[a] += sz[b];
                max_size = max(max_size, sz[a]);
                conn_comp--;
            }
        }
        int get_max_size(){
            return max_size;
        }
        int get_conn_comp() {
            return conn_comp;
        }
};

int main(){
    int n, m; cin>>n>>m;
    vector<pair<int, pair<int, int>>> edges;
    map<pair<int, int>, int> present;
    DisjointSetUnion dsu;
    for (int i=0; i<m; i++){
        int a, b, c, d; //d is the boolean which says the edge is between different colors (1) or between same colors (0)
        cin>>a>>b>>c>>d;
        if (d) edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    for (int i=1; i<=n; i++) {
        dsu.make(i);
    }
    int total_cost=0;
    for (auto &edge: edges) {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.Union(u, v);
        total_cost += wt;
        present[{u, v}]=1;
    }
    int comp_one = dsu.find(1);
    for (int i=2; i<=n; i++) {
        if (comp_one != dsu.find(i)) {
            cout<<"IMPOSSIBLE"<<endl;
            break;
        }
    }
    return 0;
}