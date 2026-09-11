class Solution {
public:
    int numberOfSpecialChars(string s) {
        int cnt=0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (s.find(ch) != string::npos &&
                s.find(toupper(ch)) != string::npos) {
                cnt++;
            }
        }
        return cnt;
    }
};