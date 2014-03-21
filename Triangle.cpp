#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (!triangle.size() || !triangle[0].size()) return 0;

        int rows = triangle.size();
        int *ra = new int[rows];
        int *rb = new int[rows];
        int *tmp= NULL;
        int L, R;

        ra[0] = triangle[0][0];
        for (int i=1; i<rows; i++) {
            vector<int>& row = triangle[i];
            for (int j=0; j<=i; j++) {
                L = (j - 1) >= 0 ? ra[j-1] : INT_MAX;
                R = (j != i) ? ra[j] : INT_MAX;
                rb[j] = ((L < R) ? L : R) + row[j];
            }
            tmp = ra, ra = rb, rb = tmp;
        }

        int sum = INT_MAX;
        for (int i=0; i<rows; i++) {
            if (ra[i] < sum) sum = ra[i];
        }

        delete[] ra;
        delete[] rb;
        return sum;
    }
};


int main() {
    int data[] = {2,3,4,6,5,7,4,1,8,3};
    vector<vector<int> > tri;
    int sum = 0;

    for (int i=0; i<4; i++) {
        sum+=i;
        tri.push_back(vector<int>(data+sum, data+sum+i+1));
    }
    Solution s;

    cout<<s.minimumTotal(tri)<<endl;
    
	system("pause");
	return 0;
}

