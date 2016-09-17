// Source : https://leetcode.com/problems/linked-list-cycle/
// Author : RQY
// Date   : 2016-09-17
/**********************************************************************************
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
     bool hasCycle(ListNode *head) {
         if(!head || !head->next)
             return false;

         ListNode *p1, *p2;
         p1 = p2 = head;
         do{
             p1 = p1->next;
             p2 = p2->next->next;
             if(p1 == p2)
                 return true;
         }while(p1&&p2&&p2->next);
         return false;
     }
 };
