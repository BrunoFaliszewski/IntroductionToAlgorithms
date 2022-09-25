#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector<int> randomize(vector<int> arr) {
    int n = arr.size();
    random_device os_seed;
    const uint_least32_t seed = os_seed();
    mt19937 generator(seed);

    for (int i=0; i<n; i++) {
        uniform_int_distribution<uint_least16_t> distribute(i, n-1);
        int key = arr[i];
        int randomI = distribute(generator);
        int randomKey = arr[randomI];

        arr[i] = randomKey;
        arr[randomI] = key;
    }

    return arr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    arr = randomize(arr);

    for (int i = 0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
}