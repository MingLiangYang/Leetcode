#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
//#include<hash_map>
#include<algorithm>
using namespace std;

//������K��ѭ����O(K*N)���ӶȾͲ�д�ˡ�
/*
����һ�����͵Ĵ��󷽷����ӵ�һ��Ԫ�ؿ�ʼ��ѭ���ƶ������ַ�����k����2ʱ����size()%k�ܹ��������ᵼ���ƶ���Ԫ�ز�ȫ����������ʱ��Ч��
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty() || nums.size() == 1){
			return;
		}
		k %= nums.size();
		//int l= nums[k];
		int b = nums[0];
		int index = k;
		for (int i = 0; i < nums.size(); i++){
			if (index >= nums.size()){
				index -= nums.size();
			}
			int tem = nums[index];
			nums[index] = b;
			b = tem;
			index += k;
		}

	}
};
*/

//�����������η�ת��(0,size-k-1)��ת��(size-k size-1)��ת���������(0,size-1)��ת ԭ��ο���Գ�����  �ܺõķ���,���Ӷȣ�2N��;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		
		if (nums.empty() || nums.size() == 1){
			return ;
		}
		k %= nums.size();
		reverse(nums, 0, nums.size() - k - 1);
		reverse(nums,nums.size() - k, nums.size() - 1);
		reverse(nums, 0, nums.size() - 1);
	}
private:
	void reverse(vector<int> & nums,int l,int r){
		while (l < r){
			swap(nums[l], nums[r]);
			l++;
			r--;
		}
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
	s.rotate(input,3);
	for (int i = 0; i < n; i++){
		cout << input[i] << " ";
	}

	while (1);
	return 0;
}

