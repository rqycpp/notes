// Source : https://leetcode.com/problems/palindrome-linked-list/
// Author : RQY
// Date   : 2016-09-03
/**********************************************************************************
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
 **********************************************************************************/
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
 class Solution {
 public:
     bool isPalindrome(ListNode* head) {//将链表的一半进行反转
         if(!head || !head->next)
             return true;
         ListNode *p1,*p2;//slow pointer and fast pointer
         p1 = p2 = head;
         while(p1 && p2 && p2->next){
             p1 = p1->next;//one step
             p2 = p2->next->next;//twp step
         }
         //此时p1指向链表的中间节点，从这里开始进行反转
         if(!p2){//偶数个节点 p2 == nullptr; a->b->c->d, p1==c,
             return sameList(head, reverseList(p1));
         }
         else{//奇数个节点 p2 == lastNode; a->b->c->d->e p1==c
             return sameList(head, reverseList(p1->next));
         }

     }

     ListNode *reverseList(ListNode* head){
         ListNode *current = head, *previous = nullptr, *next;
         while(current){
             next = current->next;
             current->next = previous;
             previous = current;
             current = next;
         }
         return previous;
     }

     bool sameList(ListNode *l1, ListNode *l2){//比较链表
         while(l2){//由于本题中l1.length >= l2.length, 所以以l2为循环条件
             if(l1->val != l2->val)
                 return false;
             l1 = l1->next;
             l2 = l2->next;
         }
         return true;
     }
 };
