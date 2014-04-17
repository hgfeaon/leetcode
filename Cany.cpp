#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

class Solution {
public:
    int _candy(vector<int> &ratings) {
        int len = ratings.size();
        if (len == 0) return 0;
        
        vector<P> rate_pos;
        vector<int> candy(len, 1);
        
        rate_pos.resize(len);
        
        for (int i=0; i<len; i++) {
            rate_pos[i] = make_pair(ratings[i], i);
        }
        
        sort(rate_pos.begin(), rate_pos.end());
        
        int total = 0;
        
        for (int i=0; i<len; i++) {
            int pos = rate_pos[i].second;
            int rat = rate_pos[i].first;
            
            if (pos > 0 && ratings[pos-1] < rat && candy[pos] <= candy[pos-1]) {
                candy[pos] = candy[pos-1] + 1;
            }
            if (pos < len-1 && ratings[pos+1] < rat && candy[pos] <= candy[pos+1]) {
                candy[pos] = candy[pos+1] + 1;
            }
            
            total += candy[pos];
        }
        return total;
    }
    
    int candy(vector<int> &ratings) {
        int len = ratings.size();
        if (len < 2) return len;
        vector<int> candy(len, 1);
        
        for (int i=1; i<len; i++) {
            if (ratings[i] > ratings[i-1]) {
                candy[i] = candy[i-1] + 1;
            }
        }
        
        for (int i=len-1; i>=1; i--) {
            if (ratings[i-1] > ratings[i] && candy[i-1] <= candy[i]) {
                candy[i-1] = candy[i] + 1;
            }
        }
        int total = 0;
        for (int i=0; i<len; i++) total += candy[i];
        
        return total;
    }
};

int main() {
    int rate[] = {1,2,2};

    vector<int> ratings(rate, rate + sizeof(rate) / sizeof(int));

    Solution s;
    
    cout<<s.candy(ratings)<<endl;

    system("pause");
	return 0;
}

