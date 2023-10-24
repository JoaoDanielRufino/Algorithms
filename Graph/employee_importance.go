// https://leetcode.com/problems/employee-importance/description/

/**
 * Definition for Employee.
 * type Employee struct {
 *     Id int
 *     Importance int
 *     Subordinates []int
 * }
 */

func solve(graph map[int]*Employee, id int) int {
    importance := graph[id].Importance

    for _, subordinate := range graph[id].Subordinates {
        importance += solve(graph, subordinate)
    }

    return importance
}

func getImportance(employees []*Employee, id int) int {
    graph := map[int]*Employee{}

    for _, employee := range employees {
        graph[employee.Id] = employee
    }

    return solve(graph, id)
}
