#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<string>
//#include<hash_map>
#include<algorithm>
//#include<iostream>
using namespace std;


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(NULL){}
};
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head) return NULL;
		ListNode * en = detectIsCycle(head);
		if (!en){
			return NULL;
		}
		else{
			return findGate(head, en);
		}

	}
private:
	ListNode * detectIsCycle(ListNode * head){
		ListNode *slow, *fast;
		if (head->next != NULL && head->next->next != NULL){
			slow = head->next;
			fast = head->next->next;
		}
		else return NULL;

		while (fast != NULL && fast->next != NULL && slow != fast){
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast == NULL){
			return NULL;
		}
		else{
			return fast;
		}
	}
	ListNode * findGate(ListNode * head, ListNode * en){
		ListNode * slow = head;
		ListNode * fast = en;
		while (fast != NULL && slow != fast){
			slow = slow->next;
			fast = fast->next;
		}
		return fast;
	}
}; int main(){
	Solution s;
	s.detectCycle(NULL);
	while (1);
	return 0;
}
