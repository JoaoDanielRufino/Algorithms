// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description

func initialize(size, defaultValue int) []int {
    arr := make([]int, size)

    for i := range arr {
        arr[i] = defaultValue
    }

    return arr
}

func dfs(graph map[int][]int, node, depth int, distances []int, seen map[int]bool) {
    seen[node] = true

    distances[node] = min(distances[node], depth)

    for _, adj := range graph[node] {
        if !seen[adj] {
            dfs(graph, adj, depth + 1, distances, seen)
        }
    }

    seen[node] = false
}

func closestMeetingNode(edges []int, node1 int, node2 int) int {
    graph := map[int][]int{}

    for from, to := range edges {
        if to != -1 {
            graph[from] = append(graph[from], to)
        }
    }

    seen := map[int]bool{}
    distancesFromNode1 := initialize(len(edges), math.MaxInt)
    distancesFromNode2 := initialize(len(edges), math.MaxInt)

    dfs(graph, node1, 0, distancesFromNode1, seen)
    dfs(graph, node2, 0, distancesFromNode2, seen)

    minDist := math.MaxInt
    ans := -1
    for i := range edges {
        if distancesFromNode1[i] == math.MaxInt || distancesFromNode2[i] == math.MaxInt {
            continue
        }

        maxDist := max(distancesFromNode1[i], distancesFromNode2[i])
        if maxDist < minDist {
            minDist = maxDist
            ans = i
        }
    }

    return ans
}
