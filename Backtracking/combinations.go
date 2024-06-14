// https://leetcode.com/problems/combinations/description

func solve(n, k, index int, curr []int) [][]int {
    if len(curr) == k {
        return [][]int{slices.Clone(curr)}
    }

    ans := [][]int{}
    for i := index; i <= n; i++ {
        curr = append(curr, i)
        ans = append(ans, solve(n, k, i+1, curr)...)
        curr = curr[:len(curr)-1]
    }

    return ans
}

func combine(n int, k int) [][]int {
    return solve(n, k, 1, []int{})
}
