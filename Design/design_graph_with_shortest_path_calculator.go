// https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description

type Edge struct {
    Weight int
    Vertex Vertex
}

type Vertex struct {
    Val int
    Edges map[int]Edge
}

type Graph struct {
    Vertices map[int]Vertex    
    Size int
}

func Constructor(n int, edges [][]int) Graph {
    graph := Graph{
        Vertices: map[int]Vertex{},
        Size: n, 
    }

    for i := 0; i < n; i++ {
        graph.Vertices[i] = Vertex{
            Val: i,
            Edges: map[int]Edge{},
        }
    }

    for _, edge := range edges {
        graph.AddEdge(edge)
    }

    return graph
}

func (this *Graph) AddEdge(edge []int)  {
    from := edge[0]
    to := edge[1]
    cost := edge[2]
    
    this.Vertices[from].Edges[to] = Edge{
        Weight: cost,
        Vertex: this.Vertices[to],
    }
}

func (this *Graph) ShortestPath(node1 int, node2 int) int {
    dist := []int{} 
    for i := 0; i < this.Size; i++{
        dist = append(dist, math.MaxInt)
    }

    pq := &PriorityQueue{
        Item{
            Node: node1,
            Weight: 0,
        },
    }

    dist[node1] = 0
    heap.Init(pq)
    for pq.Len() > 0 {
        curr := heap.Pop(pq).(Item)

        if curr.Node == node2 {
            return dist[node2]
        }

        for _, adj := range this.Vertices[curr.Node].Edges {
            if dist[adj.Vertex.Val] > dist[curr.Node] + adj.Weight {
                dist[adj.Vertex.Val] = dist[curr.Node] + adj.Weight
                heap.Push(pq, Item{Node: adj.Vertex.Val, Weight: dist[adj.Vertex.Val]})
            }
        }
    }

    return -1
}

type Item struct {
    Node int
    Weight int
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


/**
 * Your Graph object will be instantiated and called as such:
 * obj := Constructor(n, edges);
 * obj.AddEdge(edge);
 * param_2 := obj.ShortestPath(node1,node2);
 */
