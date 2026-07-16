class Solution {
public:
    bool isPalindrome(string s) {
        if (s == " ")
            return true;
        string ans = "";
        for (auto ch : s) {
            if (isalnum(ch)) {
                ch = tolower(ch);
                ans += ch;
            }
        }
        int n = ans.size();
        if (n == 1)
            return true;
        for (int i = 0, j = n-1; i <j; i++, j--) {
            if (ans[i] != ans[j]) {
                return false;
            }
        }
        return true;
    }
};