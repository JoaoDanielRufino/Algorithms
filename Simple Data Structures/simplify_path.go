// https://leetcode.com/problems/simplify-path/description

type Stack struct {
    arr []string
}

func (s *Stack) push(b string) {
    s.arr = append(s.arr, b) 
}

func (s *Stack) pop() string {
    last := len(s.arr)-1
    tmp := s.arr[last]
    s.arr = s.arr[:last]
    return tmp
}

func (s Stack) isEmpty() bool {
    return len(s.arr) == 0
}

func simplifyPath(path string) string {
    splittedPath := strings.Split(path, "/")

    stack := Stack{
        arr: []string{},
    }
    for _, sPath := range splittedPath {
        if sPath == ".." && !stack.isEmpty() {
            stack.pop()
        } else if sPath != "." && sPath != "" && sPath != ".." {
            stack.push(sPath)
        }
    }

    ans := ""
    for !stack.isEmpty() {
        ans = fmt.Sprintf("/%s%s", stack.pop(), ans)
    }

    if len(ans) == 0 {
        return "/"
    }

    return ans
}
