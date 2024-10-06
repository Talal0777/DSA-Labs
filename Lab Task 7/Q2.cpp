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

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    
    cout << "Given array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    int target;
    cout << "Enter the target from the given array: ";
    cin >> target;
    
    cout << "Target value: " << target << endl;

    
    int result = binarySearchFirst(arr, n, target);
    if (result != -1) {
        cout << "First occurrence of target value found at index " << result << endl;
    } else {
        cout << "Target value not found" << endl;
    }

    return 0;
}

