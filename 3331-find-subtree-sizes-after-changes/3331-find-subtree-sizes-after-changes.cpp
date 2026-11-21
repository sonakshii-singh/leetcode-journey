
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        vector<vector<int>> child(n);

        for (int i = 1; i < n; i++) {
            child[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);

        function<void(int)> build = [&](int u) {
            int c = s[u] - 'a';
            int old = last[c];

            last[c] = u;

            for (int v : child[u]) {
                int p = parent[v];
                int x = s[v] - 'a';

                if (last[x] != -1)
                    p = last[x];

                adj[p].push_back(v);
                build(v);
            }

            last[c] = old;
        };

        build(0);

        vector<int> ans(n, 1);

        function<void(int)> dfs = [&](int u) {
            for (int v : adj[u]) {
                dfs(v);
                ans[u] += ans[v];
            }
        };

        dfs(0);
        return ans;
    }
};
