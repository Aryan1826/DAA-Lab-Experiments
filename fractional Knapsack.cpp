#include <bits/stdc++.h>
using namespace std;

// Structure for an item
struct Item {
    int value, weight;
};

// Function to compare items based on value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // higher ratio first
}

// Function for Fractional Knapsack
double fractionalKnapsack(int W, Item arr[], int n) {
    // Step 1: Sort items by value/weight ratio
    sort(arr, arr + n, cmp);

    double finalValue = 0.0; // Result

    // Step 2: Traverse items
    for (int i = 0; i < n; i++) {
        // If adding item completely
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        }
        // If we can't add full item, take fraction
        else {
            finalValue += arr[i].value * ((double)W / arr[i].weight);
            break; // Knapsack full
        }
    }

    return finalValue;
}

// Driver code
int main() {
    int n = 3, W = 50; // Example
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; // {value, weight}

    cout << "Maximum value in Knapsack = "
         << fractionalKnapsack(W, arr, n) << endl;

    return 0;
}
