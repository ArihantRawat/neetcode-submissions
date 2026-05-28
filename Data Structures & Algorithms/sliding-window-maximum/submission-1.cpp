class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int>res;
        int i=0;
        for(;i<k;i++) {
            pq.push({nums[i],i});
        }
        res.push_back(pq.top().first);        

        while(i<nums.size()) {
            while(!pq.empty() && pq.top().second<=i-k) {
                pq.pop();
            }
            pq.push({nums[i],i});
            res.push_back(pq.top().first);
            i++;
        }

        return res;
    }
};
