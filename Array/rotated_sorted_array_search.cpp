// https://www.interviewbit.com/problems/rotated-sorted-array-search/
// https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

int binarySearch(const vector<int> &A, int l, int r, int B) {
    if(l > r)
        return -1;
        
    int mid = (l + r) / 2;
    if(A[mid] == B)
        return mid;
        
    if(A[l] <= A[mid]) {
        if(B >= A[l] && B <= A[mid])
            return binarySearch(A, l, mid-1, B);
        return binarySearch(A, mid+1, r, B);
    }
    
    if(B >= A[mid] && B <= A[r])
        return binarySearch(A, mid+1, r, B);
    return binarySearch(A, l, mid-1, B);
}

int Solution::search(const vector<int> &A, int B) {
    return binarySearch(A, 0, A.size()-1, B);
}
