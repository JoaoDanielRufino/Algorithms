// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description

type Stack struct {
    arr []int
}

func (s *Stack) push(x int) {
    s.arr = append(s.arr, x)
}

func (s *Stack) pop() int {
    tmp := s.arr[len(s.arr)-1]
    s.arr = s.arr[:len(s.arr)-1]
    return tmp
}

func (s *Stack) len() int {
    return len(s.arr)
}

func reverse(s string) string {
    reversed := []rune(s)
    start, end := 0, len(s)-1

    for start < end {
        reversed[start], reversed[end] = reversed[end], reversed[start]
        start++
        end--
    }

    return string(reversed)
}

func reverseParentheses(s string) string {
    ans := ""
    stack := &Stack{
        arr: []int{},
    }

    for i := range s {
        if s[i] == '(' {
            stack.push(len(ans))
        } else if s[i] == ')' {
            start := stack.pop()
            reversed := reverse(ans[start:])
            ans = ans[:start]
            ans += reversed
        } else {
            ans += string(s[i])
        }
    }

    return ans
}
