// https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *sorted = nullptr;
        ListNode *curr = head;
        
        while(curr) {
            ListNode *aux = curr->next;
            if(!sorted || curr->val <= sorted->val) {
                curr->next = sorted;
                sorted = curr;
            }
            else {
                ListNode *tmp = sorted;
                while(tmp->next && tmp->next->val < curr->val)
                    tmp = tmp->next;
                
                curr->next = tmp->next;
                tmp->next = curr;
            }
            curr = aux;
        }
        
        return sorted;
    }
};