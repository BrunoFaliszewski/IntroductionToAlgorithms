#include <iostream>
#include <cmath>
#include <random>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> arr1, vector<int> arr2) {
    int n = arr1.size();
    for (int j=1; j<n; j++) {
        int key1 = arr1[j];
        int key2 = arr2[j];
        int i = j - 1;
        while (i>=0 && arr1[i] > key1) {
            arr1[i+1] = arr1[i];
            arr2[i+1] = arr2[i];
            i--;
        }
        arr1[i+1] = key1;
        arr2[i+1] = key2;
    }
    return arr2;
}

vector<int> permute(vector<int> arr) {
    int n = arr.size();
    random_device os_seed;
    const uint_least32_t seed = os_seed();
    mt19937 generator(seed);
    uniform_int_distribution<uint_least16_t> distribute(1, pow((double)n,3.0));

    vector<int> P(n);
    for (int i=0; i<n; i++) {
        P[i] = (int)distribute(generator);
    }
    arr = insertionSort(P, arr);
    return arr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    arr = permute(arr);

    for (int i = 0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
}