#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // std::next_permutation(num.begin(), num.end());
        // return;
        if (num.size() < 2) return;
        int i = num.size() - 2;
        while (i>=0 && (num[i] >= num[i+1])) i--;
        if (i >= 0) {
            int p = num.size() - 1;
            while (p >= 0 && num[p] <= num[i]) p--;
            int t = num[i];
            num[i] = num[p];
            num[p] = t;
        }
        reverse(num.begin() + i + 1, num.end());
    }
};

int main() {
    
    int nums[] = {1, 2, 3};
    vector<int> num(nums, nums + sizeof(nums) / sizeof(int));
    
    Solution s;
    s.nextPermutation(num);
    
    for (int i=0; i<num.size(); i++) cout<<num[i]<<",";
    cout<<endl;
    
    system("pause");    
    return 0;
}


