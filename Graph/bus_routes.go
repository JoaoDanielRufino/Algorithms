// https://leetcode.com/problems/bus-routes/description/

type Queue[T any] struct {
    arr []T
}

func (q *Queue[T]) push(elem T) {
    q.arr = append(q.arr, elem)
}

func (q *Queue[T]) pop() T {
    elem := q.arr[0]
    q.arr = q.arr[1:]
    return elem
}

func (q *Queue[T]) size() int {
    return len(q.arr)
}

func numBusesToDestination(routes [][]int, source int, target int) int {
    if source == target {
        return 0
    }

    graph := map[int][]int{} 

    for i, route := range routes {
        for _, stop := range route {
            graph[stop] = append(graph[stop], i)
        }
    }

    q := &Queue[int]{
        arr: []int{},
    }
    seen := map[int]bool{}

    for _, route := range graph[source] {
        q.push(route)
        seen[route] = true
    }

    count := 1
    for q.size() > 0 {
        size := q.size()

        for i := 0; i < size; i++ {
            route := q.pop()

            for _, stop := range routes[route] {
                if stop == target {
                    return count
                }

                for _, nextRoute := range graph[stop] {
                    if !seen[nextRoute] {
                        q.push(nextRoute)
                        seen[nextRoute] = true
                    }
                }
            }
        }

        count++
    }

    return -1
}
