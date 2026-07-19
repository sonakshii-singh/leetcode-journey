class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int x : asteroids) {
            bool destroyed = false;

            // Collision only when stack top is moving right
            // and current asteroid is moving left
            while (!st.empty() && st.top() > 0 && x < 0) {
                if (st.top() < -x) {
                    st.pop(); // Stack asteroid explodes
                }
                else if (st.top() == -x) {
                    st.pop(); // Both explode
                    destroyed = true;
                    break;
                }
                else {
                    // Current asteroid explodes
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed)
                st.push(x);
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};