#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if (len < 2) return 0;

        vector<int> i2r(len, 0);
        vector<int> i2l(len, 0);

        int max_price = prices[len - 1];

        for (int i=len-2; i>=0; i--) {
            if (prices[i] > max_price) max_price = prices[i];
            int cp = max_price - prices[i];
            i2r[i] = cp > i2r[i + 1] ? cp : i2r[i + 1];
        }

        int min_price = prices[0];

        for (int i=1; i<len; i++) {
            if (prices[i] < min_price) min_price = prices[i];
            int cp = prices[i] - min_price;
            i2l[i] = cp > i2l[i - 1] ? cp : i2l[i - 1];
        }


        int mp = 0;

        for (int i=0; i<len; i++) {
            int p = i2l[i] + i2r[i + 1 >= len ? len - 1 : i + 1];
            if (p > mp) mp = p;
        }

        return mp;
    }
};
int main() {
    int P[] = {1, 2};
    int n = sizeof(P) / sizeof(int);

    vector<int> prices(P, P+n);

    Solution s;
    cout<<s.maxProfit(prices)<<endl;
    
	system("pause");
	return 0;
}

