#include <bits/stdc++.h>
using namespace std;

#define file_open()                   \
    freopen("inputq3.txt", "r", stdin); \
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
 
// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end-begin+1);
}
 
// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
 
// Driver code
int main(){   

    #ifndef ONLINE_JUDGE
        file_open()
    #endif
        fast;

    int arr_size; cin>>arr_size;
    int arr[arr_size];
    for (int i=0; i<arr_size; i++){
        cin>>arr[i];
    }
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
 
    cout << "Sorted array is \n";
    printArray(arr, arr_size);
    return 0;
}