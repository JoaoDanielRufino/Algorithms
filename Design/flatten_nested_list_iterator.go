// https://leetcode.com/problems/flatten-nested-list-iterator/description

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * type NestedInteger struct {
 * }
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * func (this NestedInteger) IsInteger() bool {}
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * // So before calling this method, you should have a check
 * func (this NestedInteger) GetInteger() int {}
 *
 * // Set this NestedInteger to hold a single integer.
 * func (n *NestedInteger) SetInteger(value int) {}
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 * func (this *NestedInteger) Add(elem NestedInteger) {}
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The list length is zero if this NestedInteger holds a single integer
 * // You can access NestedInteger's List element directly if you want to modify it
 * func (this NestedInteger) GetList() []*NestedInteger {}
 */

type NestedIterator struct {
    list []int
    index int
}

func createList(nestedList []*NestedInteger) []int {
    var list []int 

    for _, nested := range nestedList {
        if nested.IsInteger() {
            list = append(list, nested.GetInteger())
        } else {
            integers := createList(nested.GetList()) 
            list = append(list, integers...)
        }
    }

    return list
}

func Constructor(nestedList []*NestedInteger) *NestedIterator {
    return &NestedIterator{
        list: createList(nestedList),
    } 
}

func (this *NestedIterator) Next() int {
    elem := this.list[this.index] 
    this.index++ 
    return elem
}

func (this *NestedIterator) HasNext() bool {
    return this.index < len(this.list)
}
