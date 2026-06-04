class Solution {
public:
    vector<vector<string>> res;
    vector<string> cur;

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }

    void dfs(string& s, int start) {

        if (start == s.size()) {
            res.push_back(cur);
            return;
        }

        for (int end = start; end < s.size(); end++) {

            if (isPalindrome(s, start, end)) {

                cur.push_back(s.substr(start, end - start + 1));

                dfs(s, end + 1);

                cur.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {

        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};