#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int p, int r) {
    int x = arr[r];
    int i = p-1;
    for (int j=p; j<r; j++) {
        if (arr[j]<x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[r], arr[i+1]);
    return i+1;
}

void quickSort(vector<int>& arr, int p, int r) {
    if (p<r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}

int main() {
    vector<int> arr = {2, 8, 7, 1, 3, 5, 6, 4, 5, 1, 34, 52, 12, 65, 32, 6, 9, 10};
    quickSort(arr, 0, arr.size()-1);
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
}