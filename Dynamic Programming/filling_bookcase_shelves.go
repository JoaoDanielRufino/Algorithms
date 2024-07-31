// https://leetcode.com/problems/filling-bookcase-shelves/description

func min(a, b int) int {
    if a < b {
        return a
    }

    return b
}

func max(a, b int) int {
    if a < b {
        return b
    }

    return a
}

func solve(books [][]int, shelfWidth, currWidth, height, pos int, dp map[string]int) int {
    if pos >= len(books) {
        return height
    }

    key := fmt.Sprintf("%d_%d", currWidth, pos)

    if val, ok := dp[key]; ok {
        return val
    }

    if currWidth + books[pos][0] <= shelfWidth {
        dp[key] = min(
            solve(books, shelfWidth, currWidth + books[pos][0], max(height, books[pos][1]), pos+1, dp), 
            height + solve(books, shelfWidth, books[pos][0], books[pos][1], pos+1, dp),
        )

        return dp[key]
    }

    dp[key] = height + solve(books, shelfWidth, books[pos][0], books[pos][1], pos+1, dp)

    return dp[key]
}

func minHeightShelves(books [][]int, shelfWidth int) int {
    dp := map[string]int{}

    return solve(books, shelfWidth, 0, 0, 0, dp)
}
