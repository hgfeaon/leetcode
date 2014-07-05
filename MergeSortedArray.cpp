#include <iostream>

using namespace std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int mi = m + n - 1;
		int ai = m - 1;
		int bi = n - 1;
		while (ai >= 0 && bi >= 0) {
			if (A[ai] >= B[bi]) {
				A[mi--] = A[ai--];
			} else {
				A[mi--] = B[bi--];
			}
		}
		while (ai >= 0) {
			A[mi--] = A[ai--];
		}
		while (bi >= 0) {
			A[mi--] = B[bi--];
		}
	}
};

void print(int array[], int n) {
	for (int i=0; i<n; i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl;
}  

int main() {
	int A[] = {1, 3, 6, 10, 0, 0, 0};
	int B[] = {2, 9, 11};

	Solution s;
	print(A, 4);
	print(B, 3);
	s.merge(A, 4, B, 3);
	print(A, 7);
	return 0;
}
