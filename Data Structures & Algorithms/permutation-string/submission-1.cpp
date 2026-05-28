class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()){
            return false;
        }
        int arr[27] = {0};
        int n=s1.size();
        for(int i=0;i<n;i++) {
            arr[s1[i]-'a']++;
            arr[s2[i]-'a']--;
        }

        if(check(arr)) {
            return true;
        }
        int x=0;
        for(int i=n;i<s2.size();i++) {
            arr[s2[i]-'a']--;
            arr[s2[x++]-'a']++;
            if(check(arr)) {
                return true;
            }
        }

        return false;
    }


    bool check(int arr[]) {
        for(int i=0;i<27;i++){
            if(arr[i]>0) {
                return false;
            }
        }
        return true;
    }
};
