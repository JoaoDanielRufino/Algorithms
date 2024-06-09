// https://leetcode.com/problems/rotate-list/description

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
    if head == nil {
        return nil
    }

    tail := head
    size := 1

    for tail.Next != nil {
        tail = tail.Next
        size++
    }

    // create a cycle
    tail.Next = head

    k = k % size
    if k > 0 {
        for i := 0; i < size-k; i++ {
            tail = tail.Next
        }
    }

    newHead := tail.Next
    tail.Next = nil

    return newHead
}
