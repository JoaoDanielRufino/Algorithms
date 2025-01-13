// https://leetcode.com/problems/count-vowel-strings-in-ranges/description

func isVowel(r rune) bool {
    lower := unicode.ToLower(r)

    return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'
}

func isValid(word string) bool {
    return isVowel(rune(word[0])) && isVowel(rune(word[len(word)-1]))
}

func vowelStrings(words []string, queries [][]int) []int {
    vowelsCount := make([]int, len(words))

    for i, word := range words {
        if i > 0 {
            vowelsCount[i] = vowelsCount[i-1]
        }

        if isValid(word) {
            vowelsCount[i]++
        }
    }

    ans := make([]int, len(queries))
    for i, query := range queries {
        if query[0] == 0 {
            ans[i] = vowelsCount[query[1]]
        } else {
            ans[i] = vowelsCount[query[1]] - vowelsCount[query[0]-1]
        }
    }

    return ans
}
