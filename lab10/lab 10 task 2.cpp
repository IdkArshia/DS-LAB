#include <iostream>
using namespace std;

void heapifyMin(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;

    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);
}

bool isMinHeap(int arr[], int n)
{
    for(int i = 0; i <= (n-2)/2; i++)
    {
        if(arr[i] > arr[2*i+1] || (2*i+2 < n && arr[i] > arr[2*i+2]))
            return false;
    }
    return true;
}

int extractMin(int arr[], int &n)
{
    int root = arr[0];
    arr[0] = arr[n-1];
    n--;
    heapifyMin(arr, n, 0);
    return root;
}

void heapSortAscending(int arr[], int n)
{
    buildMinHeap(arr, n);

    int size = n;
    for(int i = 0; i < size; i++)
        arr[i] = extractMin(arr, n);
}

int main()
{
    int arr[] = {3,5,9,6,8};
    int n = 5;

    if(isMinHeap(arr, n))
        cout << "Valid Min Heap\n";
    else
        cout << "Not a Min Heap\n";

    heapSortAscending(arr, n);

    cout << "Sorted Array: ";
    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}
