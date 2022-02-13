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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode * h1 = list1;
            ListNode * h2 = list2;
            
            if(h1 == nullptr && h2 == nullptr)
                return nullptr;
            
            if(h1 == nullptr && h2 != nullptr)
                    return h2;
            else if(h1 != nullptr && h2 == nullptr)
                    return h1;
            
            ListNode * head = nullptr;
            
            if(h1 -> val <= h2 -> val) {
                    head = h1;
                    h1 = h1 -> next;
            } else {
                    head = h2;
                    h2 = h2 -> next;
            }
            
            ListNode * t = head;
            
            while(h1 != nullptr && h2 != nullptr) {
                    if(h1 -> val <= h2 -> val) {
                            t -> next = h1;
                            h1 = h1 -> next;
                    }
                    else {
                            t -> next = h2;
                            h2 = h2 -> next;
                    }
                    t = t -> next;
            }
            
            while(h1 != nullptr) {
                    t -> next = h1;
                    h1 = h1 -> next;
                    t = t -> next;
            }
            
            while(h2 != nullptr) {
                    t -> next = h2;
                    h2 = h2 -> next;
                    t = t -> next;
            }
            
            return head;
    }
};