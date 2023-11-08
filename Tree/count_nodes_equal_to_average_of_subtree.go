// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func solve(root *TreeNode, ans *int) (int, int) {
    if root == nil {
        return 0, 0
    }

    leftSum, leftCount := solve(root.Left, ans)
    rightSum, rightCount := solve(root.Right, ans)
    nodesSum := leftSum + rightSum + root.Val
    nodes := leftCount + rightCount + 1

    if nodesSum / nodes == root.Val {
        *ans++
    }

    return nodesSum, nodes
}

func averageOfSubtree(root *TreeNode) int {
    ans := 0

    solve(root, &ans) 

    return ans
}
