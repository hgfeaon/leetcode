#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int wpos = 1;
        int dups = 0;
        int cur, last = A[0];
        
        for (int i=1; i<n; i++) {
            cur = A[i];
            dups = (cur == last) ? dups + 1 : 0;
            if (dups <= 1) {
                A[wpos++] = cur;
            }
            last = cur;
        }
        return wpos;
    }
};

int main() {
    int a[] = {1,1,1,1,2,2,3,3,3};
    
    int n = sizeof(a) / sizeof(int);
    
    Solution s;
    
    int newlen = s.removeDuplicates(a, n);
    
    for (int i=0; i<newlen; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

	system("pause");
	return 0;
}

