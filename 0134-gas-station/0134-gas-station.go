func canCompleteCircuit(gas []int, cost []int) int {
    totalGas, totalCost, currentGas, startIndex := 0, 0, 0, 0

    for i := 0; i < len(gas); i++ {
        totalGas += gas[i]
        totalCost += cost[i]
        currentGas += gas[i] - cost[i]

        if currentGas < 0 {
            startIndex = i + 1
            currentGas = 0
        }
    }

    if totalGas >= totalCost {
        return startIndex
    }
    return -1
}
