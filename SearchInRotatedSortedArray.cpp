#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        if (n < 1) return -1;
        
        int left = -1, right = n, mid;
        int last = A[n-1];
        while (left + 1 < right) {
            mid = (right + left) / 2;
            if (A[mid] < last) {
                right = mid;
            } else if (A[mid] > last) {
                left = mid;
            } else {
                right = mid; // only when n == 1
            }
        }
        
        if (last > target) {
            right = n;
        } else if (last < target){
            left = -1;
        } else {
            return n-1;
        }
        while(left + 1 < right) {
            mid = (right + left) / 2;
            if (A[mid] < target) {
                left = mid;
            } else if (A[mid] > target) {
                right = mid;
            } else {
                return mid;
            }
        }
        return -1; 
    }
};

int main() {

	system("pause");
	return 0;
}

