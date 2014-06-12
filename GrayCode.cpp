#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		res.push_back(0);

		long pow2 = 1;
		for (int i=1; i <= n; i++) {
			int old_len = res.size();
			for (int i=0; i<old_len; i++) {
				res.push_back(pow2 + res[old_len - i - 1]);
			}
			pow2<<=1;
		}
		return res;
    }
};

void print(vector<int>& list) {
	for (int i=0; i<list.size(); i++) {
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

int main() {
	Solution s;
	vector<int> res = s.grayCode(3);
	print(res);
	return 0;
}
