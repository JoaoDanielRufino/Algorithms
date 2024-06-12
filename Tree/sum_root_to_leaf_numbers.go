// https://leetcode.com/problems/sum-root-to-leaf-numbers/description

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func solve(root *TreeNode, currSum int) int {
    if root == nil {
        return 0
    }

    currSum = (currSum * 10) + root.Val

    if root.Left == nil && root.Right == nil {
        return currSum
    }

    return solve(root.Left, currSum) + solve(root.Right, currSum)
}

func sumNumbers(root *TreeNode) int {
    return solve(root, 0) 
}
