#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution{
    public:
        int maxArea(vector<int>& height) {
        int len = height.size(), low = 0, high = len -1 ;
        int maxArea = 0;
        while (low < high) {
            maxArea = max(maxArea, (high - low) * min(height[low], height[high]));
            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }
        return maxArea;
    }
};

int main() {
    int bars[] = {1, 2, 5, 3, 2, 9};
    vector<int> height(bars, bars + sizeof(bars) / sizeof(int));
    Solution s;
    
    cout<<s.maxArea(height)<<endl;
    
	system("pause");
	return 0;
}

