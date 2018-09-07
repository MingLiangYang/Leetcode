/*
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

思路：使用并查集思想，每个集合的代表元是边界元素。利用unordered_map 或者 map 存储对应value-lentgh. 利用并查集算法对其更新。

注意: 插入每一个pair的时候检查左右元素，如果存在则本元素的长度为左右长度之和+1，并且需要更新左右集合的（不是左右元素，集合的代表元是该集合的
边界元素）长度。

反思：使用hash_map理论上要更快，但是本题目涉及到插入与查找两个操作，实际上map更快一些。
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
//#include<hash_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		//map<int, int> m;
		unordered_map<int, int> m;
		int res=0;
		for (int i = 0; i < nums.size(); i++){
			int x = nums[i];
			int left, right;
			if (!m.count(x)){
				int sum=0;
				left = m.count(x - 1) ? m.find(x - 1)->second : 0;
				right = m.count(x + 1) ? m.find(x + 1)->second : 0;
				sum = left + right + 1;

				m.insert(pair<int, int>(x,sum));

				if (left) m[x - left] = sum;
				if(right) m[x + right] = sum;
			
				if (sum > res) res = sum;

			}
		}
		return res;
	}
};

/*
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		map<int, int> m;
		int res=0;
		for (int i = 0; i < nums.size(); i++){
			int x = nums[i];
			if (!m.count(x)){
				int sum=0;
				if (m.count(x - 1)){
					sum+=m.find(x-1)->second;
				}
				if (m.count(x + 1)){
					sum += m.find(x + 1)->second;
				}
				sum++;
				m.insert(pair<int, int>(x,sum));
				if (m.find(x - 1) != m.end()){
					m[x - m.find(x-1)->second] = sum;
				}
				if (m.find(x + 1) != m.end()){
					m[x + m.find(x + 1)->second] = sum;
				}
				if (sum > res) res = sum;

			}
		}
		return res;
	}
};
*/
int main(){
	Solution s;
	vector<int> input = { 0,3,7,2,5,8,4,6,0,1 };
	int n=6;
	int a = s.longestConsecutive(input);
	
	cout << a;

	while (1);
	return 0;
}
