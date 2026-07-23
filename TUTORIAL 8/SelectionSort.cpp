#include <iostream>
using namespace std;

int main() {
    int A[6] = {18, 1, 2, 6, 0, 5};
    int n = 6;

    for (int i = 0; i < n - 1; i++) {
        int minj = i;
        int minx = A[i];

        for (int j = i + 1; j < n; j++) {
            if (A[j] < minx) {
                minj = j;
                minx = A[j];
            }
        }
        A[minj] = A[i];
        A[i] = minx;
    }

    for (int i = 0; i < n; i++) {
        cout << A[i] << ",";
    }
    cout << "\n";

    return 0;
}