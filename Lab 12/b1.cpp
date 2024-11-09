#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int arr[9];
    cout << "Enter 9 integers:" << endl;

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, 9);

    cout << "Sorted array: ";
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
