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
	bool isNStraightHand(vector<int>& hand, int W) {
		if (hand.size() % W != 0)return false;
		if (W == 1)return true;
		sort(hand.begin(), hand.end());
		int vis[10000] = {0};
		int cnt = W;
		for (int i = 0; i < hand.size(); i++){
			if (vis[i])continue;
			int now = hand[i];
			vis[i] = 1;
			cnt = W-1;
			for (int j = i + 1; j < hand.size(); j++){
				if ((!vis[j])&&(hand[j] == now + 1)) {
					vis[j] = 1;
					if (--cnt == 0){
						break;
					}
					now = hand[j];
				}
			}
			if (cnt)return false;
		}
		if (cnt)return false;
		else return true;
	}
};


int main(){
	Solution s;
	vector<int> input = {1, 2, 3, 6, 2, 3, 4, 7, 8};
	int k = 3;
	cout << s.isNStraightHand(input, k);
	while (1);
	return 0;
}
