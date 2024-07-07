// https://leetcode.com/problems/binary-tree-pruning/description/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pruneTree(root *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }

    root.Left = pruneTree(root.Left)
    root.Right = pruneTree(root.Right)

    if root.Left == nil && root.Right == nil && root.Val == 0 {
        return nil
    }

    return root
}

// worst approach
func hasOne(root *TreeNode) bool {
    if root == nil {
        return false
    }
    
    if root.Val == 1 {
        return true
    }
    
    return hasOne(root.Left) || hasOne(root.Right)
}

func pruneTree(root *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }
    
    leftHasOne := hasOne(root.Left)
    rightHasOne := hasOne(root.Right)
    
    if !leftHasOne && !rightHasOne && root.Val == 0 {
        return nil
    }
    
    if !leftHasOne {
        root.Left = nil
    } else {
        root.Left = pruneTree(root.Left)
    }
    
    if !rightHasOne {
        root.Right = nil
    } else {
        root.Right = pruneTree(root.Right)
    }
    
    return root
}
