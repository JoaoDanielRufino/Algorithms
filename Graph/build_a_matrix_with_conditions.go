// https://leetcode.com/problems/build-a-matrix-with-conditions/description

func dfs(graph map[int][]int, node int, seen, path []bool, stack *[]int) bool {
    seen[node] = true
    path[node] = true

    for _, adj := range graph[node] {
        if path[adj] {
            return true
        }

        if !seen[adj] && dfs(graph, adj, seen, path, stack) {
            return true
        }
    }

    path[node] = false
    *stack = append(*stack, node)

    return false
}

func topologicalSort(conditions [][]int, k int) []int {
    graph := map[int][]int{}

    for _, condition := range conditions {
        graph[condition[0]] = append(graph[condition[0]], condition[1])
    }

    seen, path := make([]bool, k+1), make([]bool, k+1)
    stack := []int{}
    for i := 1; i <= k; i++ {
        if !seen[i] && dfs(graph, i, seen, path, &stack) { //dfs returns true if cycle found
            return []int{}
        }
    }

    sorted := []int{}
    for i := len(stack)-1; i >= 0; i-- {
        sorted = append(sorted, stack[i])
    }

    return sorted
}

func buildMatrix(k int, rowConditions [][]int, colConditions [][]int) [][]int {
    orderedRows := topologicalSort(rowConditions, k) 
    orderedCols := topologicalSort(colConditions, k) 

    if len(orderedRows) == 0 || len(orderedCols) == 0 {
        return [][]int{}
    }

    ans := make([][]int, k)

    for i := range ans {
        ans[i] = make([]int, k)
    }

    for i := range k {
        for j := range k {
            if orderedRows[i] == orderedCols[j] {
                ans[i][j] = orderedRows[i]
            }
        }
    }

    return ans
}
