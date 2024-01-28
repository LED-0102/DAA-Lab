#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

vector<int> generateRandomSortedArray(int n) {
    vector<int> result;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 1e6);

    for (int i = 0; i < n; ++i) {
        result.push_back(distribution(gen));
    }

    return result;
}

int main() {
    int n=1e6;
    freopen("inputq4.txt", "w", stdout);
    vector<int> result = generateRandomSortedArray(n);
    cout<<n<<endl;
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout<<endl;
    freopen("inputq5.txt", "w", stdout);
    cout<<n<<endl;
    for (int i = 0; i < n; ++i){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    freopen("inputq6.txt", "w", stdout);
    cout<<n<<endl;
    for (int i = 0; i < n; ++i){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
