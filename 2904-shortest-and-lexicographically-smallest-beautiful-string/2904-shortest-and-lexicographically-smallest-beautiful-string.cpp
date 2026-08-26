class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> pos;

       
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                pos.push_back(i);
        }

      
        if (pos.size() < k)
            return "";

        string ans = "";

        for (int i = 0; i + k - 1 < pos.size(); i++) {
            int first = pos[i];
            int last = pos[i + k - 1];

           
            string cur = s.substr(first, last - first + 1);

            if (ans == "" ||
                cur.size() < ans.size() ||
                (cur.size() == ans.size() && cur < ans)) {
                ans = cur;
            }
        }

        return ans;
    }
};