#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int left(int i) {
    return 2*(i+1)-1;
}

int right(int i) {
    return 2*(i+1);
}

int parent(int i) {
    return floor((i+1)/2)-1;
}

void maxHeapify(vector<int>& arr, int n, int i) {
    int l = left(i);
    int r = right(i);
    int max = 0;

    if (l<=n && arr[l]>arr[i]) {
        max = l;
    } else {
        max = i;
    }
    if (r<=n && arr[r]>arr[max]) {
        max = r;
    }

    if (max != i) {
        swap(arr[i], arr[max]);
        maxHeapify(arr, n, max);
    }
}

int maximum(vector<int>& arr) {
    return arr[0];
}

void increaseKey(vector<int>& arr, int i, int key) {
    if (key < arr[i]) {
        throw range_error("key is smaller than current one");
    }
    arr[i] = key;
    while (i>0 && arr[parent(i)]<arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void insert(vector<int>& arr, int& n, int key) {
    n++;
    arr[n] = key-1;
    increaseKey(arr, n-1, key);
}

int extractMaximum(vector<int>& arr, int& n) {
    if (n<1) {
        throw length_error("heap is too small");
    }
    int max = arr[0];
    arr[0] = arr[n-1];
    n--;
    maxHeapify(arr, n, 0);
    return max;
}

int main() {
    vector<int> arr = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int n = arr.size();
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    insert(arr, n, 15);
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}