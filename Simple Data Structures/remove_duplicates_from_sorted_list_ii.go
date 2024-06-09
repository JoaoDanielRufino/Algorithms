// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }

    if head.Next != nil && head.Val == head.Next.Val {
        for head.Next != nil && head.Val == head.Next.Val {
            head = head.Next
        }

        return deleteDuplicates(head.Next)
    }

    head.Next = deleteDuplicates(head.Next)

    return head
}
