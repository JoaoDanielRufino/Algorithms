// https://leetcode.com/problems/snapshot-array/description/

type Elem struct {
    elem int
    time int
}

type SnapshotArray struct {
    arr [][]Elem 
    time int
}


func Constructor(length int) SnapshotArray {
    return SnapshotArray{
        arr: make([][]Elem, length),
        time: 0,
    }
}


func (this *SnapshotArray) Set(index int, val int)  {
    size := len(this.arr[index])

    if size > 0 && this.arr[index][size-1].time == this.time {
        this.arr[index][size-1].elem = val
    } else {
        this.arr[index] = append(this.arr[index], Elem{
            elem: val,
            time: this.time,
        })
    }
}


func (this *SnapshotArray) Snap() int {
    tmp := this.time
    this.time++
    return tmp
}


func (this *SnapshotArray) Get(index int, snap_id int) int {
    l, r, ans := 0, len(this.arr[index])-1, -1

    for l <= r {
        mid := (l + r) / 2

        if this.arr[index][mid].time <= snap_id {
            ans = mid
            l = mid + 1
        } else {
            r = mid - 1
        }
    }

    if ans == -1 {
        return 0
    }

    return this.arr[index][ans].elem
}


/**
 * Your SnapshotArray object will be instantiated and called as such:
 * obj := Constructor(length);
 * obj.Set(index,val);
 * param_2 := obj.Snap();
 * param_3 := obj.Get(index,snap_id);
 */
