class Solution {
public:
    string minWindow(string s, string t) {
        int arr1[256] = {0};
        int arr2[256] = {0};
        for(int i=0;i<t.size();i++) {
            arr1[int(t[i])]++;
        }
        int arr3[256] = {0};
        for(int i=0;i<s.size();i++) {
            arr3[int(s[i])]++;
        }
        if (!isMatched(arr1,arr3,0)) {
            return "";
        }
        int x=0;
        string res = s;
        for(int i=0;i<s.size();i++) {
            arr2[int(s[i])]++;
            while(isMatched(arr1,arr2, 0)) {
                string str = s.substr(x,i-x+1);
                if(str.length() < res.length()) {
                    res = str;
                }
                arr2[int(s[x])]--;
                x++;
            }
            
        }
        return res;
    }

    bool isMatched(int arr1[], int arr2[], int x) {
        if(x==256) {
            return true;
        }
        return arr1[x] <= arr2[x] && isMatched(arr1,arr2,x+1);
    }
};
