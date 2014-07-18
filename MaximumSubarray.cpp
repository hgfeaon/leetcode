#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int cur_sum = 0;
        int max_sum = INT_MIN;
        
        for (int i=0; i<n; i++) {
            cur_sum += A[i];
            if (cur_sum > max_sum) max_sum = cur_sum;
            if (cur_sum < 0) {
                cur_sum = 0;
            }
        }
        return max_sum;
    }
    
    int maxSubArray_dc(int A[], int n) {
        return dfs(A, 0, n);
    }
    
    int dfs(int A[], int start, int end) {
        if (start >= end) {
            cout<<"range error: start="<<start<<", end="<<end<<endl;
            return INT_MIN;
        }
        if (start + 1 == end) return A[start];
        int mid = (start + end) / 2;
        int ma = dfs(A, start, mid);
        int mb = dfs(A, mid, end);
        int maxsum = ma > mb ? ma : mb;
        int lsum = 0, rsum = 0;
        int lmax = INT_MIN, rmax = INT_MIN;

        for (int i=mid - 1; i>=0; i--) {
            lsum += A[i];
            if (lsum > lmax) lmax = lsum;
        }

        for (int i=mid; i<end; i++) {
            rsum += A[i];
            if (rsum > rmax) rmax = rsum;
        }

        if (lmax + rmax > maxsum) maxsum = lmax + rmax;
        return maxsum;
    };
};

int main() {
    int A[] = {3,1,-2,2,2,1,-2,-3};
    int len = sizeof(A) / sizeof(int);

    Solution s;

    cout<<s.maxSubArray(A, len)<<endl;
    cout<<s.maxSubArray_dc(A, len)<<endl;
    system("pause");
	return 0;
}

