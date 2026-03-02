// https://leetcode.com/problems/my-calendar-i/description/

// worst solution

type Event struct {
    start int
    end int
}

type MyCalendar struct {
    events []Event 
}


func Constructor() MyCalendar {
    return MyCalendar{
        events: []Event{},
    } 
}


func (this *MyCalendar) Book(startTime int, endTime int) bool {
    for _, event := range this.events {
        if startTime < event.end && endTime > event.start {
            return false
        }
    } 

    this.events = append(this.events, Event{startTime, endTime})

    return true
}

// best solution

type Node struct {
    start int
    end int
    left *Node
    right *Node
}

type MyCalendar struct {
    head *Node 
}


func Constructor() MyCalendar {
    return MyCalendar{
        head: nil,
    } 
}

func insert(head **Node, startTime, endTime int) bool {
    if *head == nil {
        *head = &Node{startTime, endTime, nil, nil}
        return true
    }

    if startTime >= (*head).end {
        return insert(&((*head).right), startTime, endTime)
    }

    if endTime <= (*head).start {
        return insert(&((*head).left), startTime, endTime)
    }

    return false
}

func (this *MyCalendar) Book(startTime int, endTime int) bool {
    return insert(&this.head, startTime, endTime)
}
