// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/

func minSteps(s string, t string) int {
    freqS, freqT := map[byte]int{}, map[byte]int{}
    
    for i := range s {
        freqS[s[i]]++
        freqT[t[i]]++
    }
    
    ans := 0
    for k, v := range freqS {
        if v > freqT[k] {
            ans += v - freqT[k]
        }
    }
    
    return ans
}

// or with one map
func minSteps(s string, t string) int {
    freq := map[byte]int{}
    
    for i := range s {
        freq[s[i]]++
        freq[t[i]]--
    }
    
    ans := 0
    for _, count := range freq {
        if count > 0 {
            ans += count
        }
    }
    
    return ans
}
