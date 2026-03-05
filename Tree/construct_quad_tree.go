/**
 * Definition for a QuadTree node.
 // https://leetcode.com/problems/construct-quad-tree/description/
 
 * type Node struct {
 *     Val bool
 *     IsLeaf bool
 *     TopLeft *Node
 *     TopRight *Node
 *     BottomLeft *Node
 *     BottomRight *Node
 * }
 */

func createLeafNode(value int) *Node {
    nodeVal := false

    if value == 1 {
        nodeVal = true
    }

    return &Node{
        IsLeaf: true,
        Val: nodeVal,
    }
}

func sameValue(grid [][]int, i, j, size int) bool {
    for x := i; x < i + size; x++ {
        for y := j; y < j + size; y++ {
            if grid[x][y] != grid[i][j] {
                return false
            }
        }
    }

    return true
}

func createQuadTree(grid [][]int, i, j, size int) *Node {
    if sameValue(grid, i, j, size) {
        return createLeafNode(grid[i][j])
    }

    node := &Node{Val: true}
    size /= 2

    node.TopLeft = createQuadTree(grid, i, j, size)
    node.TopRight = createQuadTree(grid, i, j + size, size)
    node.BottomLeft = createQuadTree(grid, i + size, j, size)
    node.BottomRight = createQuadTree(grid, i + size, j + size, size)

    return node
}

func construct(grid [][]int) *Node {
    return createQuadTree(grid, 0, 0, len(grid))
}
