// https://leetcode.com/problems/generate-parentheses/description

func solve(n, opened, closed int, curr string, ans *[]string) {
    if opened == n && closed == n {
        *ans = append(*ans, strings.Clone(curr))
        return
    }

    if opened == n {
        solve(n, opened, closed+1, curr + ")", ans)
        return
    }

    if opened > closed {
        solve(n, opened+1, closed, curr + "(", ans)
        solve(n, opened, closed+1, curr + ")", ans)
    }

    if opened == closed {
        solve(n, opened+1, closed, curr + "(", ans)
    }
}

func generateParenthesis(n int) []string {
    ans := []string{}

    solve(n, 0, 0, "", &ans)

    return ans
}
