class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int res = 0;
        for(int i=0;i<nums.size();i++) {
            set.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++) {
            if(!set.contains(nums[i]+1)) {
                int c = 1;
                int x = nums[i];
                while(set.contains(x-1)) {
                    c++;
                    x--;
                }
                res= max(res,c);
            }
        }
        return res;
    }
};
