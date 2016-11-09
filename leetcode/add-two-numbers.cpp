// Source : https://leetcode.com/problems/add-two-numbers/
// Author : RQY
// Date   : 2016-09-25
/**********************************************************************************
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         if(!l1)
             return l2;
         if(!l2)
             return l1;

         const int base = 10;

         ListNode dummyNode(0);
         ListNode *p1 = l1, *p2 = l2, *dummy = &dummyNode;//, *ans = NULL;
         int c = 0;//进位
         while(p1 && p2){
             dummy->next = new ListNode((p1->val + p2->val + c) % base);
             c = (p1->val + p2->val + c) / base;
             p1 = p1->next;
             p2 = p2->next;
             dummy = dummy->next;
         }
         while(p1){
             dummy->next = new ListNode((p1->val + c) % base);
             c = (p1->val + c) / base;
             p1 = p1->next;
             dummy = dummy->next;
         }
         while(p2){
             dummy->next = new ListNode((p2->val + c) % base);
             c = (p2->val + c) / base;
             p2 = p2->next;
             dummy = dummy->next;
         }
         //最后处理进位
         if(c){
             dummy->next = new ListNode(c);
         }
         return dummyNode.next;

     }
 };
