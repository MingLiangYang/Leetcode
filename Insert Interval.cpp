#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<limits.h>
//#include<hash_map>
#include<algorithm>
using namespace std;


 struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		int i = 0;
		Interval nowinterval(newInterval);
		vector<Interval> res;
		
		if (intervals.empty()){
			res.push_back(newInterval);
			return res;
		}
		
		while (intervals[i].end < newInterval.start && i < intervals.size()){
			res.push_back(intervals[i]);
			//if (i + 1 == intervals.size())break;
			i++; 
		}
		while (intervals[i].start <= newInterval.end && i < intervals.size()){
			int a,b;
			a = intervals[i].start < nowinterval.start ? intervals[i].start : nowinterval.start;
			b = intervals[i].end > nowinterval.end ? intervals[i].end : nowinterval.end;
			if (a < nowinterval.start) nowinterval.start = a;
			if (b > nowinterval.end) nowinterval.end = b;
			//if (i + 1 == intervals.size())break;
			i++;
		}
		res.push_back(nowinterval);
		for (int j = i; j < intervals.size(); j++){
			res.push_back(intervals[j]);
		}
		return res;
	}
};
int main(){
	Solution s;
	
	/*
	intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
	*/
	vector<Interval> input;
	input.push_back(Interval(1, 2));
	input.push_back(Interval(3, 5));
	input.push_back(Interval(6, 7));
	input.push_back(Interval(8, 10));
	input.push_back(Interval(12, 16));
	vector<Interval>a = s.insert(input, Interval(4, 8));
	for (int i = 0; i < a.size(); i++){
		cout << a[i].start << " " << a[i].end << endl;
	}
	while (1);
	return 0;
}