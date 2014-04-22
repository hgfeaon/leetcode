#include <iostream>
#include <cstdlib>

class Solution {
public:
    int singleNumber(int A[], int n) {
        int tmp = A[0];
        for (int i=1; i<n; i++) {
            tmp ^= A[i];
        }
        return tmp;
    }
};

int main() {

	system("pause");
	return 0;
}

