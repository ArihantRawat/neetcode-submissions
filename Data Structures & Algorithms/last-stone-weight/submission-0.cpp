class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>x;
        for(int i=0;i<stones.size();i++) {
            x.push(stones[i]);
        }
        while(x.size()>1) {
            int f1 = x.top();
            x.pop();
            int f2 = x.top();
            x.pop();
            if(f1!=f2) {
                x.push(abs(f1-f2));
            }
        }
        return x.empty() ? 0 : x.top();
    }
};
