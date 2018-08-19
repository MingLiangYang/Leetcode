#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
//#include<hash_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int k=0;
		for (int i = 0; i<nums.size()-k; i++){
			if (nums[i] == val){
				for (int j = i+1; j<nums.size()-k; j++){
					nums[j-1] = nums[j];
				}
				k++;
				i--;
			}
		}
		return nums.size() - k;
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
	int val;
	cin >> val;
	//Solution s;
	int len = s.removeElement(input,val);
	cout << "length:" << len << endl;
	for (vector<int>::iterator i = input.begin(); i != input.end(); ++i){
		cout << *i << " ";
	}
	while (1);
	return 0;
}