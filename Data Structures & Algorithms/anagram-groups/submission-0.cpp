class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string,vector<string>>map;
        for(int i=0;i<str.size();i++) {
            string s = str[i];
            sort(str[i].begin(),str[i].end());
            if(map.contains(str[i])) {
                map[str[i]].push_back(s);
            } else {
                vector<string> data;
                data.push_back(s);
                map[str[i]] = data;
            }
        }
        vector<vector<string>> res;
        for (const auto& pair : map) {
            res.push_back(pair.second);
        }
        return res;
    }
};
