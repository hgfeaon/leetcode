#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        sort(A, A+n);
        int last = A[0];
        int time = 1;
        for (int i=1; i<n; i++) {
            if (last != A[i]) {
                if(time == 3) {
                    time = 1;
                    last = A[i];
                    continue;
                }
                return last;
            }
            time++;
        }
        if (time != 3) return last;
    }
};

int main() {
    int arr[] = {-2,-2,-2,1,1};
    Solution s;
    cout<<s.singleNumber(arr, sizeof(arr) / sizeof(int))<<endl;
	system("pause");
	return 0;
}

