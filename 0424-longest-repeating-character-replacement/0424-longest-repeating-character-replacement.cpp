class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf=0, maxlen=0;
        vector<int> freq(26, 0);
        int r=0, l=0;
        while(r<s.size()){
            freq[s[r]-'A']++;
            maxf=max(maxf,freq[s[r]-'A']);
            if(r-l+1 - maxf >k){
                freq[s[l]-'A']--;
                l++;
            }
            
                maxlen=max(maxlen,r-l+1);
            
            r++;

        }
        return maxlen;
    }
};