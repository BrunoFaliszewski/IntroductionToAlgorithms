#include <iostream>
#include <cmath>

using namespace std;

auto findMaxCrossingSubarray(int arr[], int low, int mid, int high) {
    struct returnVals {
        int maxLeft, maxRight, sum;
    };
    int leftSum = arr[mid] - 1;
    int sum = 0;
    int maxLeft;
    for (int i=mid; i>=low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }
    int rightSum = arr[mid+1] - 1;
    sum = 0;
    int maxRight;
    for (int i=mid+1; i<=high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }
    return returnVals {maxLeft, maxRight, leftSum+rightSum};
}

auto findMaxSubarray(int arr[], int low, int high) {
    struct returnVals {
        int low, high, sum;
    };
    if (low==high) {
        return returnVals {low, high, arr[low]};
    }

    int mid = floor((high+low)/2);
    auto [leftLow, leftHigh, leftSum] = findMaxSubarray(arr, low, mid);
    auto [rightLow, rightHigh, rightSum] = findMaxSubarray(arr, mid+1, high);
    auto [crossLow, crossHigh, crossSum] = findMaxCrossingSubarray(arr, low, mid, high);

    if (leftSum >= rightSum && leftSum >= crossSum) {
        return returnVals {leftLow, leftHigh, leftSum};
    } else if (rightSum >= leftSum && rightSum >= crossSum) {
        return returnVals {rightLow, rightHigh, rightSum};
    } else {
        return returnVals {crossLow, crossHigh, crossSum};
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    auto [maxLeft, maxRight, sum] = findMaxSubarray(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
    cout << maxLeft << " " << maxRight << " " << sum;

}