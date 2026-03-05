// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description

func countOperations(s, expected string) int {
    operations := 0

    for i := range s {
        if s[i] != expected[i] {
            operations++
        }
    }

    return operations
}

func minOperations(s string) int {
    var a, b strings.Builder

    for i := range s {
        if i % 2 == 0 {
            a.WriteByte('0')
            b.WriteByte('1')
        } else {
            a.WriteByte('1')
            b.WriteByte('0')
        }
    }

    expectedStrings := [2]string{
        a.String(), // 0101010101...
        b.String(), // 1010101010...
    }

    return min(countOperations(s, expectedStrings[0]), countOperations(s, expectedStrings[1]))
}
