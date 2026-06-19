/#include <iostream>
#include <iterator>

using namespace std;


bool searchInMatrix(int mat[3][3], int rows, int cols, int x) {
  
    int i = 0;
    int j = cols - 1;


    while (i < rows && j >= 0) {
        if (mat[i][j] == x) {
            return true; 
        }
        else if (mat[i][j] > x) {
            
            j--; 
        } 
        else {
          
            i++; 
        }
    }

   
    return false;
}

int main() {
    
    int mat[3][3] = {
        {3, 30, 38},
        {20, 52, 54},
        {35, 60, 69}
    };
    
   
    auto rows = size(mat);
    auto cols = size(mat[0]);
    
    int x = 62;

    
    if (searchInMatrix(mat, rows, cols, x)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    
    int target2 = 35;
    cout << "Searching for " << target2 << ": " 
         << (searchInMatrix(mat, rows, cols, target2) ? "true" : "false") << endl;

    return 0;
}