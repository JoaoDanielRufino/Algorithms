// https://leetcode.com/problems/longest-palindrome/description

func longestPalindrome(s string) int {
    freq := map[byte]int{}

    for i := range s {
        freq[s[i]]++
    }

    ans, singleOddAdded := 0, false
    for _, val := range freq {
        if val % 2 == 0 {
            ans += val
        } else {
            if !singleOddAdded {
                ans += val
                singleOddAdded = true
            } else {
                ans += val - 1
            }
        }
    }

    return ans
}
