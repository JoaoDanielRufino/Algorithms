// https://leetcode.com/problems/maximum-frequency-stack/

func max(a, b int) int {
    if a < b {
        return b
    }
    return a
}

type Stack struct {
    arr []int
}

func (s *Stack) push(num int) {
    s.arr = append(s.arr, num)
}

func (s *Stack) pop() int {
    size := len(s.arr)
    num := s.arr[size-1]
    s.arr = s.arr[:size-1]
    return num
}

func (s *Stack) isEmpty() bool {
    return len(s.arr) == 0
}

type FreqStack struct {
    stacks map[int]*Stack
    freq map[int]int
    maxFreq int
}


func Constructor() FreqStack {
    return FreqStack{
        stacks: map[int]*Stack{},
        freq: map[int]int{},
        maxFreq: 0,
    } 
}


func (this *FreqStack) Push(val int)  {
    this.freq[val]++
    
    if this.stacks[this.freq[val]] == nil {
        this.stacks[this.freq[val]] = &Stack{
            arr: []int{},
        }
    }
    
    this.maxFreq = max(this.maxFreq, this.freq[val])
    this.stacks[this.freq[val]].push(val)
}


func (this *FreqStack) Pop() int {
    num := this.stacks[this.maxFreq].pop()
    
    this.freq[num]--
    
    if this.stacks[this.maxFreq].isEmpty() {
        this.maxFreq--
    }
    
    return num
}


/**
 * Your FreqStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * param_2 := obj.Pop();
 */
