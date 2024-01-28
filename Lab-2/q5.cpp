#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("inputq5.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n; cin>>n;
    assert(n>1);
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int firstMini=INT_MAX;
    int secMini=INT_MAX;
    for (int i=0; i<n; i++){
        if (arr[i] <= firstMini){
            secMini = firstMini;
            firstMini = arr[i];
        } else if (arr[i]>firstMini && arr[i] <= secMini) {
            secMini = arr[i];
        }
    }
    cout<<firstMini<<" "<<secMini<<endl;
    
}
