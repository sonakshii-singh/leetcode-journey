class Solution {
public:
    bool isPalindromic(string s) {
        vector<int>bin;
        for(int i=0; i<s.size(); i++){
            bitset<8>b(s[i]);
            for(int j=7;j>=0; j--)
            bin.push_back(b[j]);
        }
        for(int i=0; i<bin.size()/2;i++){
            if(bin[i]!=bin[bin.size()-i-1])
                return false;
        }
        return true;
    }
};