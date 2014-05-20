#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
<<<<<<< HEAD
    	int len = gas.size();
    	if (cost.size() != len || len < 1) return -1;
		int sum = 0;
		vector<int> diff(len, 0); 
		for (int i=0; i<len; i++) {
			diff[i] = gas[i] - cost[i];
		}
		int pos = 0;
		int walk= len;
		while (pos < len && diff[pos] < 0) pos++;
		if (pos == len) return -1;
		
		while (walk > 0) {
			pos = (--pos + len) % len;
			if (diff[pos] < 0) {
				if (sum > 0) sum = 0;
				sum += diff[pos];
				diff[pos] = 0;
			} else if (sum < 0){
				sum += diff[pos];
				if (sum < 0) diff[pos] = 0;
			}
			walk--;
		}
=======
        int len = gas.size();
        if (len < 1 || len != cost.size()) return -1;
        vector<int> diff(len, 0);
        for (int i=0; i<len; i++) {
            diff[i] = gas[i] - cost[i];
        }
        int p = len - 1;
        int q = 0;
        
        int sum = diff.back();
        int walk= len - 1;
        
        while (walk > 0) {
            while (walk > 0 && sum + diff[q] >= 0) {
                sum += diff[q++];
                walk--;
            }
            while (walk > 0 && sum + diff[q] < 0) {
                sum += diff[--p];
                walk--;
            }
        }
        if (sum < 0) return -1;
        return p == q ? p : -1;
>>>>>>> bff3f237d49e125c56e3a4543cdab7eba45f3596
    }
};

int main() {
<<<<<<< HEAD

=======
    int g[] = {5};
    int c[] = {5};
    int len = sizeof(g) / sizeof(g[0]);
    vector<int> gas(g, g + len);
    vector<int> cost(c, c + len);
    
    Solution s;
    cout<<s.canCompleteCircuit(gas, cost)<<endl;
    
>>>>>>> bff3f237d49e125c56e3a4543cdab7eba45f3596
	system("pause");
	return 0;
}

