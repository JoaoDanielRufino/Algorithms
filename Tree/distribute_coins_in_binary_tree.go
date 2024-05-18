// https://leetcode.com/problems/distribute-coins-in-binary-tree/description

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func abs(a int) int {
    if a < 0 {
        return a * -1
    }
    return a
}

func solve(root *TreeNode, moves *int) int {
    if root == nil {
        return 0
    }

    leftCoins := solve(root.Left, moves)
    rightCoins := solve(root.Right, moves)

    *moves += abs(leftCoins) + abs(rightCoins)

    // Number of coins each node can distribute
    return (root.Val - 1) + leftCoins + rightCoins
}

func distributeCoins(root *TreeNode) int {
    moves := 0
    solve(root, &moves)
    return moves
}
