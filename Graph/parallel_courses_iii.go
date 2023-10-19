func max(a, b int) int {
    if a < b {
        return b
    }
    return a
}

func dfs(graph map[int][]int, node int, time []int, dist map[int]int) int {
    if len(graph[node]) == 0 {
        return time[node]
    }

    if val, ok := dist[node]; ok {
        return val
    }

    ans := 0
    for _, adj := range graph[node] {
        ans = max(ans, dfs(graph, adj, time, dist))
    }

    dist[node] = time[node] + ans
    return dist[node]
}

func minimumTime(n int, relations [][]int, time []int) int {
    graph := map[int][]int{} 

    for _, relation := range relations {
        a := relation[0] - 1
        b := relation[1] - 1
        graph[a] = append(graph[a], b)
    }

    ans := 0
    dist := map[int]int{}
    for i := 0; i < n; i++ {
        ans = max(ans, dfs(graph, i, time, dist))
    }

    return ans
}
