#include <iostream>
using namespace std;

void insertionSortDescending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        cout << "After iteration " << i << ": ";
        for (int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[5];
    cout << "Enter 5 integers:" << endl;

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    insertionSortDescending(arr, 5);

    cout << "Sorted array in descending order: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
