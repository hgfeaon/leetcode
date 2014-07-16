#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        if (A == NULL || n < 1) return false;

        vector<int> sum(n, 0);

        sum[n-1] = 0;
        int jump = A[n-1];

        for (int i=n-2; i>=0; i--) {
            jump = A[i];
            if (i + jump >= n - 1) {
                sum[i] = sum[i+1] + 1;
                continue;
            }
            int region = sum[i + 1] - sum[i + jump + 1];

            sum[i] = sum[i+1] + (region > 0);
        }

        if (jump >= n-1) {
            return true;
        } else {
            return sum[0] - sum[jump] > 0;
        }
    }
};

int main() {
    int A[] = {2, 3, 1, 1, 4};
    int len = sizeof(A) / sizeof(int);
    
    Solution s;
    cout<<s.canJump(A, len)<<endl;

    system("pause");
	return 0;
}

