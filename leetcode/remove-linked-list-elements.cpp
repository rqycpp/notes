// Source : https://leetcode.com/problems/remove-linked-list-elements/
// Author : RQY
// Date   : 2016-09-14
/**********************************************************************************
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
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
     ListNode* removeElements(ListNode* head, int val) {
         ListNode dummyHead(0);dummyHead.next = head;//虚拟头节点，可以将删除head节点转换成一般情况，无需特殊处理
         ListNode *previous = &dummyHead;//前趋
         ListNode *current = head;
         while(current){
             if(current->val == val){
                 deleteNode(previous, current);//删除current节点
                 current = previous->next;
             }
             else{
                 previous = current;
                 current = current->next;
             }
         }
         return dummyHead.next;//返回真正的head
     }
     void deleteNode(ListNode *previous, ListNode *current){//删除current节点，在已知previous前提下
         ListNode *deleteNode  = current;
         previous->next = deleteNode->next;
         delete deleteNode;
     }

 };
