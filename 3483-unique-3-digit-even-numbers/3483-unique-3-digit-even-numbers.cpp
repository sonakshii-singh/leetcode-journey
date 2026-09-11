class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int x : digits)
            freq[x]++;

        int ans = 0;

        for (int num = 100; num <= 999; num++) {
            if (num % 2 != 0)
                continue;

            int x = num;
            int a = x % 10;
            x /= 10;

            int b = x % 10;
            x /= 10;

            int c = x % 10;

            freq[a]--;
            freq[b]--;
            freq[c]--;

            if (freq[a] >= 0 && freq[b] >= 0 && freq[c] >= 0)
                ans++;

            freq[a]++;
            freq[b]++;
            freq[c]++;
        }

        return ans;
    }
};