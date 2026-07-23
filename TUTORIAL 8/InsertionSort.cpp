#include <iostream>
using namespace std;

int main() {
    int T[6] = {18, 1, 2, 6, 0, 5};
    int n = 6;

    for (int i = 1; i < n; i++) {
        int x = T[i];
        int j = i - 1;

        while (j >= 0 && x < T[j]) {
            T[j + 1] = T[j];
            j = j - 1;
        }
        T[j + 1] = x;
    }

    for (int i = 0; i < n; i++) {
        cout << T[i] << ",";
    }
    cout << "\n";

    return 0;
}