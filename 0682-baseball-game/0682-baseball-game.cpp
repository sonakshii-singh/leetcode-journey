class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;

        for (string op : ops) {
            if (op == "C") {
                st.pop();
            }
            else if (op == "D") {
                st.push(2 * st.top());
            }
            else if (op == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);           // restore
                st.push(a + b);
            }
            else {
                st.push(stoi(op));
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};