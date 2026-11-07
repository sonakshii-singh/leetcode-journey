class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        using T = tuple<long long,int,int>; // endTime, weight, index
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> available;
        priority_queue<T, vector<T>, greater<>> busy;
        for (int i = 0; i < n; i++) available.push({servers[i], i});

        vector<int> ans(m);
        long long time = 0;
        for (int i = 0; i < m; i++) {
            time = max(time, (long long)i);
            if (available.empty())
                time = max(time, get<0>(busy.top()));
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [e, w, idx] = busy.top(); busy.pop();
                available.push({w, idx});
            }
            auto [w, idx] = available.top(); available.pop();
            ans[i] = idx;
            busy.push({time + tasks[i], w, idx});
        }
        return ans;
    }
};