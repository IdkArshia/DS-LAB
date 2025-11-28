#include <iostream>
using namespace std;

void heapifyMax(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);
}

int kthLargest(int arr[], int n, int k)
{
    buildMaxHeap(arr, n);

    for(int i = 1; i < k; i++)
    {
        swap(arr[0], arr[n-i]);
        heapifyMax(arr, n-i, 0);
    }
    return arr[0];
}

int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = 7;
    int k = 3;

    cout << "Kth Largest = " << kthLargest(arr, n, k);

    return 0;
}
