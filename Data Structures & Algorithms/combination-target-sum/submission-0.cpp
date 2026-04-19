class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>x;
        int i=0;
        getResult(nums,target,res,x,i);
        return res;
    }

    void getResult(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>x, int i) {
        if(target==0) {
            res.push_back(x);
            return;
        }
        if(target<0 || i==nums.size()){
            return;
        }
        x.push_back(nums[i]);
        getResult(nums,target-nums[i],res,x,i);
        //getResult(nums,target-nums[i],res,x,i+1);
        x.pop_back();
        getResult(nums,target,res,x,i+1);

    }
};
