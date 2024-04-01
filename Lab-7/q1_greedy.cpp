#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int item_id;
    int value;
    int weight;
};

double knapsack_greedy(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });

    double total_value = 0.0;
    int current_weight = 0;

    for (const Item& item : items) {
        if (current_weight + item.weight <= capacity) {
            total_value += item.value;
            current_weight += item.weight;
        }
    }

    return total_value;
}

int main() {
    int n;
    int capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<Item> items(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter details for item " << i + 1 << ":" << endl;
        cout << "Item ID: ";
        cin >> items[i].item_id;
        cout << "Value: ";
        cin >> items[i].value;
        cout << "Weight: ";
        cin >> items[i].weight;
    }

    double max_value = knapsack_greedy(items, capacity);

    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}
