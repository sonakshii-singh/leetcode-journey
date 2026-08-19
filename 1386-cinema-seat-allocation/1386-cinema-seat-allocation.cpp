class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

       
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            mp[row] |= (1 << s);
        }

       
        int ans = (n - mp.size()) * 2;

        for (auto &[row, mask] : mp) {
            bool left  = (mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5))) == 0;
            bool middle = (mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))) == 0;
            bool right = (mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9))) == 0;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};