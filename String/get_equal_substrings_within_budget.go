// https://leetcode.com/problems/get-equal-substrings-within-budget/description

func computeDiff(a, b byte) int {
    if a > b {
        return int(a - b)
    }

    return int(b - a)
}

func max(a, b int) int {
    if a < b {
        return b
    }

    return a
}

func equalSubstring(s string, t string, maxCost int) int {
    l, r, ans := 0, 0, 0

    for r < len(s) {
        maxCost -= computeDiff(s[r], t[r])

        if maxCost < 0 {
            maxCost += computeDiff(s[l], t[l])
            l++
        } else {
            ans = max(ans, (r-l)+1)
        }

        r++
    }

    return ans
}
