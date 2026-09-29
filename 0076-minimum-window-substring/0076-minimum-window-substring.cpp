class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;

        int m = t.size();
        int n = s.size();

        for (char c : t)
            need[c]++;

        int r = 0, l = 0;
        int minlen = INT_MAX, cnt = 0, sInd = -1;

        while (r < n) {

            if (need[s[r]] > 0) {
                cnt++;
            }

            need[s[r]]--;

            while (cnt == m) {

                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sInd = l;
                }
                need[s[l]]++;

                if (need[s[l]] > 0)
                    cnt--;

                l++;  
            }
            r++;
        }
        return sInd == -1 ? "" : s.substr(sInd, minlen);
    }
};