// https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/description/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sufficientSubset(root *TreeNode, limit int) *TreeNode {
    if root == nil {
        return nil
    } 

    limit -= root.Val

    if root.Left == nil && root.Right == nil {
        if limit > 0 {
            return nil
        }

        return root
    }

    root.Left = sufficientSubset(root.Left, limit)
    root.Right = sufficientSubset(root.Right, limit)

    if root.Left == nil && root.Right == nil {
        return nil
    }

    return root
}

// initial approach (more complex)
func solve(root *TreeNode, limit, currSum int) (*TreeNode, bool) {
    if root == nil {
        return nil, false
    }
    
    currSum += root.Val
    
    if root.Left == nil && root.Right == nil && currSum < limit {
        return root, true 
    }
    
    insufficientLeft, insufficientRight := false, false
    
    root.Left, insufficientLeft = solve(root.Left, limit, currSum)
    root.Right, insufficientRight = solve(root.Right, limit, currSum)
    
    if insufficientLeft && insufficientRight {
        root = nil
        return nil, true
    }
    
    if (insufficientLeft && root.Right == nil) || (insufficientRight && root.Left == nil) {
        root = nil
        return nil, true
    }
    
    if insufficientLeft {
        root.Left = nil
    }
    
    if insufficientRight {
        root.Right = nil
    }
    
    return root, false
}

func sufficientSubset(root *TreeNode, limit int) *TreeNode {
    root, _ = solve(root, limit, 0)
    
    return root
}
