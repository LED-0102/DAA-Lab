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
    freopen("inputq1.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
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

int main() {
    #ifndef ONLINE_JUDGE
        file_open()
    #endif
        fast;

    int n, m; cin>>n>>m;
    int a[n];
    int b[m];
    int c[n+m];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    for (int i=0; i<m; i++){
        cin>>b[i];
    }
    int l=0; int r=0;
    while (l<n && r<m) {
        if (a[l] <= b[r]){
            c[l+r]=a[l];
            l++;
        } else {
            c[l+r]=b[r];
            r++;
        }
    }
    if (l == n){
        for (int i=l+r; i<n+m; i++){
            c[i]=b[r];
            r++;
        }
    } else {
        for (int i=l+r; i<n+m; i++){
            c[i]=a[l];
            l++;
        }
    }
    cout<<"Q1 (a)"<<endl;
    for (int i=0; i<n+m; i++){
        cout<<c[i]<<" ";
    } cout<<endl;


    vector<int> un;
    l=0; r=0;
    un.push_back(min(a[0], b[0]));
    while (l<n && r<m) {
        if (a[l] < b[r]){
            if (!un.empty() && un.back() == a[l]){
                l++;
                continue;
            }
            un.push_back(a[l]);
            l++;
        } 
        else if (a[l] > b[r]){
            if (!un.empty() && un.back() == b[r]){
                r++; continue;
            }
            un.push_back(b[r]);
            r++;
        } else {
            l++;
        }
    }
    if (l == n){
        while (r<m){
            if (un.back() == b[r]){
                r++;
            } else {
                un.push_back(b[r]);
            }
        }
    } else {
        while (l<n){
            if (un.back() == a[l]){
                l++;
            } else {
                un.push_back(a[l]);
            }
        }
    }
    cout<<"Q1 (b)"<<endl;
    ct(un);

    vector<int> in;
    l=0; r=0;
    while (l<n && r<m){
        if (a[l] < b[r]){
            l++;
        } else if (a[l] > b[r]){
            r++;
        } else {
            if (!in.empty()){
                if (in.back() == a[l]){
                    l++;
                    continue;
                }
            }
            in.push_back(a[l]);
            l++;
        }
    }
    cout<<"Q1 (c)"<<endl;
    ct(in);
    return 0;
}