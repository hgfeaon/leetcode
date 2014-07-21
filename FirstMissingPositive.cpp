#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (A == NULL || n < 1) return 1;

        size_t len = (size_t)n + 1;
        vector<bool> bits(len, false);
        for (int i=0; i<n; i++) {
            if (A[i] < 0 || A[i] > n) continue;
            bits[A[i]] = true;
        }
        int miss = 1;
        while (miss <= INT_MAX) {
            if (!bits[miss]) return miss;
            if (miss == INT_MAX) {
                cout<<"no missing positive"<<endl;
                break;
            }
            miss++;
        }
        bits.clear();
        return 0;
    }
    
    int firstMissingPositive2(int A[], int n) {
        if (A == NULL || n < 1) return 1;

        unordered_map<int, int> mark;
        for (int i=0; i<n; i++) {
            mark[A[i]] = 1;
        }

        int miss = 1;
        while (miss <= INT_MAX) {
            if (mark.find(miss) == mark.end()) return miss;
            if (miss == INT_MAX) {
                cout<<"no missing positive"<<endl;
                return 0;
            }
            miss++;
        }
        return miss;
    }
    
    int firstMissingPositive3(int A[], int n) {
        if (A == NULL || n < 1) return 1;

        for (int i = 0; i<n; i++) {
            if (A[i] <= 0) A[i] = n + 1;
        }
        for (int i=0; i<n; i++) {
            int cur = A[i] < 0 ? -A[i] : A[i];
            if (cur <= n) A[cur - 1] = A[cur - 1] < 0 ? A[cur - 1] : -A[cur - 1];
        }
        int miss = 1;
        for (int i=0; i<n; i++) {
            if (A[i] > 0) break;
            miss++;
        }
        return miss;
    }
};

int main() {
    int A[] = {4,3 -1, 1};
    int len = sizeof(A) / sizeof(int);
    Solution s;
    cout<<s.firstMissingPositive(A, len)<<endl;
    cout<<s.firstMissingPositive2(A, len)<<endl;
    cout<<s.firstMissingPositive3(A, len)<<endl;
    system("pause");
	return 0;
}

