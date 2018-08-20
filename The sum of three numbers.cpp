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
	/*vector<vector<int>> threeSum(vector<int>& nums) {
	
		vector<int> temp;
		set<vector<int>> s;
		//sort(nums.begin(),nums.end());
		//vector<int>::iterator it = unique(nums.begin(), nums.end());
		//nums.resize(distance(nums.begin(), it));
		for (int i = 0; i < nums.size(); i++){
			for (int j = i + 1; j < nums.size(); j++){
				for (int k = j + 1; k < nums.size(); k++){
					if (nums[i] + nums[j] + nums[k] == 0){
						temp.clear();
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[k]);
						sort(temp.begin(), temp.end());
						//result.push_back(temp);
						s.insert(temp);
					}
				}
			}
		}
		vector<vector<int>> result(s.size());
		copy(s.begin(),s.end(),result.begin());
		return result;
	}*/
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
