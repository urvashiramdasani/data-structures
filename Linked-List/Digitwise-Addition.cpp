/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * t1 = l1, * t2 = l2;
        int sum = 0;
        ListNode * result = nullptr;
        ListNode * tmp;
        while(t1 && t2) {
            sum += t1->val + t2->val;
            if(sum >= 10) {
                if(result == nullptr) {
                    result = new ListNode(sum % 10);
                    tmp = result;
                }
                else {
                    ListNode * node = new ListNode(sum % 10);
                    tmp->next = node;
                    tmp = tmp->next;
                }
                sum = 1;
            } else {
                if(result == nullptr) {
                    result = new ListNode(sum);
                    tmp = result;
                }
                else {
                    ListNode * node = new ListNode(sum);
                    tmp->next = node;
                    tmp = tmp->next;
                }
                sum = 0;
            }
            t1 = t1->next;
            t2 = t2->next;
        } 
        while(t1) {
            sum += t1->val;
            if(sum >= 10) {
                if(result == nullptr) {
                    result = new ListNode(sum % 10);
                    tmp = result;
                }
                else {
                    ListNode * node = new ListNode(sum % 10);
                    tmp->next = node;
                    tmp = tmp->next;
                }
                sum = 1;
            } else {
                if(result == nullptr) {
                    result = new ListNode(sum);
                    tmp = result;
                }
                else {
                    ListNode * node = new ListNode(sum);
                    tmp->next = node;
                    tmp = tmp->next;
                }
                sum = 0;
            }
            t1 = t1->next;
        }
        while(t2) {
            sum += t2->val;
            if(sum >= 10) {
                if(result == nullptr) {
                    result = new ListNode(sum % 10);
                    tmp = result;
                }
                else {
                    ListNode * node = new ListNode(sum % 10);
                    tmp->next = node;
                    tmp = tmp->next;
                }
                sum = 1;
            } else {
                if(result == nullptr) {
                    result = new ListNode(sum);
                    tmp = result;
                }
                else {
                    ListNode * node = new ListNode(sum);
                    tmp->next = node;
                    tmp = tmp->next;
                }
                sum = 0;
            }
            t2 = t2->next;
        }
        if(sum != 0) {
            ListNode * node = new ListNode(sum);
            tmp->next = node;
        }
        return result;
    }
};
