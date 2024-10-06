#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        cout << "Active items: ";
        for (int i = left; i <= right; i++) {
            if (i == mid) {
             cout << "[" << arr[i] << "] ";
            } else {
             cout << arr[i] << " ";
            }
        }
        cout <<endl;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    cout << "Target value: " << target <<endl;
    int result = binarySearch(arr, n, target);
    if (result != -1) {
       cout << "Target value found at index " << result <<endl;
    } else {
       cout << "Target value not found" <<endl;
    }
    delete[] arr;
    return 0;
}
