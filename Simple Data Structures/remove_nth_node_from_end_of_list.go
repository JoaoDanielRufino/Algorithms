/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func solve(head *ListNode, n *int) *ListNode {
    if head == nil {
        return nil
    }

    head.Next = solve(head.Next, n)

    *n--

    if *n == 0 {
        return head.Next
    }

    return head
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
    return solve(head, &n)
}
