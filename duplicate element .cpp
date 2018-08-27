/*
Using set<int> to judge duplicate element. 
*/
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> duplicate;
		for (int i = 0; i < nums.size(); i++){
			pair<set<int>::iterator,bool> res=duplicate.insert(nums[i]);
			if (!res.second) return true;
		}
		return false;
	}
};
