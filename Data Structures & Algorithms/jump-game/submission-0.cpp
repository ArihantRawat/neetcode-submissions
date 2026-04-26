class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        for(int i=0;i<n;i++) {
            if(x>=i) {
                x=max(x,i+nums[i]);
            }
        }
        return x>=n-1;
    }
};
