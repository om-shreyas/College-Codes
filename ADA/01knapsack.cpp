#include <iostream>
#include <vector>
using namespace std;

struct KnapsackItem {
    int weight;
    int value;
};

int knapsack(vector<KnapsackItem>& items, int maxWeight) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= maxWeight; w++) {
            if (items[i - 1].weight > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            }
        }
    }
    return dp[n][maxWeight];
}

int main() {
    int numItems, maxWeight;
    cout << "Enter the number of items: ";
    cin >> numItems;
    cout << "Enter the maximum weight capacity: ";
    cin >> maxWeight;
    vector<KnapsackItem> items(numItems);
    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < numItems; i++) {
        cin >> items[i].weight >> items[i].value;
    }
    int maxValue = knapsack(items, maxWeight);
    cout << "Maximum value that can be obtained: " << maxValue << endl;
    return 0;
}
