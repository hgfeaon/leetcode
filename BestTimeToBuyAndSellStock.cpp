#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int len = prices.size();
    	if (len < 1) return 0;
		int minv = prices[0];
		int maxv = prices[0];
		int mprofit = 0;
		for (int i=1; i<len; i++) {
			int cur = prices[i];
			if (cur < minv) {
				minv = cur;
				maxv = cur;
			}
			if (cur > maxv) {
				maxv = cur;
				if (maxv - minv > mprofit) mprofit = maxv - minv;
			}
		}
		
		return mprofit;        
    }
    
    int maxProfit_dp(vector<int> &prices) {
		int len = prices.size();
		if (len < 2) return 0;
		vector<int> maxv(len, 0);
		maxv[len - 1] = prices.back();
		for (int i = len - 2; i>=0; i--) {
			if (prices[i] > maxv[i + 1]) {
				maxv[i] = prices[i];
			} else {
				maxv[i] = maxv[i + 1];
			}
		}
		int mprofit = 0;
		for (int i=0; i<len; i++) {
			int profit = maxv[i] - prices[i];
			if (profit > mprofit) mprofit = profit;
		}
		return mprofit;
	}
};

int main() {
	int ps[] = {3,2,6,5,0,3};
	int len = sizeof(ps) / sizeof(ps[0]);
	vector<int> prices(ps, ps + len);
	Solution s;
	cout<<s.maxProfit(prices)<<endl;
	cout<<s.maxProfit_dp(prices)<<endl;
	system("pause");
	return 0;
}

