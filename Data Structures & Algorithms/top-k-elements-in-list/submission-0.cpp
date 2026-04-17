class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (int i=0;i<nums.size();i++) {
            map[nums[i]]++;
        }
        vector<pair<int,int>> data;
        for (auto x : map) {
            data.push_back(make_pair(x.second,x.first));
        }
        sort(data.begin(), data.end());
        vector<int>res;
        int n = data.size()-1;
        for (int i=0;i<k;i++) {
            res.push_back(data[n-i].second);
        }
        return res;
    }
};
