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
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int N1 = nums1.size();
		int N2 = nums2.size();
		if (N1 < N2){
			return findMedianSortedArrays(nums2, nums1) ;
		}
		if (N1 == 0){
			return -1;
		}
		if (N2==0){
			return (double)(nums1[(N1-1)/2]+nums1[ N1/2]) / 2;
		}
		int low, high;
		low = 0;
		high = 2*N2 + 1;
		while (low < high){
			int cut2 = (low + high) / 2;
			int cut1 = N1 + N2 - cut2;

			double l1 = cut1 == 0?INT_MIN:nums1[(cut1 - 1) / 2];
			double l2 = cut2==0?INT_MIN:nums2[(cut2 - 1) / 2];
			double r1 = cut1 == 2*N1 ?INT_MAX:nums1[(cut1) / 2];
			double r2 = cut2==2*N2?INT_MAX:nums2[cut2 / 2];


			if (l1>r2){//cut2 ->
				low = cut2 + 1;
			}
			else if (l2 > r1){
				high = cut2 - 1;
			}
			else{
				return (max(l1, l2) + min(r1, r2)) / 2;
			}

		}
		return -1;
	}
};
int main(){
	Solution s;
	vector<int> input1 = {1,2,3,4,5};
	vector<int> input2 = {1,1,1,1};
	cout<< s.findMedianSortedArrays(input1, input2);
	while (1);
	return 0;
}