// https://app.codesignal.com/interview-practice/task/MdHZFgZFERPPagfdD/description

vector<int> solution(vector<int> a) {
    stack<int> st;
    vector<int> ans(a.size());
    
    for(int i = a.size()-1; i >= 0; i--) {
        while(!st.empty() && st.top() <= a[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(a[i]);
    }
    
    return ans;
}
