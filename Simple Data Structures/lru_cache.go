// https://leetcode.com/problems/lru-cache/description

// Note: to better improve performance of List methods, consider using doubly linked list to get remove with O(1) complexity.
// the current implementation uses a single linked list, so to remove a Node in the list is O(n) complexity.

// using go List library
type LRUCache struct {
    list *list.List
    hash map[int]*list.Element
    capacity int
}

type KeyValue struct {
    Key   int
    Val   int
}

func Constructor(capacity int) LRUCache {
    return LRUCache{
        list: list.New(),
        hash: map[int]*list.Element{},
        capacity: capacity,
    }    
}

func (this *LRUCache) shiftFront(node *list.Element) {
    this.list.MoveToFront(node)
    this.hash[node.Value.(KeyValue).Key] = this.list.Front()
}

func (this *LRUCache) Get(key int) int {
    node, ok := this.hash[key]

    if !ok {
        return -1
    }

    this.shiftFront(node) 

    return node.Value.(KeyValue).Val
}

func (this *LRUCache) Put(key int, value int)  {
    node, ok := this.hash[key]

    if ok {
        node.Value = KeyValue{
            Key: key,
            Val: value,
        }
        this.shiftFront(node)
        return
    }

    if len(this.hash) == this.capacity {
        delete(this.hash, this.list.Back().Value.(KeyValue).Key) 
        this.list.Remove(this.list.Back())
    }

    this.list.PushFront(KeyValue{
        Key: key,
        Val: value,
    })
    this.hash[key] = this.list.Front()
}


// or implementing the list
type Node struct {
    Key  int
    Val  int
    Next *Node
}

type List struct {
    Head *Node
    Tail *Node
}

func (l *List) PushFront(key, val int) {
    newNode := &Node{
        Key: key,
        Val: val,
    }

    if l.Head == nil {
        l.Head = newNode
        l.Tail = newNode
    } else {
        newNode.Next = l.Head
        l.Head = newNode
    }
}

func (l *List) PopBack() {
    if l.Head == l.Tail {
        l.Head = nil
        l.Tail = nil
    } else {
        var prev *Node = nil
        curr := l.Head

        for curr.Next != nil {
            prev = curr
            curr = curr.Next
        }

        l.Tail = prev
        l.Tail.Next = nil
    }
}

func (l *List) Erase(node *Node) {
    if node == l.Head && node == l.Tail {
        l.Head = nil
        l.Tail = nil
    } else if node == l.Head {
        l.Head = l.Head.Next
    } else {
        var prev *Node = nil
        curr := l.Head

        for curr != node {
            prev = curr
            curr = curr.Next
        }

        prev.Next = curr.Next

        if curr == l.Tail {
            l.Tail = prev
        }
    }
}

type LRUCache struct {
    list *List
    hash map[int]*Node
    capacity int
}

func Constructor(capacity int) LRUCache {
    return LRUCache{
        list: &List{},
        hash: map[int]*Node{},
        capacity: capacity,
    }    
}

func (this *LRUCache) shiftFront(key int, node *Node) {
    this.list.Erase(node)
    this.list.PushFront(key, node.Val)
    this.hash[key] = this.list.Head
}

func (this *LRUCache) Get(key int) int {
    node, ok := this.hash[key]

    if !ok {
        return -1
    }

    this.shiftFront(key, node) 

    return node.Val
}

func (this *LRUCache) Put(key int, value int)  {
    node, ok := this.hash[key]

    if ok {
        node.Val = value
        this.shiftFront(key, node)
        return
    }

    if len(this.hash) == this.capacity {
        delete(this.hash, this.list.Tail.Key) 
        this.list.PopBack()
    }

    this.list.PushFront(key, value)
    this.hash[key] = this.list.Head
}
