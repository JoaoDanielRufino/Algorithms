// https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/

int Solution::kthsmallest(const vector<int> &A, int B) {
    int l = *min_element(A.begin(), A.end());
    int r = *max_element(A.begin(), A.end());
    int mid;
    
    while(l <= r) {
        mid = (l + r) / 2;
        
        int less = 0, equal = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] == mid)
                equal++;
            else if(A[i] < mid)
                less++;
            if(less >= B)
                break;
        }
        
        if(less < B && less + equal >= B)
            return mid;
        if(less >= B)
            r = mid-1;
        else
            l = mid+1;
    }
}
