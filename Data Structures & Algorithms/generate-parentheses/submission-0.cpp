class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        getData("",n,0);
        return res;
    }

    void getData(string x, int n, int open) {
        if(n==0) {
            res.push_back(x);
        }
        if(open>0) {
            x=x+")";
            getData(x,n-1,open-1);
            x.pop_back();
        }
        if(open<n) {
            x=x+"(";
            getData(x,n,open+1);
            x.pop_back();
        }
        
    }
};
