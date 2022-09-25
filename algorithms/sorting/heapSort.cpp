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

void buildMaxHeap(vector<int>& arr) {
    int n = arr.size()-1;
    for (int i=floor(arr.size()/2)-1; i>=0;i--) {
        maxHeapify(arr, n, i);
    }
}

void heapsort(vector<int>& arr) {
    buildMaxHeap(arr);
    int n = arr.size()-1;
    for (int i=arr.size()-1; i>0; i--) {
        swap(arr[0], arr[i]);
        n--;
        maxHeapify(arr, n, 0);
    }
}

int main() {

    vector<int> arr = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    heapsort(arr);
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }

}