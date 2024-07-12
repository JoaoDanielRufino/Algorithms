// https://leetcode.com/problems/maximum-score-from-removing-substrings/description

type Stack struct {
    arr []byte
}

func (s *Stack) push(x byte) {
    s.arr = append(s.arr, x)
}

func (s *Stack) pop() byte {
    tmp := s.arr[len(s.arr)-1]
    s.arr = s.arr[:len(s.arr)-1]
    return tmp
}

func (s *Stack) top() byte {
    return s.arr[len(s.arr)-1]
}

func (s *Stack) len() int {
    return len(s.arr)
}

func removeAndCount(s, sub string, val int) (int, string) {
    count := 0
    stack := &Stack{
        arr: []byte{},
    }

    for i := range s {
        if s[i] == sub[1] && stack.len() > 0 && stack.top() == sub[0] {
            stack.pop()
            count += val
        } else {
            stack.push(s[i])
        }
    }

    return count, string(stack.arr)
}

func maximumGain(s string, x int, y int) int {
    ans := 0

    if x > y {
        score, removed := removeAndCount(s, "ab", x)
        ans += score
        score, _ = removeAndCount(removed, "ba", y)
        ans += score
    } else {
        score, removed := removeAndCount(s, "ba", y)
        ans += score
        score, _ = removeAndCount(removed, "ab", x)
        ans += score
    }

    return ans
}
