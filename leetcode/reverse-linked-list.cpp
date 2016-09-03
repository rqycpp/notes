// Source : https://leetcode.com/problems/reverse-linked-list/
// Author : RQY
// Date   : 2016-09-03
/**********************************************************************************
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
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
     ListNode* reverseList(ListNode* head) {//利用栈先将队列元素入栈，然后再按出战顺序设置节点next
                                            //效率不高。
         if(!head)
             return nullptr;
         stack<ListNode*> Nodes;
         Nodes.push(nullptr);
         ListNode *current = head;
         while(current){
             Nodes.push(current);
             current = current->next;
         }
         head = Nodes.top();
         while(Nodes.top()){
             ListNode *temp = Nodes.top();
             Nodes.pop();
             temp->next = Nodes.top();
         }
         return head;
     }

//这种做法不需要额外的空间，而且速度更快
     ListNode* reverseList(ListNode* head)
     {
         ListNode *previous = nullptr, *current = head, *next;
         while(current)
         {
             next = current->next;
             current->next = previous;//指向前一个
             previous = current;//当先的节点是下一次循环的前驱节点
             current = next;//下一个节点
         }
         //a->b->c->d->null;
         //结束时,current = null;previous = d;
         return previous;
     }

//递归做法，实际上和递推的道理是一样的，这样看起来还是递推容易理解一些
     ListNode* reverseList(ListNode* head) {
         return reverseList(head, nullptr);
     }
     ListNode* reverseList(ListNode* current, ListNode* previous){
         if(current == nullptr)
             return previous;
         ListNode *next = current->next;
         current->next = previous;
         previous = current;
         current = next;
         return reverseList(current, previous);
     }

//递归做法，理解起来有点难，可以画图理解。
     ListNode* reverseList(ListNode* head)
     {
         if (!head || !head->next)
         {
             return head;
         }

         ListNode* node = reverseList(head->next);

         //a->b->c->d->null
         //d是边界，开始返回
         //node = d; head = c;
         head->next->next = head;//a->b->c<-d;
         head->next = NULL;//c->null

         return node;//return c
     }
 };
