#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int ia = 0, ib = 0;
        int it = -1;
        int im = (m + n - 1) / 2;
        int val= 0;

        bool empty_a = A == NULL || m < 1;
        bool empty_b = B == NULL || n < 1;
        
        while (!empty_a && ia < m && !empty_b && ib < n && it < im) {
            if (A[ia] < B[ib]) {
                val = A[ia++];
            } else {
                val = B[ib++];
            }
            ++it;
        }
        
        while (!empty_a && ia < m && it < im) {
            val = A[ia++];
            it++;
        }
        while (!empty_b && ib < n && it < im) {
            val = B[ib++];
            it++;
        }
        if ((m + n) & 1) {
            return val;
        } else {
            int val2 = 0;
            if ((empty_a || ia >= m) && (empty_b || ib >= n)) {
                // should not happen
            } else if (empty_a || ia >= m) {
                val2 = B[ib];
            } else if (empty_b || ib >= n) {
                val2 = A[ia];
            } else {
                val2 = A[ia] > B[ib] ? B[ib] : A[ia];
            }
            return (val + val2) / 2.0;
        }
    }
    
    double findMedianSortedArrays2(int A[], int m, int B[], int n) {
        double ma = 0;
        double mb = 0;

        bool empty_a = A == NULL || m < 1;
        bool empty_b = B == NULL || n < 1;
        
        if (!empty_a) ma = (A[(m - 1) / 2] + A[m/2]) / 2.0;
        if (!empty_b) mb = (B[(n - 1) / 2] + B[n/2]) / 2.0;
        
        if (empty_a && empty_b) { // will this happen ?
            return 0;
        } else if (empty_a) {
            return mb;
        } else if (empty_b) {
            return ma;
        }
        
        double low = 0, high = 0;

        if (ma > mb) {
            low = mb, high = ma;
        } else if (ma < mb) {
            low = ma, high = mb;
        } else {
            return ma;
        }
        
        double precise = 0.01;
        double mv = 0;
        int total = m + n;
        int half  = total / 2;
        bool declared = false;
        while(high - low > precise) {
            mv = (high + low) / 2.0;
            int* pa = lower_bound(A, A + m, mv);
            int* pb = lower_bound(B, B + n, mv);
            int lh = (pa - A) + (pb - B);

            if (lh < half) {        // the median assumed is too small, so increase it
                low = mv;
            } else if (lh > half) { // the median assumed is too big, so decrease it
                high= mv;
            } else {
                declared = true;
                // divided into odd/even case. should re-calculate the mv
                // for even case median calculated from two adjacent numbers in
                // the merged array, we assume that one is mmore and the other
                // is mless (median = (mmore + mless) / 2.0 )
                int mmore = 0;
                // find bigger number to compute median for even case.
                if (pa == A + m && pb == B + n) {
                    // should not happen;
                    cout<<"[1]should not happen"<<endl;
                } else if (pa == A + m) {
                    mmore = *pb;
                } else if (pb == B + n) {
                    mmore = *pa;
                } else {
                    if (*pa < *pb) {
                        mmore = *pa;
                    } else {
                        mmore = *pb;
                    }
                }
                
                // for odd case. the mv is equal to value of mmore
                if (half * 2 != total) {
                    mv = mmore;
                    break;
                }
                
                // find samller number to compute median for even case.
                pa--, pb--;
                int mless = 0;
                if (pa < A && pb < B) {
                    // should not happen
                    cout<<"[2]should not happen"<<endl;
                } else if (pa < A) {
                    mless = *pb;
                } else if (pb < B) {
                    mless = *pa;
                } else {
                    if (*pb > * pa) {
                        mless = *pb;
                    } else {
                        mless = *pa;
                    }
                }
                mv = (mless + mmore) / 2.0;
                break;
            }
        }
        if (declared) { // median value is on the boundary
            return mv;
        }
        if (fabs(mv - ma) < fabs(mv - mb)) {
            return ma;
        } else {
            return mb;
        }
    }
};

int main() {
    Solution s;
    int A[] = {1};
    int B[] = {1};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    
    cout<<s.findMedianSortedArrays(A, m, B, n)<<endl;
	system("pause");
	return 0;
}

