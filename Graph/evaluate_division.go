// https://leetcode.com/problems/evaluate-division/description/

// (a/b) * (b/c) = a/c
// a -> b -> c = a/c

type Edge struct {
    to string
    weight float64
}

type Graph map[string][]Edge

func solve(graph Graph, current, dest string, seen map[string]bool) float64 {
    if _, contains := graph[current]; !contains {
        return -1
    }

    if current == dest {
        return 1
    }

    seen[current] = true

    for _, adj := range graph[current] {
        if !seen[adj.to] {
            ans := solve(graph, adj.to, dest, seen)

            if ans != -1 {
                return adj.weight * ans
            }
        }
    }

    return -1
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
    graph := Graph{}

    for i, equation := range equations {
        a, b := equation[0], equation[1]
        graph[a] = append(graph[a], Edge{b, values[i]})
        graph[b] = append(graph[b], Edge{a, 1 / values[i]})
    }

    ans := make([]float64, 0, len(queries))
    for _, query := range queries {
        seen := map[string]bool{}
        ans = append(ans, solve(graph, query[0], query[1], seen))
    }

    return ans
}
