// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func solve(root *TreeNode, currSum *int) *TreeNode {
    if root == nil {
        return nil
    }

    root.Right = solve(root.Right, currSum) 

    *currSum += root.Val
    root.Val = *currSum

    root.Left = solve(root.Left, currSum)

    return root
}

func bstToGst(root *TreeNode) *TreeNode {
    currSum := 0
    return solve(root, &currSum)
}
