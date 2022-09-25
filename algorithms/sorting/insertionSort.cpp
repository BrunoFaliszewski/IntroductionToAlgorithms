#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int j=1; j<n; j++) {
        int key = arr[j];
        int i = j - 1;
        while (i>=0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arr[] = {10, 20, 4, 23, 15, 3};

    insertionSort(arr, sizeof(arr)/sizeof(arr[0]));

    for (int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }
}