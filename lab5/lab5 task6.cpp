#include <iostream>
using namespace std;
int recursiveArraySum(void** arr, int* sizes, int dim) {
    int sum = 0;
    if (dim == 1) {
        int* intArr = (int*)arr;
        for (int i = 0; i < sizes[0]; i++) {
            sum += intArr[i];
        }
    } else {
        for (int i = 0; i < sizes[0]; i++) {
            sum += recursiveArraySum((void**)arr[i], sizes + 1, dim - 1);
        }
    }
    return sum;
}
int main() {
    int* row1 = new int[2]{1, 2};
    int* row2 = new int[3]{3, 4, 5};
    void** arr2D = new void*[2];
    arr2D[0] = row1;
    arr2D[1] = row2;
    int sizes[] = {2, 3};
    int total = recursiveArraySum(arr2D, sizes, 2);
    cout << "Total sum of elements: " << total << endl;
    delete[] row1;
    delete[] row2;
    delete[] arr2D;
}
