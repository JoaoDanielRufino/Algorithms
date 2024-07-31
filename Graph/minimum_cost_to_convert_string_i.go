// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description

type Edge struct {
    to byte
    cost int64
}

func dijkstra(graph map[byte][]Edge, source byte) []int64 {
    dist := make([]int64, 26)

    for i := range dist {
        dist[i] = math.MaxInt
    }

    pq := &PriorityQueue{
        Item{
            Node: source,
            Weight: 0,
        },
    }

    dist[source-'a'] = 0
    heap.Init(pq)

    for pq.Len() > 0 {
        curr := heap.Pop(pq).(Item)

        for _, adj := range graph[curr.Node] {
            next, wt := adj.to, adj.cost
            nextWt := dist[curr.Node-'a'] + wt

            if dist[next-'a'] > nextWt {
                dist[next-'a'] = nextWt
                heap.Push(pq, Item{
                    Node: next,
                    Weight: nextWt,
                })
            }
        }
    }

    return dist
}

func minimumCost(source string, target string, original []byte, changed []byte, cost []int) int64 {
    graph := map[byte][]Edge{}

    for i := range original {
        graph[original[i]] = append(graph[original[i]], Edge{
            to: changed[i],
            cost: int64(cost[i]),
        })
    }

    minDist := make([][]int64, 26)
    for i := 'a'; i <= 'z'; i++ {
        minDist[i-'a'] = dijkstra(graph, byte(i))
    }

    var ans int64 = 0
    for i := range source {
        if source[i] != target[i] {
            minCost := minDist[source[i]-'a'][target[i]-'a']

            if minCost == math.MaxInt {
                return -1
            }

            ans += minCost
        }
    }

    return ans
}


type Item struct {
    Node byte
    Weight int64
}

type PriorityQueue []Item

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool { return pq[i].Weight < pq[j].Weight }
func (pq PriorityQueue) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PriorityQueue) Push(x any) {
	*pq = append(*pq, x.(Item))
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}
