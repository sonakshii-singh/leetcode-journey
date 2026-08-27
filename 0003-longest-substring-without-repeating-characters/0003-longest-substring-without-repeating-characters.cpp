class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int hashLen=256;
        int maxLen=0;
        int hash[hashLen];
        int l=0, r=0;
        for(int i=0; i<hashLen; ++i){
            hash[i]=-1;
        }
        while(r<s.size()){
            if(hash[s[r]]!=-1){
                l=max(l,hash[s[r]]+1);
            }
            int len=r-l+1;
            maxLen=max(len,maxLen);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};