/*
	2Sum 3Sum 4Sum question makes me think of a solution to all this problem.
	因此基于kSum通解问题的思考，提出以下程序，利用递归（DFS）解决kSum问题。问题的详细描述见2Sum、3Sum and 4Sum code。	
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
	vector<vector<int>> fourSum(vector<int>& nums, int target) {//fourSum function is for testing on Leetcode 4Sum question
		return NSum(nums, target, 4);
	}
	vector<vector<int>> NSum(vector<int>& nums, int target, int k) { // Sort and special cases, call core function kSum.
		if (nums.size() < k){
			return vector<vector<int>> {0};
		}
		sort(nums.begin(), nums.end());
		vector<vector<int>> r = kSum(nums, target, k, 0);
		return r;
	}
	vector<vector<int>> kSum(vector<int>& nums, int target, int k, int begin) {//DFS 
		vector<vector<int>> res;
		if (k == 2){  // outdoor 
			int i = begin ;
			int j = nums.size() - 1;
			while (i < j){  //固定区间斗鸡眼问题
				int a = nums[i];
				int b = nums[j];
				if (a + b == target){//find answer and record it
					vector<int> temp;
					temp.clear();  // essential step
					temp.push_back(b);
					temp.push_back(a);
					res.push_back(temp);
					while (nums[++i] == a && i<nums.size()-1); //filter out repeat integers
					while (nums[--j] == b && j>begin);         //ensure in array range
				}
				else if(a+b<target){  //move left pointer
					i++;
				}
				else{                 //right one 
					j--;
				}
			}
			return res;
		}
		else{
		
			for (int m = begin; m < nums.size() - k + 1; m++){ // DFS's width  
				vector<vector<int>> t;
				int n_m = nums[m];
				if ( m > begin && nums[m - 1] == n_m) continue;  // filter repeat integers
				
				t = kSum(nums, target - n_m, k - 1, m + 1);    // core recursive calling 
				                                               // vector,target-nums[m],k-1,m+1
									       // m+1 not begin+1  !!!!!!!!!!!!!!!!!
				if (!t.empty()){        //!!!!!!!!!!!!
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
