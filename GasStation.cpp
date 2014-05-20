#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
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
    }
};

int main() {

	system("pause");
	return 0;
}

