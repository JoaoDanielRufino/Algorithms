// https://leetcode.com/problems/validate-binary-search-tree/description

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func validate(root *TreeNode, minVal, maxVal int) bool {
    if root == nil {
        return true
    }

    if root.Val <= minVal || root.Val >= maxVal {
        return false
    }

    return validate(root.Left, minVal, root.Val) && validate(root.Right, root.Val, maxVal)
}

func isValidBST(root *TreeNode) bool {
    return validate(root, math.MinInt, math.MaxInt)
}
