class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> runChar, runStart, runEnd, runLen;
        vector<int> posToRun(n);
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            int idx = runChar.size();
            runChar.push_back(s[i] - '0');
            runStart.push_back(i);
            runEnd.push_back(j - 1);
            runLen.push_back(j - i);
            for (int k = i; k < j; k++) posToRun[k] = idx;
            i = j;
        }
        int m = runChar.size();
        long long totalOnes = count(s.begin(), s.end(), '1');

        vector<long long> gainVal(m, LLONG_MIN);
        for (int idx = 1; idx < m - 1; idx++)
            if (runChar[idx] == 1)
                gainVal[idx] = (long long)runLen[idx - 1] + runLen[idx + 1];

        int LOG = 1;
        while ((1 << LOG) < max(m, 2)) LOG++;
        vector<vector<long long>> sp(LOG + 1, vector<long long>(m, LLONG_MIN));
        if (m > 0) {
            for (int idx = 0; idx < m; idx++) sp[0][idx] = gainVal[idx];
            for (int k = 1; k <= LOG; k++)
                for (int idx = 0; idx + (1 << k) <= m; idx++)
                    sp[k][idx] = max(sp[k-1][idx], sp[k-1][idx + (1 << (k-1))]);
        }
        auto rangeMax = [&](int l, int r) -> long long {
            if (l > r) return LLONG_MIN;
            int k = 31 - __builtin_clz(r - l + 1);
            return max(sp[k][l], sp[k][r - (1 << k) + 1]);
        };

        int Q = queries.size();
        vector<int> ans(Q);
        for (int qi = 0; qi < Q; qi++) {
            int l = queries[qi][0], r = queries[qi][1];
            int p = posToRun[l], q = posToRun[r];
            long long gain = 0;
            if (p != q) {
                int lenA = runEnd[p] - l + 1;
                int lenB = r - runStart[q] + 1;
                long long candidates = 0;
                if (q >= p + 2) {
                    if (runChar[p+1] == 1) {
                        long long rightNb = (p+2 <= q-1) ? (long long)runLen[p+2] : (long long)lenB;
                        candidates = max(candidates, (long long)lenA + rightNb);
                    }
                    if (q-1 != p+1 && runChar[q-1] == 1) {
                        long long leftNb = (q-2 >= p+1) ? (long long)runLen[q-2] : (long long)lenA;
                        candidates = max(candidates, leftNb + (long long)lenB);
                    }
                    if (p+2 <= q-2) {
                        long long rm = rangeMax(p+2, q-2);
                        if (rm > LLONG_MIN/2) candidates = max(candidates, rm);
                    }
                }
                gain = candidates;
            }
            ans[qi] = (int)(totalOnes + gain);
        }
        return ans;
    }
};