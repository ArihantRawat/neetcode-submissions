class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int len=1;
        int x=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=2;
                x=i;
                len=2;
            }
        }
        for(int i=2;i<n;i++) {
            for(int j=0;j<n-i;j++){
                if(s[j]==s[j+i] && dp[j+1][j+i-1]!=-1) {
                    dp[j][j+i] = dp[j+1][j+i-1] + 2;
                    x=j;
                    len=i+1;
                }
            }
        }
        return s.substr(x,len);
    }
};
