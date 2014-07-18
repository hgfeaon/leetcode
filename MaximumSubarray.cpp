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
};

int main() {
    int A[] = {-2, -1, -3, 4, -1, 2, 1, -5, 4};
    int len = sizeof(A) / sizeof(int);

    Solution s;

    cout<<s.maxSubArray(A, len)<<endl;

    system("pause");
	return 0;
}

