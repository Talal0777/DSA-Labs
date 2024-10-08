#include <iostream>
using namespace std;
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

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Enter the Target value: "<<endl;
	cin>>target; 
    cout << "Target value: " << target <<endl;
    int result = binarySearchLast(arr, n, target);
    if (result != -1) {
       cout << "Last occurrence of target value found at index " << result <<endl;
    } else {
       cout << "Target value not found" <<endl;
    }
    return 0;
}
