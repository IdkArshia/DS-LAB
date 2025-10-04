#include <iostream>
using namespace std;

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int insertSorted(int arr[], int& n, int value, int capacity) {
    if (n >= capacity) return -1;
    int i = n - 1;
    while (i >= 0 && arr[i] > value) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = value;
    n++;
    return i + 1;
}

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[100] = {12, 7, 90, 25, 33, 18, 41};
    int n = 7, capacity = 100;
    int value = 47;

    sortArray(arr, n);
    int index = binarySearch(arr, n, value);
    if (index == -1) insertSorted(arr, n, value, capacity);

    index = binarySearch(arr, n, value);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\nValue " << value << " found at index: " << index << endl;

    return 0;
}
