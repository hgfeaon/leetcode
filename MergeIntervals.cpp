#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

void print(vector<Interval>&);

class Solution {
private:
	static int compare(const Interval& a, const Interval& b) {
		return a.start < b.start;
	}
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> res;
		int len = intervals.size();
		if (len < 1) return res;

		sort(intervals.begin(), intervals.end(), Solution::compare);
		
		cout<<"sorted:";
		print(intervals);

		Interval merged = intervals[0];
		for (int i=1; i<len; i++) {
			Interval& cur = intervals[i];
			if (merged.end >= cur.start) { // merge two intervals
				if (merged.end < cur.end) merged.end = cur.end;
			} else {
				res.push_back(merged);
				merged = cur;
			}
		}
		res.push_back(merged);

		return res;
	}
};

void print(vector<Interval>& is) {
	for (int i=0; i<is.size(); i++) {
		cout<<"["<<is[i].start<<","<<is[i].end<<"]"<<" ";
	}
	cout<<endl;
} 

int main() {

	Solution s;
	vector<Interval> is;
	is.push_back(Interval(1, 3));
	is.push_back(Interval(2, 6));

	is.push_back(Interval(8, 10));
	is.push_back(Interval(15, 18));

	cout<<"data:";
	print(is);

	vector<Interval> res = s.merge(is);
	
	cout<<"res:";
	print(res);

	return 0;
}
