class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int freq[26] = {};
        
        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";
        
        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';

            // Try to keep target[i] same
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
            }
            else {
                // Find the smallest character greater than target[i]
                int bigger = -1;

                for (int j = x + 1; j < 26; j++) {
                    if (freq[j] > 0) {
                        bigger = j;
                        break;
                    }
                }

                if (bigger != -1) {
                    ans += char('a' + bigger);
                    freq[bigger]--;

                    // Append remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }

                // Cannot continue with target[i],
                // so we need to backtrack.
                break;
            }
        }

        // Backtracking
        for (int i = ans.size() - 1; i >= 0; i--) {
            freq[ans[i] - 'a']++;

            int x = target[i] - 'a';

            for (int j = x + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    string result = target.substr(0, i);
                    result += char('a' + j);
                    freq[j]--;

                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            result += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};