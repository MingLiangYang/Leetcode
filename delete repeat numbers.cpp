/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
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
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()){
			return 0;
		}
		int now = nums.at(0);
		int k = 1;
		for (int i = 1; i < nums.size(); i++){
			if (nums[i]!=now){
				nums[k] = nums[i];
				now = nums[i];
				++k;
			}
		}
		return k;
	}
};


int main(){
	Solution s;
	vector<int> input;
	int n;
	int member;
	int target;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> member;
		input.push_back(member);
	}
	//Solution s;
	int len = s.removeDuplicates(input);
	cout << "length£º" << len<<endl;
	for (vector<int>::iterator i = input.begin(); i != input.end(); ++i){
		cout << *i << " ";
	}
	while (1);
	return 0;
}

 
