class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        int arr[n];
        arr[0]=1;
        arr[1]=2;
        for(int i=2;i<n;i++){
            arr[i]=arr[i-2]+arr[i-1];
        }
        return arr[n-1];
    }
};
