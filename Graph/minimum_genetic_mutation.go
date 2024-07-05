// https://leetcode.com/problems/minimum-genetic-mutation/description

func oneMutation(startGene, endGene string) bool {
    diff := 0

    for i := range startGene {
        if startGene[i] != endGene[i] {
            diff++

            if diff >= 2 {
                return false
            }
        }
    }

    return true
}

func shortestPath(graph map[string][]string, startGene, endGene string) int {
    queue := []string{startGene}
    dist := map[string]int{}
    seen := map[string]bool{}

    dist[startGene] = 0
    seen[startGene] = true
    for len(queue) > 0 {
        gene := queue[0]
        queue = queue[1:]

        if gene == endGene {
            return dist[endGene]
        }

        for _, adj := range graph[gene] {
            if !seen[adj] {
                queue = append(queue, adj)
                dist[adj] = dist[gene] + 1
                seen[adj] = true
            }
        }
    }

    return -1
}

func minMutation(startGene string, endGene string, bank []string) int {
    graph := map[string][]string{}
    vertices := append([]string{startGene}, bank...)

    for i := 0; i < len(vertices); i++ {
        for j := 1; j < len(vertices); j++ {
            if oneMutation(vertices[i], vertices[j]) {
                graph[vertices[i]] = append(graph[vertices[i]], vertices[j])
                graph[vertices[j]] = append(graph[vertices[j]], vertices[i])
            }
        }
    }

    return shortestPath(graph, startGene, endGene)
}
