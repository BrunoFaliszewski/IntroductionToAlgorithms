#include <iostream>
#include <vector>
#include <random>

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

int randomizedPartition(vector<int>& arr, int p, int r) {
    random_device os_seed;
    const uint_least32_t seed = os_seed();
    mt19937 generator(seed);
    uniform_int_distribution<uint_least16_t> distribute(p, r);
    int i = distribute(generator);
    swap(arr[r], arr[i]);
    
    return partition(arr, p, r);
}

void randomizedQuickSort(vector<int>& arr, int p, int r) {
    if (p<r) {
        int q = randomizedPartition(arr, p, r);
        randomizedQuickSort(arr, p, q-1);
        randomizedQuickSort(arr, q+1, r);
    }
}

int main() {
    vector<int> arr = {2, 8, 7, 1, 3, 5, 6, 4, 5, 1, 34, 52, 12, 65, 32, 6, 9, 10};
    randomizedQuickSort(arr, 0, arr.size()-1);
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
}