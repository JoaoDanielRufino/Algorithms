// https://leetcode.com/problems/group-anagrams

func countChar(s string) [26]int {
    count := [26]int{}

    for i := range s {
        count[s[i] - 'a']++
    }

    return count
}

func groupAnagrams(strs []string) [][]string {
    countMapping := map[[26]int]int{}
    ans := [][]string{}

    index := 0
    for _, str := range strs {
        count := countChar(str)

        if _, ok := countMapping[count]; !ok {
            countMapping[count] = index
            index++
        }

        pos := countMapping[count]

        if pos >= len(ans) {
            ans = append(ans, []string{str})
        } else {
            ans[pos] = append(ans[pos], str)
        }
    }

    return ans
}
