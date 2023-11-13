// https://leetcode.com/problems/sort-vowels-in-a-string/description

func isVowel(c rune) bool {
    c = unicode.ToUpper(c)

    if c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O' {
        return true
    }

    return false
}

func sortVowels(s string) string {
    var vowels []rune

    for _, c := range s {
        if isVowel(c) {
            vowels = append(vowels, c)
        }
    }

    sort.Slice(vowels, func(i, j int) bool {
        return vowels[i] < vowels[j]
    })

    var ans string
    index := 0
    for _, c := range s {
        if isVowel(c) {
            ans += string(vowels[index])
            index++
        } else {
            ans += string(c)
        }
    }

    return ans
}

// Second solution
func isVowel(c rune) bool {
    c = unicode.ToUpper(c)

    if c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O' {
        return true
    }

    return false
}

func sortVowels(s string) string {
    vowels := map[rune]int{}

    for _, c := range s {
        if isVowel(c) {
            vowels[c]++
        }
    }

    var ans string
    runes := []rune{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'}
    index := 0
    for _, c := range s {
        if !isVowel(c) {
            ans += string(c)
        } else {
            for vowels[runes[index]] == 0 {
                index++
            }

            ans += string(runes[index])
            vowels[runes[index]]--
        }
    }

    return ans
}
