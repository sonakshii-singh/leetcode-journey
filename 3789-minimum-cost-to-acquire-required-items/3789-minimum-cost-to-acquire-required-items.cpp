
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long ans = 0;

        if (costBoth >= cost1 + cost2) {
            ans = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        }
        else {
            long long common = min(need1, need2);

            ans = common * costBoth;

            if (need1 > need2) {
                ans += (need1 - need2) * 1LL * min(cost1, costBoth);
            }
            else {
                ans += (need2 - need1) * 1LL * min(cost2, costBoth);
            }
        }

        return ans;
    }
};
