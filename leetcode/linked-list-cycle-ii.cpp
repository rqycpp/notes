// Source : https://leetcode.com/problems/linked-list-cycle-ii/
// Author : RQY
// Date   : 2016-09-17
/**********************************************************************************
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

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
     ListNode *detectCycle(ListNode *head) {
         ListNode *nodeInCircle = hasCycle(head);
         if(!nodeInCircle)
             return NULL;
         ListNode *p1 = head, *p2 = head;
         int cycleLen = cycleLength(nodeInCircle);
         while(cycleLen--){
             p2 = p2->next;//p2先走cycleLen个单位
         }
         while(p1 != p2){//当p1 = p2时，此处为环的入口节点
             p1 = p1->next;
             p2 = p2->next;
         }
         return p1;
     }
     ListNode *hasCycle(ListNode *head) {//若存在环，则返回环中某一个节点
          if(!head || !head->next)
              return NULL;

          ListNode *p1, *p2;
          p1 = p2 = head;
          do{
              p1 = p1->next;
              p2 = p2->next->next;
              if(p1 == p2)
                  return p1;
          }while(p1&&p2&&p2->next);
          return NULL;
     }
     int cycleLength(ListNode *head){//利用环中某一节点，求出环的长度
         int length = 0;
         ListNode *current = head;
         do{
             current = current->next;
             ++length;
         }while(current != head);
         return length;
     }
 };
