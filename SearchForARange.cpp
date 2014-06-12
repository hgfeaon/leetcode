#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	int getDirection(int A[], int idx, int target, bool isDefaultBack) {
		int r = A[idx] - target;
		if (r == 0) {
			r = isDefaultBack ? -1 : 1;
		}
		return r;
	}
	int getFirstValueIndex(int A[], int n, int target, bool isFromBack) {
		int p = -1;
		int q = n;
		while (p + 1 < q) {
			int mid_idx = (p + q) / 2;
			int where = getDirection(A, mid_idx, target, isFromBack);
			if (where < 0) {
				p = mid_idx;
			} else {
				q = mid_idx;
			}
		}
		if (p != -1 && A[p] != target) {
			p = -1;
		}
		if (q == n || A[q] != target) {
			q = -1;
		}
		return isFromBack ? p : q;
	}
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> res;
		res.push_back(getFirstValueIndex(A, n, target, false));
		res.push_back(getFirstValueIndex(A, n, target, true));
		return res;
	}
};

int main() {
	int A[] = {2, 2};
	Solution s;
	vector<int> res = s.searchRange(A, sizeof(A) / sizeof(int),3);
	cout<<"["<<res[0]<<", "<<res[1]<<"]"<<endl;
	return 0;
}
