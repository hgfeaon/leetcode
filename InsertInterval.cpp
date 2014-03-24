#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef struct tagInterval Interval;

struct tagInterval {
    int start;
    int end;
    tagInterval() : start(0), end(0) {}
    tagInterval(int s, int e=0) : start(s), end(e) {}
};

class Solution {
public:
    // verbose one
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        int ns = newInterval.start;
        int ne = newInterval.end;
        int num = intervals.size();
        int i, is, ie;

        for (i = 0; i<num; i++) {
            if (intervals[i].end >= ns) break;
            ret.push_back(intervals[i]);
        }
        is = i;
        bool dispart = false;
        if (is == num || (dispart = intervals[is].start > ne)) {
            ret.push_back(Interval(ns, ne));
        }
        
        for (; i<num; i++) {
            if (intervals[i].start > ne) break;
        }
        ie = i - 1;
        if (is != num && ie >= is) {
            int s, e;
            if (dispart) {
                s = intervals[is].start;
            } else {
                s = min(intervals[is].start, ns);
            }
            e = max(intervals[ie].end, ne);
            ret.push_back(Interval(s, e));
        }
        while(i < num) ret.push_back(intervals[i++]);
        
        return ret;
    }
    // better to read and comprehend
    vector<Interval> _insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        int ns = newInterval.start;
        int ne = newInterval.end;
        int num = intervals.size();
        
        bool joined = false;
        bool pushed = false;
        for (int i=0; i<num; i++) {
            Interval cur = intervals[i];
            if (!is_overlapped(cur, newInterval)) {
                if (newInterval.end < cur.start) {
                    if (!pushed) {
                        ret.push_back(newInterval);
                        pushed = true;
                    }
                }
                ret.push_back(cur);
            } else {
                newInterval = join(newInterval, cur);
                joined = true;
            }
        }
        if ((!joined&&!pushed) || !pushed) {
            ret.push_back(newInterval);
        }
        return ret;
    }

    bool is_overlapped(Interval& a,  Interval& b) {
        if (a.end < b.start || b.end < a.start) return false;
        return true;
    }
    
    Interval join(Interval& a,  Interval& b) {
        return Interval(min(a.start, b.start), max(a.end, b.end));
    }
};

void print(vector<Interval> nums) {
    for (int i=0; i<nums.size(); i++) {
        cout<<" ["<<nums[i].start<<", "<<nums[i].end<<"],";
    }
    cout<<endl;
}

int main() {
    Interval tests[10];

    int start[] = {2, 6, 8, 9, 12};
    int end[]   = {5, 7, 9, 10, 16};
    int nums = 3;
    
    for (int i=0; i<nums; i++) {
        tests[i].start = start[i];
        tests[i].end = end[i];
    }

    vector<Interval> cases(tests, tests+nums);
    
    Interval interval(0, 1);
    
    Solution s;
    
    print(s._insert(cases, interval));
    
	system("pause");
	return 0;
}

