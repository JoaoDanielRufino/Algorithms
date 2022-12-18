// https://app.codesignal.com/interview-practice/task/MdHZFgZFERPPagfdD/description

vector<int> solution(vector<int> a) {
    stack<int> st;
    vector<int> ans(a.size(), -1);
    
    for(int i = 0; i < a.size(); i++) {
        while(!st.empty() && a[i] > a[st.top()]) {
            ans[st.top()] = a[i];
            st.pop();
        }
        
        st.push(i);
    }
    
    return ans;
}
