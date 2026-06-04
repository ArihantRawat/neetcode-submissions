class Solution {
public:

    vector<vector<int>>res;
    vector<int>cur;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return res;
    }

    void dfs(vector<int>& nums, int idx) {
         res.push_back(cur);
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            cur.push_back(nums[i]);
            dfs(nums, i + 1);
            cur.pop_back();
        }
    }
};
