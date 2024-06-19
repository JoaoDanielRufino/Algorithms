// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description

func countBouquets(bloomDay []int, k, maxBloomDay int) int {
    count, bouquets := 0, 0

    for _, day := range bloomDay {
        if day <= maxBloomDay {
            count++
        } else {
            count = 0
        }

        if count == k {
            bouquets++
            count = 0
        }
    }

    return bouquets
}

func minDays(bloomDay []int, m int, k int) int {
    if m * k > len(bloomDay) {
        return -1
    }

    l, r, minBouquets := slices.Min(bloomDay), slices.Max(bloomDay), -1

    for l <= r {
        mid := (l + r) / 2

        bouquets := countBouquets(bloomDay, k, mid)

        if bouquets < m {
            l = mid + 1
        } else {
            minBouquets = mid
            r = mid - 1
        }
    }

    return minBouquets
}
