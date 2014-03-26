#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
		int *rpos = A, *wpos = A + 1, *end = A + n;
		int cur;
        int pre = *(rpos++);
        while (rpos != end) {
        	cur = *(rpos++);
			if (pre == cur) continue;
			*(wpos++) = pre = cur;
		}
        return n - (rpos - wpos);
    }
};

int main() {
	int array[] = {0, 1, 2,3};
	Solution s;
	
	int newsize = s.removeDuplicates(array, sizeof(array)/sizeof(int));
	for (int i=0; i<newsize; i++) {
		cout<<array[i]<<",";
	}
	
	system("pause");
	return 0;
}

