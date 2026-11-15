
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;

        long long even = 1, odd = 0;
        long long sum = 0, ans = 0;

        for (int x : arr) {
            sum += x;

            if (sum % 2 == 1) {
                ans = (ans + even) % mod;
                odd++;
            }
            else {
                ans = (ans + odd) % mod;
                even++;
            }
        }

        return ans;
    }
};
