#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows, cols;
        if (!(rows = matrix.size()) || !(cols = matrix[0].size())) return false;
        int ridx, cur, first = -1, last = rows;
        while (first + 1 < last) {
            ridx = (first + last) / 2;
            cur = matrix[ridx][0];
            if (cur < target) {
                first = ridx;
            } else if (cur > target) {
                last = ridx;
            } else {
                break;
            }
        }
        if (first + 1 == last) {
            ridx = first;
        } else {
            return true;
        }
        if (ridx < 0 || ridx >= rows) return false;
        return binary_search(matrix[ridx].begin(), matrix[ridx].end(), target);
    }
    
    bool _searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows, cols;
        if (!(rows = matrix.size()) || !(cols = matrix[0].size())) return false;
        int first = 0, last = rows * cols - 1;
        while (first <= last) {
            int mi = (first + last) / 2;
            int mv = matrix[mi / cols][mi % cols];
            if (mv > target) {
                last = mi - 1;
            } else if (mv < target) {
                first= mi + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int mat[] = { 1,   3,  5,  7,
                10, 11, 16, 20,
                23, 30, 34, 50};
    int rown = 3;
    int coln = 4;
    vector<vector<int> > matrix;
    for (int i=0; i<rown; i++) {
        matrix.push_back(vector<int>(mat+i*coln, mat+i*coln + coln));
    }
    Solution s;
    cout<<s._searchMatrix(matrix, 50)<<endl;
	system("pause");
	return 0;
}

