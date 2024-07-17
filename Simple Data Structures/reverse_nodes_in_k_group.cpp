// https://leetcode.com/problems/reverse-nodes-in-k-group/description

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *tmp = head;
        int count = 0;
        
        while(tmp && count != k) {
            tmp = tmp->next;
            count++;
        }
        
        if(count == k) {
            ListNode *prev = reverseKGroup(tmp, k);
            for(int i = 0; i < k; i++) {
                ListNode *tmp2 = head->next;
                head->next = prev;
                prev = head;
                head = tmp2;
            }
            head = prev;
        }
        
        return head;
    }
};
