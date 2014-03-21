#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        vector<pair<int, int> > nums;
        for (int i=0; i<numbers.size(); i++) {
            nums.push_back(make_pair(numbers[i], i+1));
        }
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;
        int sum = 0;
        while(i<j) {
            sum = nums[i].first + nums[j].first;
            if (sum > target) {
                j--;
            } else if (sum < target) {
                i++;
            } else {
                break;
            }
        }
        ret.push_back(nums[i].second);
        ret.push_back(nums[j].second);
        sort(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    int data[] = {2, 7, 11, 15};
    Solution s;
    vector<int> nums(data, data+sizeof(data)/sizeof(int));
    vector<int> ret = s.twoSum(nums, 9);
    cout<<ret[0]<<","<<ret[1]<<endl;
	system("pause");
	return 0;
}

