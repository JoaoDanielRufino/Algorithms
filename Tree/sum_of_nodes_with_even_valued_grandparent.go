// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func solve(root, parent, grandparent *TreeNode) int {
    if root == nil {
        return 0
    }

    if grandparent != nil && grandparent.Val % 2 == 0 {
        return root.Val + solve(root.Left, root, parent) + solve(root.Right, root, parent)
    }
    
    return solve(root.Left, root, parent) + solve(root.Right, root, parent)
}

func sumEvenGrandparent(root *TreeNode) int {
    return solve(root, nil, nil)
}
