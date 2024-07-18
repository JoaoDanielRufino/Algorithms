// https://leetcode.com/problems/min-stack/description

type MinStack struct {
    stack []int
    minStack []int
}


func Constructor() MinStack {
    return MinStack{
        stack: []int{},
        minStack: []int{},
    } 
}


func (this *MinStack) Push(val int) {
    this.stack = append(this.stack, val)

    if len(this.minStack) == 0 || val <= this.minStack[len(this.minStack)-1] {
        this.minStack = append(this.minStack, val)
    }
}


func (this *MinStack) Pop() {
    lenStack := len(this.stack)
    lenMinStack := len(this.minStack)

    removed := this.stack[lenStack-1]
    this.stack = this.stack[:lenStack-1]

    if removed == this.minStack[lenMinStack-1] {
        this.minStack = this.minStack[:lenMinStack-1]
    }
}


func (this *MinStack) Top() int {
    return this.stack[len(this.stack)-1] 
}


func (this *MinStack) GetMin() int {
    return this.minStack[len(this.minStack)-1] 
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
