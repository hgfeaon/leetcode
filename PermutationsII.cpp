#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
	public:
		vector<vector<int> > permuteUnique(vector<int> &num) {
			vector<vector<int> > result;
			if (num.size() < 1) return result;
			vector<int> path;
			dfs(num, 0, path, result);
		}

		void dfs(vector<int>& dict, int pos, vector<int>& path, vector<vector<int> > &result) {
			int len = dict.size();
			if (pos >= len) {
				result.push_back(path);
				return;
			}
			unordered_set<int> uniques;
			for (int i=pos; i<len; i++) {
				if (i != pos && uniques.count(dict[i]) > 0) continue;
				uniques.insert(dict[i]);
				path.push_back(dict[i]);
				
				int tmp = dict[i];
				dict[i] = dict[pos];
				dict[pos] = tmp;
				
				dfs(dict, pos + 1, path, result);
				path.pop_back();

				tmp = dict[i];
				dict[i] = dict[pos];
				dict[pos] = tmp;
			}
		}

		vector<vector<int> > permuteUnique2(vector<int> &num) {
			vector<vector<int> > res;
			sort(num.begin(), num.end());
			do {
				res.push_back(num);
			} while (next_permutation(num.begin(), num.end()));
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
	int nums[] = {1, 1, 2};
	vector<int> num(nums, nums + sizeof(nums) / sizeof(nums[0]));
	print(num);
	cout<<"----"<<endl;
	Solution s;
	vector<vector<int> > res = s.permuteUnique2(num);
	
	for (int i=0; i < res.size(); i++) {
		print(res[i]);
	}
	return 0;
}
