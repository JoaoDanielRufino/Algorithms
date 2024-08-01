// https://leetcode.com/problems/asteroid-collision/description

type Stack struct {
    arr []int
}

func (s *Stack) push(elem int) {
    s.arr = append(s.arr, elem)
}

func (s *Stack) pop() int {
    tmp := s.arr[len(s.arr)-1]
    s.arr = s.arr[:len(s.arr)-1]
    return tmp
}

func (s *Stack) top() int {
    return s.arr[len(s.arr)-1]
}

func (s *Stack) empty() bool {
    return len(s.arr) == 0
}

func (s *Stack) size() int {
    return len(s.arr)
}

func abs(a int) int {
    if a < 0 {
        return -a
    }

    return a
}

func asteroidCollision(asteroids []int) []int {
    stack := &Stack{
        arr: []int{},
    } 

    for _, ast := range asteroids {
        if ast > 0 || stack.empty() {
            stack.push(ast)
            continue
        }

        for !stack.empty() && stack.top() > 0 && abs(ast) > stack.top() {
            stack.pop()
        }

        if !stack.empty() && abs(ast) == stack.top() {
            stack.pop()
        } else if stack.empty() || stack.top() < 0 {
            stack.push(ast)
        }
    }

    ans := make([]int, stack.size())
    for i := len(ans)-1; i >= 0; i-- {
        ans[i] = stack.pop()
    }

    return ans
}
