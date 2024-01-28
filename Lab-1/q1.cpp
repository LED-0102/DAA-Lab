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



int main(){
    #ifndef ONLINE_JUDGE
        file_open()
    #endif
        fast;
    
    int n; cin>>n;
    int a[n];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    int largest=INT_MIN;
    int largest_ind = -1;
    int second_largest=INT_MIN;
    int second_largest_ind=-1;
    for (int i=0; i<n; i++){
        if (a[i] <= largest && a[i] <= second_largest){
            continue;
        } else if (a[i]<=largest && a[i]>=second_largest){
            second_largest = a[i];
            second_largest_ind = i;
        } else if (a[i]>=largest) {
            second_largest=largest;
            second_largest_ind=largest_ind;
            largest=a[i];
            largest_ind=i;
        }
    }
    cout<<largest+second_largest<<endl;
    return 0;
}