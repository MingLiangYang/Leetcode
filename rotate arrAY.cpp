#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
//#include<hash_map>
#include<algorithm>
using namespace std;

//基本的K次循环，O(K*N)复杂度就不写了。
/*
方法一：典型的错误方法，从第一个元素开始，循环移动。这种方法当k大于2时而且size()%k能够整除，会导致移动的元素不全。不能整除时奏效。
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty() || nums.size() == 1){
			return;
		}
		k %= nums.size();
		//int l= nums[k];
		int b = nums[0];
		int index = k;
		for (int i = 0; i < nums.size(); i++){
			if (index >= nums.size()){
				index -= nums.size();
			}
			int tem = nums[index];
			nums[index] = b;
			b = tem;
			index += k;
		}

	}
};
*/

//方法二：三次翻转，(0,size-k-1)翻转，(size-k size-1)翻转，最后整个(0,size-1)翻转 原理参考轴对称性质  很好的方法,复杂度（2N）;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		
		if (nums.empty() || nums.size() == 1){
			return ;
		}
		k %= nums.size();
		reverse(nums, 0, nums.size() - k - 1);
		reverse(nums,nums.size() - k, nums.size() - 1);
		reverse(nums, 0, nums.size() - 1);
	}
private:
	void reverse(vector<int> & nums,int l,int r){
		while (l < r){
			swap(nums[l], nums[r]);
			l++;
			r--;
		}
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
	s.rotate(input,3);
	for (int i = 0; i < n; i++){
		cout << input[i] << " ";
	}

	while (1);
	return 0;
}

