//C++ program to merge two sorted array using constant space
#include <bits/stdc++.h>
using namespace std;

#define file_open()                   \
    freopen("inputq2.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);

void swapIfGrtr(int ar1[], int i, int j){
    if(ar1[i] > ar1[j]){
        swap(ar1[i], ar1[j]);
    }
}

void merge(int ar1[],int lt, int m, int n){
	int len = n;
	int gap = len/2 + (len%2);
	
	while(gap>0){
        int left=lt, right = left + gap;
        while(right<len){
            swapIfGrtr(ar1, left, right);
            left++;
            right++;
        }
        if(gap==1){
            break;
        }
        gap = (gap/2) + (gap%2);
	}
}

int main() {

    #ifndef ONLINE_JUDGE
        file_open()
    #endif
        fast;

	int n, m; cin>>n>>m;
    int ar1[n];
    for (int i=0; i<n; i++) {
        cin>>ar1[i];
    }
	merge(ar1, 2, m, n);

	cout << "The sorted array is: ";
	for (int i = 0; i < n; i++){
		cout << ar1[i] << " ";
    }
    cout<<endl;
	return 0;
}

//This code is contributed by 525tamannacse1
