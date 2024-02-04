#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define file_open()                   \
    freopen("inputq2.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);

int getMergedElement(int a[], int m, int b[], int n, int i) {
    int index1 = 0, index2 = 0;

    while (index1 < m && index2 < n) {
        if (a[index1] <= b[index2]) {
            if (i == 0) {
                return a[index1];
            }
            index1++;
        } else {
            if (i == 0) {
                return b[index2];
            }
            index2++;
        }
        i--;
    }

    while (index1 < m) {
        if (i == 0) {
            return a[index1];
        }
        index1++;
        i--;
    }

    while (index2 < n) {
        if (i == 0) {
            return b[index2];
        }
        index2++;
        i--;
    }
    return -1;
}



int main(){

    #ifndef ONLINE_JUDGE
        file_open()
    #endif
        fast;


    int m, n;
    cin>>m>>n;
    int a[m];
    int b[n];
    for (int i=0; i<m; i++){
        cin>>a[i];
    }
    for (int i=0; i<n; i++){
        cin>>b[i];
    }
    if ((m+n)%2 == 0){
        cout<<(float)((float)(getMergedElement(a, m, b, n, (m+n)/2-1)+getMergedElement(a, m, b, n, (m+n)/2))/2)<<endl;
    } else {
        cout<<getMergedElement(a, m, b, n, (m+n)/2)<<endl;
    }
    return 0;
}

//Time complexity O(n)
//Space complexity O(1)