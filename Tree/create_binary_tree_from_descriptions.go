// https://leetcode.com/problems/create-binary-tree-from-descriptions/description

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func createBinaryTree(descriptions [][]int) *TreeNode {
    hash := map[int]*TreeNode{}
    seen := map[int]bool{}
    parent := -1

    for _, d := range descriptions {
        if hash[d[1]] == nil {
            hash[d[1]] = &TreeNode{
                Val: d[1],
            }
        }

        if hash[d[0]] == nil {
            hash[d[0]] = &TreeNode{
                Val: d[0],
            }
        }

        if d[2] == 1 {
            hash[d[0]].Left = hash[d[1]]
        } else {
            hash[d[0]].Right = hash[d[1]]
        }

        seen[d[1]] = true
    }

    for val := range hash {
        if !seen[val] {
            parent = val
        }
    }

    return hash[parent]
}
