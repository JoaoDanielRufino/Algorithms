// https://leetcode.com/problems/single-number/

int Solution::singleNumber(const vector<int> &A) {
    int x = 0;
    
    for(int i = 0; i < A.size(); i++) {
        x ^= A[i];
    }
    
    return x;
}
