// https://leetcode.com/problems/house-robber-iii/description/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Pair[T, U any] struct {
    first T
    second U
}

func solve(root *TreeNode, prevRobbed bool, memory map[Pair[*TreeNode, bool]]int) int {
    if root == nil {
        return 0
    }

    pair := Pair[*TreeNode, bool]{
        first: root,
        second: prevRobbed,
    }

    if val, ok := memory[pair]; ok {
        return val
    }

    if prevRobbed {
        memory[pair] = solve(root.Left, false, memory) + solve(root.Right, false, memory)
        return memory[pair]
    }

    robbing := root.Val + solve(root.Left, true, memory) + solve(root.Right, true, memory)
    noRobbing := solve(root.Left, false, memory) + solve(root.Right, false, memory)

    memory[pair] = max(robbing, noRobbing)

    return memory[pair]
}

func rob(root *TreeNode) int {
    memory := map[Pair[*TreeNode, bool]]int{}

    return max(solve(root, false, memory), solve(root, true, memory)) 
}
