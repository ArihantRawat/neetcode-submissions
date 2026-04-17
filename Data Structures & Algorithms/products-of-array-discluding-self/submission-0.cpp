class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> back(n);
        back[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            back[i] = back[i+1]*nums[i];
        }
        int front=1;
        vector<int> res;
        for(int i=0;i<n-1;i++){
            res.push_back(front*back[i+1]);
            front=front*nums[i];
        }
        res.push_back(front);
        return res;
    }
};
