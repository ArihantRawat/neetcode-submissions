class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n == 0) return 0;
        vector<int> arr(n, 0);
        arr[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            arr[i]=max(arr[i+1],prices[i]);
        }
        int res=0;
        for(int i=0;i<n-1;i++){
            res=max(res,arr[i+1]-prices[i]);
        }
        return res;
    }
};
