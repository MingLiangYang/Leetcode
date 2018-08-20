/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/
/*
思路：固定区间斗鸡
外层循环i遍历数组中元素，l=i+1;r=size-1; while(l<r);遍历l和r。
核心思想：
	对于每一个sum=a+b+c;(nums[i],nums[l],nums[r])，判断sum与0的关系:
		如果sum<0,l指针右移;如果sum>0，r指针左移;如果sum==0，记录结果{a,b,c}，l指针右移，r指针左移。
	循环出口a(nums[i])>0; (注：b,c值一定比a大,故sum=a+b+c没有往后找的必要了)
要点：
	在移动指针时有两点要注意，题目要求不能有重复结果，但是需要考虑同一个元素的重复出现，所以不可以直接去重处理。
		（因为有的元素重复有的不重复，重复个数也不同）。
	1、i指针只计算重复元素的第一个，后边的重复元素直接忽略。 如-1-1-1 2... a只考虑第一个-1，后边的-1直接忽略。原理：确定a=第一个-1，相当于
		确定情况至少有一个-1；忽略后边的重复，跳到下一个元素2，相当于情况不含有-1。逻辑完备
	2、l,r指针移动同上，遍历时需要忽略除第一个以外的所有重复元素。

反思与提高：
	要点中的去重环节实际上是比较麻烦的，需要考虑三个指针，容易出错。可以使用set<vector<int>>转vector<vector<int>>帮助结果去重。
	本方法代码在文中注释。
*/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
//#include<hash_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() < 2){
			return vector<vector<int>> {0};
		}
		//set<vector<int>> s;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++){
			int l = i + 1;
			int r = nums.size() - 1;
			
			int a = nums[i];
			if (a > 0) break;
			if (i > 0 && a == nums[i - 1]) continue;
			while (l < r){
				int b = nums[l];
				int c = nums[r];
				int sum = a + b + c;
				//cout << sum << " ";
				if (sum>0) r--;
				else if (sum < 0) l++;
				else{//sum==0
					vector<int> tem;
					tem.clear();
					tem.push_back(a);
					tem.push_back(b);
					tem.push_back(c);
					result.push_back(tem);
					//s.insert(tem);
					//l++; r--;
					while (nums[++l] == b);
					while (nums[--r] == c);
				}
			}

		}
		//result.resize(s.size());
		//copy(s.begin(), s.end(), result.begin());
		return result;
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
	//cin >> target;
	vector<vector<int>> res;
	res = s.threeSum(input);
	for (vector<vector<int>>::iterator i = res.begin(); i != res.end(); ++i){
		for (vector<int>::iterator it = (*i).begin(); it != (*i).end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}
	while (1);
	return 0;
}
