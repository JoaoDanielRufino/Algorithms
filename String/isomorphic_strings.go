// https://leetcode.com/problems/isomorphic-strings

func seen(m map[byte]byte, b byte) bool {
    _, ok := m[b]

    return ok
}

func isIsomorphic(s string, t string) bool {
    sMap, tMap := map[byte]byte{}, map[byte]byte{}

    for i := 0; i < len(s); i++ {
        if seen(sMap, s[i]) && sMap[s[i]] != t[i] {
            return false
        } else if seen(tMap, t[i]) && tMap[t[i]] != s[i] {
            return false
        }

        sMap[s[i]] = t[i]
        tMap[t[i]] = s[i]
    }

    return true
}
