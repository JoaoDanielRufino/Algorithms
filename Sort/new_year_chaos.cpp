void minimumBribes(vector<int> q) {
    unordered_map<int, int> mp;
    int count = 0;
    bool flag;
    
    for(int i = q.size()-1; i > 0; i--) {
        flag = false;
        for(int j = 0; j < i; j++) {
            if(q[j] > q[j+1]) {
                int tmp = q[j];
                q[j] = q[j+1];
                q[j+1] = tmp;
                mp[tmp]++;
                count++;
                if(mp[tmp] > 2) {
                    cout << "Too chaotic" << endl;
                    return;
                }
                flag = true;
            }
        }
        if(!flag)
            break;
    }
    
    cout << count << endl;
}
