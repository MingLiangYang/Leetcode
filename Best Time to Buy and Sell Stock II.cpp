#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<limits.h>
//#include<hash_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int sum = 0;
		int lower = prices[0], upper = prices[0];
		for (vector<int>::iterator it = prices.begin(); it != prices.end()-1; ++it){
			if ((*it) <= *(it + 1)){
				upper= *(it + 1);
			}
			else{//ÏÂ½µ
				sum += upper - lower;
				upper = *(it + 1);
				lower=*(it + 1);
			}
		}
		return sum;
	}
};

int main(){
	Solution s;
	vector<int> input = { 7,1,5,3,6,4 };
	int n = 6;
	int a = s.maxProfit(input);

	cout << a;

	while (1);
	return 0;
}