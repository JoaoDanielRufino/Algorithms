// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func solve(root *TreeNode, dist int, count *int) []int {
    if root.Left == nil && root.Right == nil {
        return []int{1}
    }

    left, right := []int{}, []int{}

    if root.Left != nil {
        left = solve(root.Left, dist, count)
    }

    if root.Right != nil {
        right = solve(root.Right, dist, count)
    }

    for i := range left {
        for j := range right {
            if left[i] + right[j] <= dist {
                *count++
            }
        }
    }

    nodesDist := append(left, right...)
    for i := range nodesDist {
        nodesDist[i]++
    }

    return nodesDist
}

func countPairs(root *TreeNode, distance int) int {
    count := 0 

    solve(root, distance, &count)

    return count
}
