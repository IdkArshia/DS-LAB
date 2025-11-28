#include <iostream>
using namespace std;

void heapifyMin(int heap[], int n, int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && heap[left] < heap[smallest])
        smallest = left;

    if(right < n && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapifyMin(heap, n, smallest);
    }
}

void buildMinHeap(int heap[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyMin(heap, n, i);
}

void update_key(int heap[], int n, int i, int new_val)
{
    heap[i] = new_val;

    while(i != 0 && heap[(i-1)/2] > heap[i])
    {
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extractMin(int heap[], int &n)
{
    int root = heap[0];
    heap[0] = heap[n-1];
    n--;
    heapifyMin(heap, n, 0);
    return root;
}

void deleteKey(int heap[], int &n, int i)
{
    update_key(heap, n, i, -99999);
    extractMin(heap, n);
}

int main()
{
    int heap[] = {8,7,6,5,4};
    int n = 5;

    buildMinHeap(heap, n);

    update_key(heap, n, 2, 1);
    deleteKey(heap, n, 1);

    cout << "Final Heap: ";
    for(int i = 0; i < n; i++)
        cout << heap[i] << " ";

    return 0;
}
