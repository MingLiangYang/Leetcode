/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

说明：不允许修改给定的链表。
思路：
1、判断有无环：快慢指针，追及问题。快指针是慢指针速度二倍，相遇时复杂度O(N)，如果fast==NULL则无环。
2、找环入口：快指针，慢指针分别赋值为head和相遇点指针，速度均为1。再次相遇时为环入口。
证明：
1、追及问题，慢指针顶多走完一遍，故O(N)复杂度。
2、2S=S+nr(n==1)且s=x+y 得出x=nr-y 故重新归位后，慢指针（此时速度相同）到达x远后，快指针走了nr-y，即反向走了y，正是入口点。
其中：s为慢指针路程，n为常数这里固定为1,r为环的长度,x为head到环入口的长度,y为慢指针第一次进入环时距离快指针的距离。
*/

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

		while (fast != NULL && fast->next!=NULL && slow != fast){
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
	ListNode * findGate(ListNode * head , ListNode * en){
		ListNode * slow = head;
		ListNode * fast = en;
		while (fast!=NULL && slow != fast){
			slow = slow->next;
			fast = fast->next;
		}
		return fast;
	}
};
