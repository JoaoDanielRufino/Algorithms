// https://leetcode.com/problems/reconstruct-itinerary/description/

func reverse(s []string) {
    l, r := 0, len(s)-1
    
    for l < r {
        s[l], s[r] = s[r], s[l]
        l++
        r--
    }
}

func solve(graph map[string][]string, curr string, path *[]string) {
    for len(graph[curr]) > 0 {
        adj := graph[curr][0] 
        graph[curr] = graph[curr][1:]
        solve(graph, adj, path)
    }
    
    *path = append(*path, curr)
}

func findItinerary(tickets [][]string) []string {
    graph := map[string][]string{}
    
    for _, ticket := range tickets {
        from, to := ticket[0], ticket[1]
        graph[from] = append(graph[from], to)
    }
    
    for from := range graph {
        sort.Strings(graph[from])
    }
    
    path := []string{}
    solve(graph, "JFK", &path)
    
    reverse(path)
    
    return path
}
