#include <iostream>
#include <cmath>

using namespace std;

void merge(int arr[], int p, int q, int r) {
    const int n1 = q - p + 1;
    const int n2 = r - q;
    int L[n1];
    int P[n2];
    for (int i=0; i<n1; i++) {
        L[i] = arr[p+i];
    }
    for (int i=0; i<n2; i++) {
        P[i] = arr[i+q+1];
    }
    int i = 0;
    int j =0;
    int k = p;
    while (i<n1 && j<n2) {
        if (L[i] <= P[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = P[j];
            j++;
        }
        k++;
    }
    while (i<n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j<n2) {
        arr[k] = P[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int p, int r) {
    if (p>=r) {
        return;
    }

    int q = floor((p+r)/2);
    mergeSort(arr, p, q);
    mergeSort(arr, q+1, r);
    merge(arr, p, q, r);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arr[] = {10, 20, 4, 23, 3, 5};
    mergeSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
    for (int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }
}