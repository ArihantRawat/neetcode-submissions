class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for(int i=0;i<s.size();i++) {
            if((s[i]==')' || s[i]==']' || s[i]=='}') && q.empty()) {
                return false;
            }
            else if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
                q.push(s[i]);
            } else if (s[i]=='}' && q.top()=='{') {
                q.pop();
            } else if (s[i]==']' && q.top()=='[') {
                q.pop();
            } else if (s[i]==')' && q.top()=='(') {
                q.pop();
            } else {
                return false;
            }
        }

        return q.size()==0;
    }
};
