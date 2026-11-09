class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> freeS;
        for (int i = 0; i < k; i++) freeS.insert(i);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;
        vector<int> cnt(k, 0);

        for (int i = 0; i < (int)arrival.size(); i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                freeS.insert(busy.top().second);
                busy.pop();
            }
            if (freeS.empty()) continue;
            auto it = freeS.lower_bound(i % k);
            if (it == freeS.end()) it = freeS.begin();
            int id = *it;
            freeS.erase(it);
            cnt[id]++;
            busy.push({(long long)arrival[i] + load[i], id});
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) if (cnt[i] == mx) ans.push_back(i);
        return ans;
    }
};