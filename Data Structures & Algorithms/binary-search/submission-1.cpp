class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int x=0;
        while(x<=n) {
            int m = x + ((n - x) / 2);
            if(nums[m]==target) {
                return m;
            } else if (nums[m]>target) {
                n=m-1;
            } else {
                x=m+1;
            }
        }
        return -1;
    }
};
