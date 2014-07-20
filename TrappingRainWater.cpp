#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if (n < 1) return 0;
        vector<int> peaks;
        vector<int> peaks_tmp;

        int last_idx = 0;

        bool increasing = true;
        for (int i=1; i<n; i++) {
            if (A[i] < A[last_idx]) {
                if (increasing) {
                    peaks.push_back(last_idx);
                }
                increasing = false;
            } else {
                increasing = true;
            }
            last_idx = i;
        }
        if (increasing) peaks.push_back(n - 1);

        if (peaks.size() < 2) return 0;
        
        bool updated = true;

        while (updated) {
            updated = false;
            peaks_tmp.clear();
            peaks_tmp.push_back(peaks[0]);
            peaks_tmp.push_back(peaks[1]);
            for (int i=2; i<peaks.size(); i++) {
                int tlen = peaks_tmp.size();
                int ai = peaks_tmp[tlen - 2];
                int bi = peaks_tmp[tlen - 1];
                int ci = peaks[i];

                if (A[ai] >= A[bi] && A[ci] >= A[bi]) {
                    peaks_tmp[tlen - 1] = ci;
                    updated = true;
                } else {
                    peaks_tmp.push_back(ci);
                }
            }
            swap(peaks, peaks_tmp);
        }

        int rain = 0;

        for (int i=1; i<peaks.size(); i++) {
            int left = peaks[i - 1];
            int right= peaks[i];

            int h = min(A[left], A[right]);
            int blocks = 0;
            for (int i=left + 1; i<right; i++) blocks += A[i] > h ? h : A[i];
            rain += h * (right - left - 1) - blocks;
        }
        return rain;
    }
    
    void print(vector<int> &array) {
        for (int i=0; i<array.size(); i++) {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
};


int main() {
    int blocks[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int blocks2[] = {5,2,1,2,1,5};
    
    int len = sizeof(blocks) / sizeof(int);
    int len2 = sizeof(blocks2) / sizeof(int);

    Solution s;

    cout<<s.trap(blocks2, len2)<<endl;
    cout<<s.trap(blocks, len)<<endl;
    
	system("pause");
	return 0;
}

