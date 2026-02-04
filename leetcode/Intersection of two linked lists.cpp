#160.相交链表

#题目链接：https://leetcode.cn/problems/intersection-of-two-linked-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
  //先选出长的链表，由diff得到差值，让长的链表先走差值的步数，最后两个链表节点一次向下循环，看什么时候节点相交
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        struct ListNode *a;
        struct ListNode *b;
        a = headA,b = headB;
        int diff = 0;
        while(a->next != NULL){
            a = a->next;
            diff++; 
        }
        while(b->next != NULL){
            b = b->next;
            diff--;
        }
        if(a != b){
            return NULL;
        }
        if(diff > 0){
            a = headA;
            b = headB;
        }else{
            a = headB;
            b = headA;
        }
        diff = abs(diff);
        while(diff-- != 0){
            a = a->next;
        }
        while(a != b){
            a = a->next;
            b = b->next;
        }
        return a;
        
    }
};
