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
	vector<vector<int>> fourSum(vector<int>& nums,int target) {
		vector<vector<int>> result;
		if (nums.size() < 4){
			return vector<vector<int>> {0};
		}
		//set<vector<int>> s;
		sort(nums.begin(), nums.end());
		for (int m = 0; m < nums.size()-3; m++){
			int d = nums[m];
			//if (nums[m] > target) break;
			if (m > 0 && d == nums[m - 1])continue;
			for (int i = m+1; i < nums.size() - 2; i++){
				int l = i + 1;
				int r = nums.size() - 1;

				int a = nums[i];
				//if (a > 0) break;
				if (i > m+1 && a == nums[i - 1]) continue;

				while (l < r){
					int b = nums[l];
					int c = nums[r];
					int sum = a + b + c + d;
					//cout << sum << " ";
					if (sum > target) r--;
					else if (sum < target) l++;
					else{//sum==0
						vector<int> tem;
						tem.clear();
						tem.push_back(d);
						tem.push_back(a);
						tem.push_back(b);
						tem.push_back(c);
						result.push_back(tem);
						//s.insert(tem);
						//l++; r--;
						while (nums[++l] == b && l<nums.size()-1) ;
						while (nums[--r] == c && r > i);
					}
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
	cin >> target;
	vector<vector<int>> res;
	res = s.fourSum(input,target);
	for (vector<vector<int>>::iterator i = res.begin(); i != res.end(); ++i){
		for (vector<int>::iterator it = (*i).begin(); it != (*i).end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}
	while (1);
	return 0;
}
