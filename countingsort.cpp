#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    int count[1000] = {0};  // assuming max element ≤ 999
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= maxVal; i++)
        while (count[i]--)
            arr[index++] = i;
}

int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter non-negative elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    countingSort(arr, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
