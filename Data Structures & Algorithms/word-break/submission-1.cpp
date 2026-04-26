class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[n]=true;
        unordered_set<string> st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        string x="";
        for(int i=n-1;i>=0;i--) {
            for (const auto& w : wordDict) {
                if ((i + w.size()) <= s.size() &&
                     s.substr(i, w.size()) == w) {
                    dp[i] = dp[i + w.size()];
                }
                if (dp[i]) {
                    break;
                }
            }
        }
        return dp[0];
    }
};
