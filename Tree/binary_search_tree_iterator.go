// https://leetcode.com/problems/binary-search-tree-iterator/description

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Stack struct {
    arr []*TreeNode
}

func (s *Stack) push(node *TreeNode) {
    s.arr = append(s.arr, node)
}

func(s *Stack) pop() *TreeNode {
    size := len(s.arr)
    tmp := s.arr[size-1]
    s.arr = s.arr[:size-1]
    return tmp
}

func (s *Stack) top() *TreeNode {
    return s.arr[len(s.arr)-1]
}

func (s *Stack) isEmpty() bool {
    return len(s.arr) == 0
}
 
type BSTIterator struct {
    stack *Stack 
}


func Constructor(root *TreeNode) BSTIterator {
    iterator := BSTIterator{
        stack: &Stack{
            arr: []*TreeNode{},
        },
    } 

    iterator.traverse(root)

    return iterator
}

func (this *BSTIterator) traverse(root *TreeNode) {
    curr := root

    for curr != nil {
        this.stack.push(curr)
        curr = curr.Left
    }
}


func (this *BSTIterator) Next() int {
    next := this.stack.pop()
    this.traverse(next.Right)
    return next.Val
}


func (this *BSTIterator) HasNext() bool {
    return !this.stack.isEmpty() 
}


/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
