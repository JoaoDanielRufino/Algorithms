// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/

func gcd(a, b int) int {
    if b == 0 {
        return a
    }

    return gcd(b, a % b)
}

func hasGroupsSizeX(deck []int) bool {
    freq := map[int]int{}
    
    for _, card := range deck {
        freq[card]++
    }

    ans := freq[deck[0]]
    for _, val := range freq {
        ans = gcd(ans, val)
    }

    return ans > 1
}
