#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n < 1) return false;
        int pre = A[0];
        int wpos = 1, rpos = 1;
        while (rpos < n) {
            if (A[rpos] == pre) {
                rpos++;
            } else {
                pre = A[wpos++] = A[rpos++];
            }
        }
        n = wpos;
        
        int sep = A[n-1];
        int left = -1, right = n;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (sep > A[mid]) {
                right = mid;
                sep = A[mid];
            } else if (sep < A[mid]) {
                left = mid;
            } else {
                right = mid;
                break;
            }
        }
        return binary_search(A, right, target) || binary_search(A + right, n - right, target);
    }
    
    bool binary_search(int *a, int n, int target) {
        int left = -1, right = n;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (a[mid] > target) {
                right = mid;
            } else if (a[mid] < target) {
                left = mid;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int array[] = {1,1,1,1,1};
    int len = sizeof(array) / sizeof(array[0]);
    Solution s;
    for (int i=0; i<len; i++) {
        cout<<"search ["<<i<<"] = "<<s.search(array, len, array[i])<<endl;
    }
    cout<<s.search(array, len, 1000)<<endl;
	system("pause");
	return 0;
}

