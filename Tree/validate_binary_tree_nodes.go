// https://leetcode.com/problems/validate-binary-tree-nodes/description

func findRoot(n int, left, right []int) int {
    children := map[int]bool{}

    for _, val := range left {
        children[val] = true
    }
    for _, val := range right {
        children[val] = true
    }

    for i := 0; i < n; i++ {
        if _, ok := children[i]; !ok {
            return i
        }
    }

    return -1
}

func solve(node int, leftChild, rightChild []int, seen map[int]bool) bool {
    if node == -1 {
        return true
    }

    seen[node] = true
    left := leftChild[node]
    right := rightChild[node]

    if seen[left] || seen[right] {
        return false
    }

    return solve(left, leftChild, rightChild, seen) && solve(right, leftChild, rightChild, seen)
}

func validateBinaryTreeNodes(n int, leftChild []int, rightChild []int) bool {
    root := findRoot(n, leftChild, rightChild)

    if root == -1 {
        return false
    }

    seen := map[int]bool{}

    ok := solve(root, leftChild, rightChild, seen)

    return ok && len(seen) == n
}
