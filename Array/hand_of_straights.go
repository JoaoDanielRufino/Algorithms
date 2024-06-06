// https://leetcode.com/problems/hand-of-straights

func isNStraightHand(hand []int, groupSize int) bool {
    if len(hand) % groupSize != 0 {
        return false
    }

    sort.Ints(hand)

    hash := map[int]int{}
    for _, num := range hand {
        hash[num]++
    }

    for _, num := range hand {
        if hash[num] <= 0 {
            continue
        }

        for i := 0; i < groupSize; i++ {
            if hash[num+i] == 0 {
                return false
            }

            hash[num+i]--
        }
    }

    return true
}
