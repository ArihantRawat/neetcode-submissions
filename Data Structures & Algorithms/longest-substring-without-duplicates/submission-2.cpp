class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[256] ={0};
        int x=0;
        int res = 0;
        int c=0;
        for(int i=0;i<s.length();i++) {
            arr[int(s[i])]++;
            c++;
            while(arr[int(s[i])]>1) {
                c--;
                arr[int(s[x])]--;
                x++;
            }
            
            res=max(res,c);
        }
        return res;
    }
};
