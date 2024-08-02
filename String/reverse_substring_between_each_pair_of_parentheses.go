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

// or adding string to stack
type Stack struct {
    arr []string
}

func (s *Stack) push(x string) {
    s.arr = append(s.arr, x)
}

func (s *Stack) pop() string {
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
    stack := &Stack{
        arr: []string{""},
    }

    for i := range s {
        if s[i] == '(' {
            stack.push("")
        } else if s[i] == ')' {
            toReverse := stack.pop()
            curr := stack.pop()
            stack.push(curr + reverse(toReverse))
        } else {
            curr := stack.pop()
            stack.push(curr + string(s[i]))
        }
    }

    return stack.pop()
}

// or recursive
func reverse(s string) string {
    runes := []rune(s)
    l, r := 0, len(s)-1
    
    for l < r {
        runes[l], runes[r] = runes[r], runes[l]
        l++
        r--
    }
    
    return string(runes)
}

func solve(s string, start int, seen []bool) string {
    ans := ""
    
    for i := start; i < len(s); i++ {
        if seen[i] {
            continue
        }
        
        seen[i] = true
        
        if s[i] == '(' {
            ans += solve(s, i+1, seen)
        } else if s[i] == ')' {
            return reverse(ans)
        } else {
            ans += string(s[i])
        }
    }
    
    return ans
}

func reverseParentheses(s string) string {
    seen := make([]bool, len(s))
    
    return solve(s, 0, seen)
}
