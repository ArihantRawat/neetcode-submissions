class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> store;
        for(int i = 0; i< nums.size();i++) {
            if(store.contains(nums[i])){
                return true;
            }
            store.insert(nums[i]);
        }
        return false;
    }
};