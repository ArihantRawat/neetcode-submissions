class Solution {
public:
    unordered_map<char, vector<char>> mp = {
             {'2', {'a', 'b', 'c'}},
             {'3', {'d', 'e', 'f'}},
             {'4', {'g', 'h', 'i'}},
             {'5', {'j', 'k', 'l'}},
             {'6', {'m', 'n', 'o'}},
             {'7', {'p', 'q', 'r', 's'}},
             {'8', {'t', 'u', 'v'}},
             {'9', {'w', 'x', 'y', 'z'}},
    };
    vector<string>res;
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) {
            return res;
        }
        getAns(digits,0,"");
        return res;
    }

    void getAns(string digits, int x, string s){
        if(x==digits.size()) {
            res.push_back(s);
            return;
        }
        vector<char> ch = mp[digits[x]];
        for(int i=0;i<ch.size();i++) {
            getAns(digits,x+1,s+ch[i]);   
        }
    }
};
