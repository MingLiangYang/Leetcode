/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

反思：可以使用排序双指针法计算2Sum。
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
//#include<hash_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> tm = nums;
		vector<int> res;
		for (vector<int>::iterator it = tm.begin(); it != tm.end(); ++it){
			for (vector<int>::iterator later = it + 1; later != tm.end(); ++later){
				if ((*it) + (*later) == target){
					res.push_back(distance(tm.begin(), it));
					res.push_back(distance(tm.begin(), later));
					return res;
				}
			}
		}
		return nums;
	}
};

int main(){
	Solution s;
	vector<int> input;
	int n;
	//hash_map<int, int> hm;
	int member;
	int target;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> member;
		input.push_back(member);
	}
	cin >> target;
	vector<int> res;
	res = s.twoSum(input, target);
	for (vector<int>::iterator i = res.begin(); i != res.end(); ++i){
		cout << *i << " ";
	}
	while (1);
	return 0;
}


