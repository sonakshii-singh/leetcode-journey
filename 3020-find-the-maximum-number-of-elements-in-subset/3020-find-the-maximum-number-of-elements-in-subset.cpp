class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 1;

        // Special case: x = 1 (1^2 = 1, so it's its own square)
        if (freq.count(1)) {
            int cnt = freq[1];
            // If odd: use all; if even: use cnt-1 (need odd count for palindrome)
            ans = max(ans, cnt % 2 == 1 ? cnt : cnt - 1);
        }

        for (auto& [x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            // Keep going while we have at least 2 of current value
            while (freq.count(cur) && freq[cur] >= 2) {
                len += 2;
                if (cur > 31622LL) { // cur*cur would exceed 10^9
                    cur = cur * cur; // will exceed map, freq[cur]=0
                    break;
                }
                cur = cur * cur;
            }

            // Try to place one element at the center
            if (freq.count(cur) && freq[cur] >= 1)
                len++;
            else
                len = max(1, len - 1); // remove one pair, use one as center

            ans = max(ans, len);
        }

        return ans;
    }
};