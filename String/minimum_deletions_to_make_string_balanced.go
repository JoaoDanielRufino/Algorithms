// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description

func min(a, b int) int {
    if a < b {
        return a
    }

    return b
}

func minimumDeletions(s string) int {
    aCount, bCount := make([]int, len(s)), make([]int, len(s))
    count := 0

    // counting 'b' chars at left
    for i := range s {
        bCount[i] = count
        if s[i] == 'b' {
            count++
        }
    }

    // counting 'a' chars at right
    count = 0
    for i := len(s)-1; i >= 0; i-- {
        aCount[i] = count
        if s[i] == 'a' {
            count++
        }
    }

    // choosing index 'i' to divide the string
    ans := len(s)
    for i := range s {
        ans = min(ans, aCount[i] + bCount[i])
    }

    return ans
}

// stack also works
type Stack struct {
    arr []byte
}

func (s *Stack) push(b byte) {
    s.arr = append(s.arr, b)
}

func (s *Stack) pop() byte {
    tmp := s.arr[len(s.arr)-1]
    s.arr = s.arr[:len(s.arr)-1]
    return tmp
}

func (s *Stack) top() byte {
    return s.arr[len(s.arr)-1]
}

func (s *Stack) isEmpty() bool {
    return len(s.arr) == 0
}

func minimumDeletions(s string) int {
    stack := Stack{
        arr: []byte{},
    }

    ans := 0
    for i := range s {
        if !stack.isEmpty() && stack.top() == 'b' && s[i] == 'a' {
            stack.pop()
            ans++
        } else {
            stack.push(s[i])
        }
    }

    return ans
}
