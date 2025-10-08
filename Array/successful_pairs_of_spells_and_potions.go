// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description

func countSuccessfulPairs(spell int64, potions []int, success int64) int {
    l, r := 0, len(potions)-1
    count := 0

    for l <= r {
        mid := (l + r) / 2

        strength := spell * int64(potions[mid])

        if strength >= success {
            r = mid - 1
            count = len(potions) - mid
        } else {
            l = mid + 1
        }
    }

    return count
}

func successfulPairs(spells []int, potions []int, success int64) []int {
    ans := make([]int, 0, len(spells))

    sort.Ints(potions)

    for _, spell := range spells {
        ans = append(ans, countSuccessfulPairs(int64(spell), potions, success))
    }

    return ans
}
