/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <cstddef>
#include <queue>
class Solution {
public:
    struct cmp{
        bool operator()(ListNode* a,ListNode* b){  //operator()是「重载函数调用运算符 ()」,结构体cmp的对象可以被结构体内部的函数operator（）优先调用，实现程序内部的自动排序
                                                   //return a->val > b->val;的方式实现了最小栈的功能，当a的val小于b的val，return false，a的优先级大，放在栈顶，后面的步骤优先弹出，实现链表节点数值先从小到大有序
            return a->val > b->val;
        }
    };
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;   //priority_queue<..., cmp> pq 中，cmp 是自定义比较器，用于指定优先队列的元素排序 / 优先级规则,是C++自带函数
                                                              ////默认的排序规则是最大栈：输入对象a和b，当返回true时，b的优先级大于a的优先级，优先级大的被放到栈顶，cmp改变默认功能，实现最小栈排列
        for(int i = 0;i<lists.size();i++)
        {
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }
        ListNode* res = new ListNode(-1);
        ListNode* head = res;
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            head->next  = temp;
            head = head->next;
            if(temp->next != NULL){
                pq.push(temp->next);
            }
        }
        return res->next;
    }
};
