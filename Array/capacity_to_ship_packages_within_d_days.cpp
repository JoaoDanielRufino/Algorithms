// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
public:
    bool OK(vector<int>& weigths, int days, int cap) {
        int count = 1, curr = 0;

        for(int w : weigths) {
            curr += w;
            if(curr > cap) {
                count++;
                curr = w;
            }
        }

        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;

        for(int w : weights) {
            l = max(l, w);
            r += w;
        }

        int ans;
        while(l <= r) {
            int mid = l + (r - l)/2;

            if(OK(weights, days, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
