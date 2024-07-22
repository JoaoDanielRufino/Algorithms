// https://leetcode.com/problems/multiply-strings/description/

func multiply(num1 string, num2 string) string {
    if num1 == "0" || num2 == "0" {
        return "0"
    }
    
    ans := make([]byte, len(num1) + len(num2))
    
    for i := len(num1)-1; i >= 0; i-- {
        for j := len(num2)-1; j >= 0; j-- {
            n1 := num1[i] - '0'
            n2 := num2[j] - '0'
            ans[i+j+1] += n1 * n2
            
            if ans[i+j+1] >= 10 {
                ans[i+j] += ans[i+j+1] / 10
                ans[i+j+1] %= 10
            }
        }
    }
    
    if ans[0] == 0 {
        ans = ans[1:]
    }
    
    for i := range ans {
        ans[i] += '0'
    }
    
    return string(ans)
}
