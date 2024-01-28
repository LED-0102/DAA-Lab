#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int maxCrossingSum(const vector<int>& arr, int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; --i) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; ++i) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarraySum(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    return max(maxSubarraySum(arr, low, mid),
               maxSubarraySum(arr, mid + 1, high),
               maxCrossingSum(arr, low, mid, high));
}
int findMaxSubarraySum(const vector<int>& arr) {
    int n = arr.size();

    return maxSubarraySum(arr, 0, n - 1);
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int result = findMaxSubarraySum(arr);

    cout << "The maximum sum of a subarray is: " << result << endl;

    return 0;
}
