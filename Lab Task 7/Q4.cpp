#include <iostream>
using namespace std;

int binarySearchFirst(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int binarySearchLast(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int binarySearchCount(int arr[], int n, int target) {
    int firstOccurrence = binarySearchFirst(arr, n, target);
    if (firstOccurrence == -1) {
        return 0;
    }
    int lastOccurrence = binarySearchLast(arr, n, target); 
    return lastOccurrence - firstOccurrence + 1;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    cout << "Target value: " << target << endl;
    int count = binarySearchCount(arr, n, target);
    cout << "Number of occurrences: " << count << endl;
    return 0;
}