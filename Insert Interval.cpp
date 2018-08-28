/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]

输出: [[1,2],[3,10],[12,16]]

思路：顺序查找，考虑新区间的前端和旧区间的末端，新区间的末端和旧区间的前端的关系。注意边界条件和区间个数。
*/
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
		
		if (intervals.empty()){ //special case
			res.push_back(newInterval);
			return res;
		}
		
		while (intervals[i].end < newInterval.start && i < intervals.size()){ //i<size 
			res.push_back(intervals[i]);                                  //end < start_new: push_back 
			//if (i + 1 == intervals.size())break;
			i++; 
		}
		while (intervals[i].start <= newInterval.end && i < intervals.size()){ //update the newinterval's start and end 
			int a,b;
			a = intervals[i].start < nowinterval.start ? intervals[i].start : nowinterval.start; // get the min start value
			b = intervals[i].end > nowinterval.end ? intervals[i].end : nowinterval.end;   //get the max end value
			if (a < nowinterval.start) nowinterval.start = a;    //The update the min and max value and update newInterval
			if (b > nowinterval.end) nowinterval.end = b;
			//if (i + 1 == intervals.size())break;
			i++;
		}
		res.push_back(nowinterval);   // put the newInterval 
		for (int j = i; j < intervals.size(); j++){  // left elements 
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
