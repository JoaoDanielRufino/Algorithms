// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func lca(root *TreeNode, p, q int) *TreeNode {
    if root == nil {
        return nil
    }

    if root.Val == p || root.Val == q {
        return root
    }

    left := lca(root.Left, p, q)
    right := lca(root.Right, p, q)

    if left != nil && right != nil {
        return root
    }

    if left != nil {
        return left
    }

    return right
}

func findPath(root *TreeNode, target int, currPath []string) ([]string, bool) {
    if root == nil {
        return currPath, false
    }

    if root.Val == target {
        return currPath, true
    }

    path, found := findPath(root.Left, target, append(currPath, "L"))
    if found {
        return path, true
    }

    path, found = findPath(root.Right, target, append(currPath, "R"))
    return path, found
}

func getDirections(root *TreeNode, startValue int, destValue int) string {
    lcaNode := lca(root, startValue, destValue)

    p1, _ := findPath(lcaNode, startValue, []string{})
    p2, _ := findPath(lcaNode, destValue, []string{})

    return strings.Repeat("U", len(p1)) + strings.Join(p2, "")
}
