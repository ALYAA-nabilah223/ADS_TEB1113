#include <iostream>
using namespace std;

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (i <= high && A[i] <= pivot);

        do {
            j--;
        } while (A[j] > pivot);

        if (i >= j) {
            break;
        }

        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main() {
    int A[6] = {18, 1, 2, 6, 0, 5};
    int n = 6;

    quickSort(A, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << A[i] << ", ";
    }
    cout << "\n";

    return 0;
}