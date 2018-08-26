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
	vector<vector<int>> NSum(vector<int>& nums, int target, int k) {
		if (nums.size() < k){
			return vector<vector<int>> {0};
		}
		sort(nums.begin(), nums.end());
		vector<vector<int>> r = kSum(nums, target, k, 0);
		return r;
	}
	vector<vector<int>> kSum(vector<int>& nums, int target, int k, int begin) {
		vector<vector<int>> res;
		if (k == 2){
			int i = begin ;
			int j = nums.size() - 1;
			while (i < j){
				int a = nums[i];
				int b = nums[j];
				if (a + b == target){
					vector<int> temp;
					temp.clear();
					temp.push_back(b);
					temp.push_back(a);
					res.push_back(temp);
					while (nums[++i] == a && i<nums.size()-1);
					while (nums[--j] == b && j>begin);
				}
				else if(a+b<target){
					i++;
				}
				else{
					j--;
				}
			}
			return res;
		}
		else{
		
			for (int m = begin; m < nums.size() - k + 1; m++){
				vector<vector<int>> t;
				int n_m = nums[m];
				if ( m > begin && nums[m - 1] == n_m) continue;
				t = kSum(nums, target - n_m, k - 1, m + 1);
				if (!t.empty()){
					for (int l = 0; l < t.size(); l++){
						t[l].push_back(n_m);
						res.push_back(t[l]);
					}
				}

			}
			return res;
		}
	}
};

int main(){
	Solution s;
	vector<int> input = {-2,-1,0,0,1,2};
	int n;
	//hash_map<int, int> hm;
	int member;
	int target;
	//cin >> n;
	//n = 6;
	/*
	for (int i = 0; i < n; i++){
		cin >> member;
		input.push_back(member);
	}
	*/
	//cin >> target;
	//int k;
	//cin >> k;
	//int index=0;
	vector<vector<int>> res;
	res = s.NSum(input, target=0, 4);
	for (vector<vector<int>>::iterator i = res.begin(); i != res.end(); ++i){
		for (vector<int>::iterator it = (*i).begin(); it != (*i).end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}
	while (1);
	return 0;
}
