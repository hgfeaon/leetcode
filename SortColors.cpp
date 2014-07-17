#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int cnt[3] = {0};
        for (int i = 0; i < n; i++) {
            cnt[A[i]]++;
        }
        int start = 0;
        for (int i=0; i<3; i++) {
            if (i > 0) start += cnt[i-1];
            for (int j=start; j < start + cnt[i]; j++) {
                A[j] = i;
            }
        }
    }
};

int main() {

    int A[] = {1, 2, 0, 1};
    int len = sizeof(A) / sizeof(int);

    Solution s;
    s.sortColors(A, len);
    
    for (int i=0; i<len; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
	system("pause");
	return 0;
}

