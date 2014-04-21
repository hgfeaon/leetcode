#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int> > result;
public:
    vector<vector<int> > permute(vector<int> &num) {
    	result.clear();
    	dfs(num, 0);
    	return result;
    }
    
    void dfs(vector<int>& num, int idx) {
		int tmp;
		int len = num.size();
		if (len == idx + 1) {
			result.push_back(num);
			return;
		}
		for (int i=idx; i<len; i++) {
			tmp = num[idx];
			num[idx] = num[i];
			num[i] = tmp;
			dfs(num, idx + 1);
			tmp = num[idx];
			num[idx] = num[i];
			num[i] = tmp;
		}
	}
};

void print(vector<vector<int> >& res) {
	for (int i=0; i<res.size(); i++) {
		for (int j=0; j<res[i].size(); j++) {
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

}

int main() {
	int elems[] = {1, 1, 1};
	
	vector<vector<int> > res;
	vector<int> elements(elems, elems + sizeof(elems) / sizeof(int));
	
	Solution s;
	res = s.permute(elements);
	
	print(res);
	
	system("pause");
	return 0;
}

