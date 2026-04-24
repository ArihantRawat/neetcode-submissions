class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> state(26, 0); // 0=unvisited, 1=visiting, 2=visited
        vector<bool> present(26, false);
        string result;

        // mark present characters
        for (auto &w : words) {
            for (char c : w) {
                present[c - 'a'] = true;
            }
        }

        // build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string &w1 = words[i];
            string &w2 = words[i + 1];

            int p = min(w1.size(), w2.size());

            // invalid prefix case
            if (w1.size() > w2.size() && w1.substr(0, p) == w2.substr(0, p)) {
                return "";
            }

            for (int j = 0; j < p; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    break;
                }
            }
        }

        // DFS on all present characters
        for (int i = 0; i < 26; i++) {
            if (present[i] && state[i] == 0) {
                if (dfs(i, adj, state, result)) {
                    return "";
                }
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state, string& res) {
        if (state[node] == 1) return true;  // cycle
        if (state[node] == 2) return false; // already done

        state[node] = 1;

        for (int nei : adj[node]) {
            if (dfs(nei, adj, state, res)) return true;
        }

        state[node] = 2;
        res.push_back(node + 'a');
        return false;
    }
};