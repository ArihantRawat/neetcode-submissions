class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        int res = INT_MIN;
        for(int i=1;i<=n;i++){
            x=max(nums[i-1],x+nums[i-1]);
            res = max(res,x);
        }
        return res;
    }
};
