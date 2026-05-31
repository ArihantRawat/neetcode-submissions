class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        int n = piles.size();
        for(int i=0;i<n;i++) {
            r=max(r,piles[i]);
        }
        int res = r;
        while(l<=r) {
            int m = (l+r)/2;
            if(check(piles,h,m)) {
                res = min(res,m);
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return res;
    }

    bool check (vector<int>&piles, int h, int x) {
        int rt=0;
        for(int i=0;i<piles.size();i++) {
            rt += ceil((double)piles[i] / x);
        }
        return rt<=h;
    }
};
