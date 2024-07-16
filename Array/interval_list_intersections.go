// https://leetcode.com/problems/interval-list-intersections/description/

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}

func intervalIntersection(firstList [][]int, secondList [][]int) [][]int {
    ans := [][]int{}
    first, second := 0, 0
    
    for first < len(firstList) && second < len(secondList) {
        firstX, firstY := firstList[first][0], firstList[first][1]
        secondX, secondY := secondList[second][0], secondList[second][1]
        
        if secondX >= firstX && secondX <= firstY {
            ans = append(ans, []int{secondX, min(firstY, secondY)}) 
        } else if firstX >= secondX && firstX <= secondY {
            ans = append(ans, []int{firstX, min(firstY, secondY)})
        }
        
        if firstY > secondY {
            second++
        } else {
            first++
        }
    }
    
    return ans
}

// or
func max(a, b int) int {
    if a < b {
        return b
    }

    return a
}

func min(a, b int) int {
    if a < b {
        return a
    }
    
    return b
}

func intervalIntersection(firstList [][]int, secondList [][]int) [][]int {
    ans := [][]int{}
    first, second := 0, 0
    
    for first < len(firstList) && second < len(secondList) {
        firstX, firstY := firstList[first][0], firstList[first][1]
        secondX, secondY := secondList[second][0], secondList[second][1]
        
        if firstX <= secondY && secondX <= firstY {
            ans = append(ans, []int{max(firstX, secondX), min(firstY, secondY)})
        }
        
        if firstY > secondY {
            second++
        } else {
            first++
        }
    }
    
    return ans
}
