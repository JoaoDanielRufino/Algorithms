// https://leetcode.com/problems/verifying-an-alien-dictionary/description/

func isAlienSorted(words []string, order string) bool {
    letterPosition := map[byte]int{}

    for i := range order {
        letterPosition[order[i]] = i
    }

    for i := 0; i < len(words)-1; i++ {
        for j := range words[i] {
            if j >= len(words[i+1]) {
                return false
            }

            letter1 := words[i][j]
            letter2 := words[i + 1][j]

            if letter1 != letter2 {
                if letterPosition[letter1] > letterPosition[letter2] {
                    return false
                }

                break
            }
        }
    }

    return true
}
