// https://leetcode.com/problems/delete-nodes-and-return-forest/description/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func solve(root *TreeNode, toDeleteMap map[int]bool, roots *[]*TreeNode) *TreeNode {
    if root == nil {
        return nil
    }
    
    root.Left = solve(root.Left, toDeleteMap, roots)
    root.Right = solve(root.Right, toDeleteMap, roots)
    
    if toDeleteMap[root.Val] {
        if root.Left != nil {
            *roots = append(*roots, root.Left) 
        }
        
        if root.Right != nil {
            *roots = append(*roots, root.Right)
        }
        
        root = nil
    }
    
    return root
}

func delNodes(root *TreeNode, to_delete []int) []*TreeNode {
    toDeleteMap := map[int]bool{}
    
    for _, val := range to_delete {
        toDeleteMap[val] = true
    }
    
    roots := []*TreeNode{}
    
    root = solve(root, toDeleteMap, &roots)
    
    if root != nil {
        roots = append(roots, root)
    }
    
    return roots
}
