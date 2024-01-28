#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

vector<int> generateRandomSortedArray(int n, int m) {
    vector<int> result;

    // Generate first m random elements in ascending order
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 1e6);

    for (int i = 0; i < m; ++i) {
        result.push_back(distribution(gen));
    }
    sort (result.begin(), result.end());
    // Generate remaining n-m random elements in descending order
    vector<int> remaining(n - m);
    for (int i = 0; i < n - m; ++i) {
        remaining[i] = distribution(gen);
    }

    sort(remaining.begin(), remaining.end());

    result.insert(result.end(), remaining.begin(), remaining.end());

    return result;
}

int main() {
    int n=1e6;
    int m=500010;
    freopen("inputq1.txt", "w", stdout);
    vector<int> result = generateRandomSortedArray(n, m);
    cout<<n<<" "<<m<<endl;
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout<<endl;
    freopen("inputq2.txt", "w", stdout);
    cout<<n<<" "<<m<<endl;
    for (int i = 0; i < n; ++i){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    freopen("inputq3.txt", "w", stdout);
    cout<<n<<" "<<m<<endl;
    for (int i = 0; i < n; ++i){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
