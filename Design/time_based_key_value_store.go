// https://leetcode.com/problems/time-based-key-value-store/description/

type timeMapValue struct {
    value string
    timestamp int
}

type TimeMap struct {
    timeMap map[string][]timeMapValue
}


func Constructor() TimeMap {
    return TimeMap{
        timeMap: make(map[string][]timeMapValue),
    } 
}


func (this *TimeMap) Set(key string, value string, timestamp int)  {
    this.timeMap[key] = append(this.timeMap[key], timeMapValue{value, timestamp})
}


func (this *TimeMap) Get(key string, timestamp int) string {
    values := this.timeMap[key] 

    l, r := 0, len(values)-1
    val := ""
    for l <= r {
        mid := (l + r) / 2

        if values[mid].timestamp <= timestamp {
            l = mid + 1
            val = values[mid].value
        } else {
            r = mid - 1
        }
    }

    return val
}


/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */
