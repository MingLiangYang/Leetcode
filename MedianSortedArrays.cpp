/*
A hard question:
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

你可以假设 nums1 和 nums2 不同时为空。

重点思路：
1、将数字扩大二倍，则无需考虑奇偶；保证nums2个数小于nums1

2、确定数组2的cut2位置，数组1cut1的位置固定。恒有cut1+cut2==N1+N2(两个数组扩大后总数2N+2个)

3、核心思想：不断调整cut2的位置，使得cut1-left（值，而不是位置指针）<=cut2-right && cut2-left<=cut1-right 不然的话调整cut2的位置（cut1自然变动）。
eg. if(cut1-left>cut2-right)  cut2右移（如果不用二分就是cut2+=1） 这里可以使用二分搜索，low=cut2+1; high不变，每次的cut2=(low+high)/2;
最终满足cut2的条件，确定两个cut的位置，最后中位值等于和的一半of（（两个cut左边值的最大值）和（两个cut右边值的最小值））。

4、注意一个细节：最后有可能cut到两个数组起始的空白位置（*1*2*3*4...*5*），即首位两个*。那么此时cut两侧只有一个值是存在的，另一个必须赋值为
无限大或者无限小，使得最后的中位值（如何计算见第3条）存在且有意义。根据中位值的计算方式可以看出，如果cut在左端点必须令左值为INT_MIN,如果cut
在右端点必须令cut右值为INT_MAX，数组一和数组二均需处理。道理显而易见，这样赋值会使最后计算2左max或者2右min的时候有意义。

5、最后这是一个简洁而完美效率O(log(m+n))的解答，日后有时间补齐其他递归方法。
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
		high = 2*N2 ;
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
