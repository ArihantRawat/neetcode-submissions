class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>res;
        res.push_back(0);
        stack<pair<int,int>>s;
        int n=temperatures.size();
        s.push({temperatures[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            while(!s.empty()&&temperatures[i]>=s.top().first) {
                s.pop();
            }
            if(s.empty()){
                res.push_back(0);
            } else {
                res.push_back(s.top().second-i);
            }
            s.push({temperatures[i],i});
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
