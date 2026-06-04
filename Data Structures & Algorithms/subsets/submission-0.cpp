class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>s;
        getAns(nums,0,res,s);
        return res;
    }
    void getAns(vector<int>& nums, int x, vector<vector<int>>&res, vector<int>s) {
        if(x==nums.size()) {
            res.push_back(s);
            return;
        }
        getAns(nums,x+1,res,s);
        s.push_back(nums[x]);
        getAns(nums,x+1,res,s);
    }
};
