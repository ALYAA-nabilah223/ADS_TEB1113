#include <iostream>
#include <algorithm> // For std::max
#include <climits>   // For INT_MIN

using namespace std;


const int N = 5;

int findMaxValue(int mat[N][N]) {
    
    int max_diff = INT_MIN;

    
    int max_mat[N][N];

    // 1. Initialize the very last cell (bottom-right corner)
    max_mat[N-1][N-1] = mat[N-1][N-1];

    // 2. Pre-fill the last row (can only look to its right)
    for (int j = N - 2; j >= 0; j--) {
        max_mat[N-1][j] = max(mat[N-1][j], max_mat[N-1][j+1]);
    }

    // 3. Pre-fill the last column (can only look downwards)
    for (int i = N - 2; i >= 0; i--) {
        max_mat[i][N-1] = max(mat[i][N-1], max_mat[i+1][N-1]);
    }

    // 4. Fill the rest of the max_mat from bottom to top, right to left
    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - 2; j >= 0; j--) {
            
            // Update our max_diff using the valid submatrix down-right from here
            // The closest valid top-left element for a submatrix is at (i+1, j+1)
            int current_diff = max_mat[i+1][j+1] - mat[i][j];
            if (current_diff > max_diff) {
                max_diff = current_diff;
            }

            // Update max_mat[i][j] for future elements further up/left to use
            max_mat[i][j] = max({ mat[i][j], 
                                  max_mat[i+1][j], 
                                  max_mat[i][j+1] });
        }
    }

    return max_diff;
}

int main() {
    // The exact input from your image
    int mat[N][N] = {
        { 1,  2, -1, -4, -20 },
        {-8, -3,  4,  2,   1 },
        { 3,  8,  6,  1,   3 },
        {-4, -1,  1,  7,  -6 },
        { 0, -4, 10, -5,   1 }
    };

    cout << "Maximum value is: " << findMaxValue(mat) << endl;

    return 0;
}