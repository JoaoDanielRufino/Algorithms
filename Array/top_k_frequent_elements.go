// https://leetcode.com/problems/top-k-frequent-elements/description/

func topKFrequent(nums []int, k int) []int {
    freq := map[int]int{}
    bucket := make([][]int, len(nums) + 1)

    for _, num := range nums {
        freq[num]++
    }

    for key, val := range freq {
        if bucket[val] == nil {
            bucket[val] = []int{}
        }

        bucket[val] = append(bucket[val], key)
    }

    ans := make([]int, 0, k)
    pos := len(bucket) - 1
    for pos >= 0 && len(ans) < k {
        if bucket[pos] != nil {
            ans = append(ans, bucket[pos]...)
        }

        pos--
    }

    return ans
}
