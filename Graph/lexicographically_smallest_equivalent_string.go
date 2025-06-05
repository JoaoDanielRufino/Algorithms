// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/

func findMin(graph map[byte][]byte, curr byte, seen map[byte]bool) byte {
    seen[curr] = true

    minSoFar := curr
    for _, adj := range graph[curr] {
        if !seen[adj] {
            minSoFar = min(minSoFar, findMin(graph, adj, seen))
        }
    }

    return minSoFar
}

func smallestEquivalentString(s1 string, s2 string, baseStr string) string {
    graph := map[byte][]byte{}

    for i := range s1 {
        if s1[i] != s2[i] {
            graph[s1[i]] = append(graph[s1[i]], s2[i])
            graph[s2[i]] = append(graph[s2[i]], s1[i])
        }
    }

    ans := make([]byte, 0, len(baseStr))
    for i := range baseStr {
        seen := map[byte]bool{}
        ans = append(ans, findMin(graph, baseStr[i], seen))
    }

    return string(ans)
}
