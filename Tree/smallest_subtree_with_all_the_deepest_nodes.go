// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func max(a, b int) int {
    if a < b {
        return b
    }
    
    return a
}

func calculateNodesDepth(root *TreeNode, depth int, nodesDepth map[*TreeNode]int) int {
    if root == nil {
        return 0
    }
    
    nodesDepth[root] = depth
    
    leftDepth := calculateNodesDepth(root.Left, depth+1, nodesDepth)
    rightDepth := calculateNodesDepth(root.Right, depth+1, nodesDepth)
    
    return 1 + max(leftDepth, rightDepth)
}

func findSubtree(root *TreeNode, maxDepth int, nodesDepth map[*TreeNode]int) *TreeNode {
    if root == nil {
        return nil
    }
    
    if nodesDepth[root] == maxDepth {
        return root
    }
    
    left := findSubtree(root.Left, maxDepth, nodesDepth)
    right := findSubtree(root.Right, maxDepth, nodesDepth)
    
    if left != nil && right != nil {
        return root
    }
    
    if left != nil {
        return left
    }
    
    return right
}

func subtreeWithAllDeepest(root *TreeNode) *TreeNode {
    nodesDepth := map[*TreeNode]int{}
    
    maxDepth := calculateNodesDepth(root, 1, nodesDepth)  // also returns maxDepth
    
    return findSubtree(root, maxDepth, nodesDepth)
}
