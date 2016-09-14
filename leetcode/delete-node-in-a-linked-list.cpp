// Source : https://leetcode.com/problems/delete-node-in-a-linked-list/
// Author : RQY
// Date   : 2016-09-14
/**********************************************************************************
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3,
the linked list should become 1 -> 2 -> 4 after calling your function.
 **********************************************************************************/
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */

//直接删除某一个节点，通过所给的地址。
//大多数情况下，我们会找到该节点的前一个节点，然后pre->next = curr->next; delete curr;
//而在此题目中，这种方法不再适用。取而代之的是将下一节点的val保存到当前节点，再curr->next = nextNode->next,最后删除nextNode
//也就是说，nextNode变成了它的替死鬼。（该情况下不能删除尾节点）
 class Solution {
 public:
     void deleteNode(ListNode* node) {
         ListNode *nextNode = node->next;
         node->val = nextNode->val;
         node->next = nextNode->next;
         delete nextNode;
     }
 };
