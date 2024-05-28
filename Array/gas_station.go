func canCompleteCircuit(gas []int, cost []int) int {
    currGas, totalGas, totalCost, ans := 0, 0, 0, 0

    for i := 0; i < len(gas); i++ {
        totalGas += gas[i]
        totalCost += cost[i]
        currGas += (gas[i] - cost[i])
        if currGas < 0 {
            currGas = 0
            ans = i + 1
        }
    }

    if totalCost > totalGas {
        return -1
    }

    return ans
}
