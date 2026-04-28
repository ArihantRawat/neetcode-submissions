class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int i=0;
        while(i<n) {
            int st = intervals[i][0];
            int end = intervals[i][1];
            i++;
            while(i<n) {
                if (end>=intervals[i][0]) {
                    end=max(end,intervals[i][1]);
                    i++;
                } else{
                    break;
                }
            }
            res.push_back({st,end});
        }
        return res;
    }
};
