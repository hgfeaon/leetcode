#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
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
    }
};

int main() {
    int g[] = {5};
    int c[] = {5};
    int len = sizeof(g) / sizeof(g[0]);
    vector<int> gas(g, g + len);
    vector<int> cost(c, c + len);
    
    Solution s;
    cout<<s.canCompleteCircuit(gas, cost)<<endl;
    
	system("pause");
	return 0;
}

