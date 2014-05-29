#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
		k--;
		if (n < 1 || k < 0) return "";

    	vector<int> nums(n, 0);
		long seg = 1;
		for (int i=0; i<n; i++) {
			nums[i] = i + 1;
			seg = seg * (nums[i]);
		}
		if (k >= seg) return "";	
		int idx = 0;

		for (int i=0; i < n-1; i++) {
			seg = seg / (n - i);
			idx = k / seg + i;
			k = k % seg;

			int sel = nums[idx];

			for (int j = idx; j>i; j--) {
				nums[j] = nums[j - 1];
			}

			nums[i] = sel;
		}
		string res;
		for (int i=0; i<n; i++) {
			res.push_back((char)(nums[i] + '0'));
		}
		return res;
    }
};

int main() {
	Solution s;
	cout<<s.getPermutation(4, 3)<<endl;
	return 0;
}
