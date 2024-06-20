// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description

type Pair struct {
    sum int
    a int
    b int
}

type PriorityQueue []*Pair

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].sum < pq[j].sum
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x any) {
	item := x.(*Pair)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil  // avoid memory leak
	*pq = old[0 : n-1]
	return item
}

func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
    pq := &PriorityQueue{}
    heap.Init(pq)

    for i, num := range nums1 {
        heap.Push(pq, &Pair{
            sum: num + nums2[0],
            a: i,
            b: 0,
        })
    }

    smallestPairs := [][]int{}
    for k > 0 && pq.Len() > 0 {
        pair := heap.Pop(pq).(*Pair)

        smallestPairs = append(smallestPairs, []int{nums1[pair.a], nums2[pair.b]})
        
        next := pair.b + 1
        if next < len(nums2) {
            heap.Push(pq, &Pair{
                sum: nums1[pair.a] + nums2[next],
                a: pair.a,
                b: next,
            })
        }

        k--
    }

    return smallestPairs
}
