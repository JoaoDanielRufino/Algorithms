// https://www.interviewbit.com/problems/rotated-array/
// https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

int findPivot(const vector<int> &A, int l, int r) {
    if(r < l)
        return 0;
    
    if(r == l)
        return r;
        
    int mid = (r + l) / 2;
    if(mid < r && A[mid] > A[mid+1])
        return mid+1;
        
    if(mid > l && A[mid] < A[mid-1])
        return mid;
        
    if(A[r] >= A[mid])
        return findPivot(A, l, mid-1);
    return findPivot(A, mid+1, r);
}

int Solution::findMin(const vector<int> &A) {
    int pos = findPivot(A, 0, A.size()-1);
    
    return A[pos];
}
