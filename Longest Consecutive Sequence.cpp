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
