#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        return dfs(1, n);
    }
    
    int dfs(int start, int end) {
    	if (start >= end) return 1;
		int count = 0;
		// choose different number from [start, end] as the root
		for (int i = start; i <= end; i++) {
			// number of left tree cases * number of right tree cases
			count += dfs(start, i - 1) * dfs(i + 1, end); 
		}
		return count;
	}
};

int main() {
	Solution s;
	
	cout<<s.numTrees(3)<<endl;
	
	system("pause");
	return 0;
}

