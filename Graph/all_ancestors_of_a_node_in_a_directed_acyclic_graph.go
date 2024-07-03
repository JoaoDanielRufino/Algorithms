// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description

func dfs(graph map[int][]int, u, ancestor int, seen []bool, ans [][]int) {
    seen[u] = true

    for _, adj := range graph[u] {
        if !seen[adj] {
            ans[adj] = append(ans[adj], ancestor)
            dfs(graph, adj, ancestor, seen, ans)
        }
    }
}

func getAncestors(n int, edges [][]int) [][]int {
    graph := map[int][]int{}

    for _, edge := range edges {
        u, v := edge[0], edge[1]
        graph[u] = append(graph[u], v)
    }

    ans := make([][]int, n)
    for i := range n {
        seen := make([]bool, n)
        dfs(graph, i, i, seen, ans)
    }

    return ans
}
