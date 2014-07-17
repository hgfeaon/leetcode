#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    vector<long> sum;
    vector<long> step;
    set<int> can;
public:
    int jump(int A[], int n) {
        step.clear(), sum.clear(), can.clear();
        step.resize(n, INT_MAX), sum.resize(n, 0);
        
        int jmp = A[0];
        can.insert(n - 1);
        step[n - 1] = 0;
        
        for (int i = n - 2; i>= 0; i--) {
            jmp = A[i];
            if (i + jmp >= n - 1) {
                sum[i] = sum[i + 1] + 1;
                can.insert(i);
                continue;
            }
            int region = sum[i + 1] - sum[i + jmp + 1];
            if (region > 0) {
                sum[i] = sum[i + 1] + 1;
                can.insert(i);
            } else {
                sum[i] = sum[i + 1];
            }
        }

        if (can.size() > 1 && (jmp >= n-1 || sum[0] - sum[jmp] > 0)) {
            can.insert(0);
        }

        int cur_jmp_to;
        int pre_jmp_to = n-1 + A[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            cur_jmp_to = i + A[i];
            int min_step = INT_MAX;

            if (cur_jmp_to >= pre_jmp_to) {
                min_step = step[i + 1] - 1;
                if (min_step < 0) min_step = 0;
                for (int j = pre_jmp_to; j < n && j <= cur_jmp_to; j++) {
                    if (step[j] < min_step) min_step = step[j];
                }
            } else if (A[i] > 0) {
                set<int>::iterator lower = can.lower_bound(i+1);
                set<int>::iterator upper = can.upper_bound(cur_jmp_to);
                while (lower != upper) {
                    if (step[*lower] < min_step) min_step = step[*lower];
                    lower++;
                }
            }
            step[i] = min_step == INT_MAX ? INT_MAX : min_step + 1;
            pre_jmp_to = cur_jmp_to;
        }
        
        return step[0];
    }
};

class SolutionBetter {
public:
    int jump(int A[], int n) {
        if (A == nullptr || n <= 0) {
            return -1;
        } else if (n == 1) {
            return 0;
        }

        int last_pos, this_pos;
        int i;
        int result;

        last_pos = 0;
        this_pos = 0;
        result = 0;
        for (i = 0; this_pos < n - 1; ++i) {
            if (i > this_pos) {
                return -1;
            }
            if (i + A[i] > this_pos) {
                if (i > last_pos) {
                    last_pos = this_pos;
                    ++result;
                }
                this_pos = i + A[i];
            }
        }

        return result + 1;
    }
};

int main() {
    int A[] = {1, 1, 2, 1, 1};
    int len = sizeof(A) / sizeof(int);

    Solution s;

    cout<<s.jump(A, len)<<endl;

    system("pause");
	return 0;
}

