// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        
        while(curr) {
            ListNode *aux = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aux;
        }
        
        return prev;
    }
};

// recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *tmp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return tmp;
    }
};
