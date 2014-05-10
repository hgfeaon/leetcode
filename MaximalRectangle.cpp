#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void print_matrix(int* m, int rows, int cols) {
    for (int i=0; i<rows; i++) {

        for (int j = 0; j<cols; j++) {
            cout<<m[cols * i + j]<<" ";
        }
        cout<<endl;
    }
}

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        if (cols == 0) return 0;
        cols++;
        
        int* memo = new int[cols * cols];
        for (int i=cols * cols - 1; i>=0; i--) memo[i] = 0;
        for (int i=1; i<cols; i++) memo[i * cols + i - 1] = 1;
        
        int max_rect = 0;

        for (int i=0; i<rows; i++) {
            vector<char>& row = matrix[i];
            for (int j = 1; j<cols; j++) {
                int base = j * cols;
                for (int k = j; k<cols; k++) {
                    if (row[k - 1] == '1' && memo[base + k - 1] > 0) {
                        int cur_rect = ++memo[base + k] * (k - j + 1);
                        if (cur_rect > max_rect) max_rect = cur_rect;
                    } else {
                        memo[base + k] = 0;
                    }
                }
            }
            // cout<<endl;
            // print_matrix(memo, cols, cols);
        }
        delete[] memo;
        return max_rect;
    }
};

int main() {
    char mat[][4] =  {
                        {'1', '1', '0', '1'},
                        {'1', '1', '1', '0'},
                        {'1', '1', '0', '1'},
                        {'0', '1', '1', '0'}
                    };
    vector<vector<char> > matrix;
    int rows = sizeof(mat) / sizeof(mat[0]);
    int cols = sizeof(mat[0]) / sizeof(mat[0][0]);
    for (int i=0; i<rows; i++) {
        matrix.push_back(vector<char>(mat[i], mat[i] + cols));
    }
    Solution s;
    cout<<s.maximalRectangle(matrix)<<endl;
	system("pause");
	return 0;
}

