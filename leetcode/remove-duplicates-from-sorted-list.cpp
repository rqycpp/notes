// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author : RQY
// Date   : 2016-09-14
/**********************************************************************************
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
     ListNode* deleteDuplicates(ListNode* head) {
         // ListNode dummyHead(0); dummyHead.next = head;
         // ListNode *previous = &dummyHead;
         ListNode *current = head;
         while(current && current->next){
             if(current->val == current->next->val){
                 deleteNode(current, current->next);//删除current->next节点
             }
             else
                 current = current->next;
         }
         return head;

     }
     void deleteNode(ListNode *previous, ListNode *current){
         previous->next = current->next;
         delete current;
     }
 };
