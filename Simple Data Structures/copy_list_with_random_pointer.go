// https://leetcode.com/problems/copy-list-with-random-pointer/description

/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

// Better
func copyRandomList(head *Node) *Node {
    curr := head
    hash := map[*Node]*Node{}

    for curr != nil {
        hash[curr] = &Node{
            Val: curr.Val,
        }
        curr = curr.Next
    }

    curr = head
    for curr != nil {
        tmp := hash[curr]
        tmp.Next = hash[curr.Next]
        tmp.Random = hash[curr.Random]
        curr = curr.Next
    }

    return hash[head]
}

// Worse
func copyRandomList(head *Node) *Node {
    ans := &Node{} 
    curr, currAns := head, ans
    indexToNode, nodeToIndex := map[int]*Node{}, map[*Node]int{}

    index := 0
    for curr != nil {
        currAns.Next = &Node{
            Val: curr.Val,
            Next: nil,
            Random: nil,
        }

        currAns = currAns.Next

        indexToNode[index] = currAns
        nodeToIndex[curr] = index

        index++
        curr = curr.Next
    } 

    currAns = ans.Next
    curr = head
    for curr != nil {
        if curr.Random == nil {
            currAns.Random = nil
        } else {
            currAns.Random = indexToNode[nodeToIndex[curr.Random]]
        }
        
        curr = curr.Next
        currAns = currAns.Next
    }

    return ans.Next
}
