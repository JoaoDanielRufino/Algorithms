// https://leetcode.com/problems/remove-nodes-from-linked-list/description

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func max(a, b int) int {
    if a < b {
        return b
    }

    return a
}

func solve(node *ListNode, currMax *int) {
    if node == nil {
        return
    }

    solve(node.Next, currMax)

    if node.Val < *currMax {
        node.Val = node.Next.Val
        node.Next = node.Next.Next
    } 

    *currMax = max(*currMax, node.Val)
}

func removeNodes(head *ListNode) *ListNode {
    currMax := -1

    solve(head, &currMax)

    return head
}
